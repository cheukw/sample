#include <cassert>
#include "net/tcp_client.h"
#include "net/libevent_headers.h"
#include "net/tcp_conn.h"
#include "net/fd_channel.h"
#include "net/connector.h"

TCPClient::TCPClient(EventLoop* l, const std::string& raddr, const std::string& n)
    : loop_(l)
    , remote_addr_(raddr)
    , name_(n)
    , auto_reconnect_(true)
    , reconnect_interval_(3.0)
    , connecting_timeout_(3.0)
    , conn_fn_(&internal::DefaultConnectionCallback)
    , msg_fn_(&internal::DefaultMessageCallback) 
{
}

TCPClient::~TCPClient()
{
    assert(!connector_.get());
    auto_reconnect_.store(false);
    TCPConnPtr c = conn();
    if (c) {
        // Most of the cases, the conn_ is at disconnected status at this time.
        // But some times, the user application layer will call TCPClient::Close()
        // and delete TCPClient object immediately, that will make conn_ to be at disconnecting status.
        assert(c->IsDisconnected() || c->IsDisconnecting());
        if (c->IsDisconnecting()) {
            // the reference count includes :
            //  - this
            //  - c
            //  - A disconnecting callback which hold a shared_ptr of TCPConn
            assert(c.use_count() >= 3);
            c->SetCloseCallback(CloseCallback());
        }
    }
    conn_.reset();
}

void TCPClient::Connect() 
{
    auto f = [this]() {
        assert(loop_->IsInLoopThread());
        connector_.reset(new Connector(loop_, this));
        connector_->SetNewConnectionCallback(std::bind(&TCPClient::OnConnection, this, std::placeholders::_1, std::placeholders::_2));
        connector_->Start();
    };
    loop_->RunInLoop(f);
}

void TCPClient::Disconnect() 
{
    loop_->RunInLoop(std::bind(&TCPClient::DisconnectInLoop, this));
}

void TCPClient::SetConnectionCallback(const ConnectionCallback& cb) 
{
    conn_fn_ = cb;
    auto  c = conn();
    if (c) {
        c->SetConnectionCallback(cb);
    }
}

void TCPClient::DisconnectInLoop() 
{
    assert(loop_->IsInLoopThread());
    auto_reconnect_.store(false);

    if (conn_) {
        assert(!conn_->IsDisconnected() && !conn_->IsDisconnecting());
        conn_->Close();
    } else {
        // When connector_ is connecting to the remote server ...
        assert(connector_ && !connector_->IsConnected());
    }

    if (connector_->IsConnected() || connector_->IsDisconnected()) {
        
    } else {
        // When connector_ is trying to connect to the remote server we should cancel it to release the resources.
        connector_->Cancel();
    }

    connector_.reset(); // Free connector_ in loop thread immediately
}

void TCPClient::Reconnect() {
    
    Connect();
}

void TCPClient::OnConnection(net_socket_t sockfd, const std::string& laddr) {
    if (sockfd < 0) {
        // We need to notify this failure event to the user layer
        // Note: When we could not connect to a server,
        //       the user layer will receive this notification constantly
        //       because the connector_ will retry to do reconnection all the time.
        conn_fn_(TCPConnPtr(new TCPConn(loop_, "", sockfd, "", "")));
        return;
    }

    
    assert(loop_->IsInLoopThread());
    TCPConnPtr c = TCPConnPtr(new TCPConn(loop_, name_, sockfd, laddr, remote_addr_));
    c->set_type(TCPConn::kOutgoing);
    c->SetMessageCallback(msg_fn_);
    c->SetConnectionCallback(conn_fn_);
    c->SetCloseCallback(std::bind(&TCPClient::OnRemoveConnection, this, std::placeholders::_1));

    {
        std::lock_guard<std::mutex> guard(mutex_);
        conn_ = c;
    }

    c->OnAttachedToLoop();
}

void TCPClient::OnRemoveConnection(const TCPConnPtr& c) {
    assert(c.get() == conn_.get());
    assert(loop_->IsInLoopThread());
    conn_.reset();
    if (auto_reconnect_.load()) {
        Reconnect();
    }
}

TCPConnPtr TCPClient::conn() const {
    if (loop_->IsInLoopThread()) {
        return conn_;
    } else {
        // If it is not in the loop thread, we should add a lock here
        std::lock_guard<std::mutex> guard(mutex_);
        TCPConnPtr c = conn_;
        return c;
    }
}

