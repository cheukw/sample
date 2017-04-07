#include "net/inner_pre.h"

#include "net/listener.h"
#include "net/event_loop.h"
#include "net/fd_channel.h"
#include "net/libevent_headers.h"
#include "net/sockets.h"


Listener::Listener(EventLoop* l, const std::string& addr)
    : fd_(INVALID_SOCKET)
	, loop_(l)
	, listening_(false)
	, addr_(addr) 
{}

Listener::~Listener(){
    chan_.reset();
    EVUTIL_CLOSESOCKET(fd_);
    fd_ = INVALID_SOCKET;
}

void Listener::Listen() {
    fd_ = sockets::CreateNonblockingSocket();
    if (fd_ < 0) {
        return;
    }
	struct sockaddr_in addr;
	if (!sockets::ParseFromIPPort(addr_.data(), &addr)){
		return;
	}
	;
    int ret = ::bind(fd_, sockets::sockaddr_cast(&addr), static_cast<socklen_t>(sizeof addr));
    int serrno = errno;
    if (ret < 0) {
        return;
    }
    ret = ::listen(fd_, SOMAXCONN);
    if (ret < 0) {
        return;
    }

    chan_.reset(new FdChannel(loop_, fd_, true, false));
    chan_->SetReadCallback(std::bind(&Listener::HandleAccept, this));
    loop_->RunInLoop(std::bind(&FdChannel::AttachToLoop, chan_.get()));
    listening_ = true;
   
}

void Listener::HandleAccept() {

    struct sockaddr_storage ss;
    socklen_t addrlen = sizeof(ss);
    net_socket_t nfd = -1;
    if ((nfd = ::accept(fd_, sockets::sockaddr_cast(&ss), &addrlen)) == -1) {
        int serrno = errno;
        if (serrno != EAGAIN && serrno != EINTR) {}
        return;
    }

    if (evutil_make_socket_nonblocking(nfd) < 0) {       
        CLOSESOCKET(nfd);
        return;
    }

    sockets::SetKeepAlive(nfd, true);

	std::string raddr;
	sockets::ToIPPort(&ss, raddr);
    if (raddr.empty()) {
        CLOSESOCKET(nfd);
        return;
    }

    if (new_conn_fn_) {
        new_conn_fn_(nfd, raddr, sockets::sockaddr_in_cast(&ss));
    }
}

void Listener::Stop() {
    assert(loop_->IsInLoopThread());
    chan_->DisableAllEvent();
    chan_->Close();
    listening_ = false;
}

