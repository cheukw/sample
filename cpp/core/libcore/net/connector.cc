#include "net/connector.h"
#include "net/event_loop.h"
#include "net/fd_channel.h"
#include "net/sockets.h"
#include "net/libevent_headers.h"
#include "net/dns_resolver.h"
#include "net/tcp_client.h"

Connector::Connector(EventLoop* l, TCPClient* client)
    : status_(kDisconnected)
    , loop_(l)
    , owner_tcp_client_(client)
    , remote_addr_(client->remote_addr())
    , timeout_(client->connecting_timeout())
    , fd_(INVALID_SOCKET)
    , own_fd_(false) 
{
    sockets::ParseFromIPPort(remote_addr_.data(), &raddr_);
}

Connector::~Connector() {
    assert(loop_->IsInLoopThread());
   
    if (status_ == kDNSResolving) {
        assert(!chan_.get());
        assert(!dns_resolver_.get());
        assert(!timer_.get());
    } else if (!IsConnected()) {
        // A connected tcp-connection's sockfd has been transfered to TCPConn.
        // But the sockfd of unconnected tcp-connections need to be closed by myself.
        assert(own_fd_);
        assert(chan_->fd() == fd_);
        CLOSESOCKET(fd_);
        fd_ = INVALID_SOCKET;
    }

    assert(fd_ < 0);
    chan_.reset();
}

void Connector::Start() {
    assert(loop_->IsInLoopThread());

    timer_.reset(new TimerEventWatcher(loop_, std::bind(&Connector::OnConnectTimeout, shared_from_this()), timeout_));
    timer_->Init();
    timer_->AsyncWait();

    if (raddr_.sin_addr.s_addr != 0) {
        Connect();
        return;
    }

    status_ = kDNSResolving;
    auto index = remote_addr_.rfind(':');
    assert(index != std::string::npos);
    auto host = std::string(remote_addr_.data(), index);
    auto f = std::bind(&Connector::OnDNSResolved, shared_from_this(), std::placeholders::_1);
    dns_resolver_ = std::make_shared<DNSResolver>(loop_, host, timeout_, f);
    dns_resolver_->Start();
}


void Connector::Cancel() {
    assert(loop_->IsInLoopThread());
    if (dns_resolver_) {
        dns_resolver_->Cancel();
        dns_resolver_.reset();
    }

    assert(timer_);
    timer_->Cancel();
    timer_.reset();

    if (status_ == kDNSResolving) {
        assert(chan_.get() == NULL);
        conn_fn_(-1, "");
    }

    if (chan_.get()) {
        assert(status_ != kDNSResolving);
        chan_->DisableAllEvent();
        chan_->Close();
    }
}

void Connector::Connect() {
    assert(fd_ == INVALID_SOCKET);
    fd_ = sockets::CreateNonblockingSocket();
    own_fd_ = true;
    assert(fd_ >= 0);
    int rc = ::connect(fd_, sockets::sockaddr_cast(&raddr_), sizeof(raddr_));
    if (rc != 0) {
        int serrno = errno;
        if (!EVUTIL_ERR_CONNECT_RETRIABLE(serrno)) {
            HandleError();
            return;
        }
    }

    status_ = kConnecting;

    chan_.reset(new FdChannel(loop_, fd_, false, true));
    
    chan_->SetWriteCallback(std::bind(&Connector::HandleWrite, shared_from_this()));
    chan_->AttachToLoop();
}

void Connector::HandleWrite() {
    if (status_ == kDisconnected) {
        // The connecting may be timeout, but the write event handler has been
        // dispatched in the EventLoop pending task queue, and next loop time the handle is invoked.
        // So we need to check the status whether it is at a kDisconnected
        
        return;
    }

    assert(status_ == kConnecting);
    int err = 0;
    socklen_t len = sizeof(len);
    if (getsockopt(chan_->fd(), SOL_SOCKET, SO_ERROR, (char*)&err, (socklen_t*)&len) != 0) {
               
    }

    if (err != 0) {
        EVUTIL_SET_SOCKET_ERROR(err);
        HandleError();
        return;
    }

    assert(fd_ == chan_->fd());
	struct sockaddr_in addr;
	sockets::GetLocalAddr(chan_->fd(), &addr);
	std::string laddr;
	sockets::ToIPPort(&addr, laddr);
    conn_fn_(chan_->fd(), laddr);
    timer_->Cancel();
    timer_.reset();
    chan_->DisableAllEvent();
    chan_->Close();
    own_fd_ = false; // Move the ownership of the fd to TCPConn
    fd_ = INVALID_SOCKET;
    status_ = kConnected;
}

void Connector::HandleError() {
    assert(loop_->IsInLoopThread());
    int serrno = errno;

    // In this error handling method, we will invoke 'conn_fn_' callback function
    // to notify the user application layer in which the user maybe call TCPClient::Disconnect.
    // TCPClient::Disconnect may cause this Connector object desctruct.
    auto self = shared_from_this();
    status_ = kDisconnected;

    if (chan_) {
        assert(fd_ > 0);
        chan_->DisableAllEvent();
        chan_->Close();
    }

    timer_->Cancel();
    timer_.reset();

    if (EVUTIL_ERR_CONNECT_REFUSED(serrno)) {
        conn_fn_(-1, "");
    }

    // Although TCPClient has a Reconnect() method to deal with automatically reconnection problem,
    // TCPClient's Reconnect() will be invoked when a established connection is broken down.
    //
    // But if we could not connect to the remote server at the very beginning,
    // the TCPClient's Reconnect() will never be triggled.
    // So Connector needs to do reconnection automatically itself.
    if (owner_tcp_client_->auto_reconnect()) {

        // We must close(fd) firstly and then we can do the reconnection.
        if (fd_ > 0) {
            assert(own_fd_);
            EVUTIL_CLOSESOCKET(fd_);
            fd_ = INVALID_SOCKET;
        }
		loop_->RunAfter(owner_tcp_client_->reconnect_interval(), std::bind(&Connector::Start, shared_from_this()));
    }
}

void Connector::OnConnectTimeout() {
    assert(status_ == kConnecting || status_ == kDNSResolving);
    EVUTIL_SET_SOCKET_ERROR(ETIMEDOUT);
    HandleError();
}

void Connector::OnDNSResolved(const std::vector <struct in_addr>& addrs) {
    if (addrs.empty()) {
        HandleError();
        return;
    }

    raddr_.sin_addr = addrs[0]; // TODO random index ?
    status_ = kDNSResolved;
    Connect();
}

std::string Connector::StatusToString() const {
    H_CASE_STRING_BIGIN(status_);
    H_CASE_STRING(kDisconnected);
    H_CASE_STRING(kDNSResolving);
    H_CASE_STRING(kDNSResolved);
    H_CASE_STRING(kConnecting);
    H_CASE_STRING(kConnected);
    H_CASE_STRING_END();
}
