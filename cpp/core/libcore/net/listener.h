#pragma once
#include <functional>
#include <memory>
#include "net/inner_pre.h"
#include "utils/timestamp.h"

class EventLoop;
class FdChannel;

class Listener {
public:
    typedef std::function <void(net_socket_t sockfd, const std::string&, const struct sockaddr_in*)> NewConnectionCallback;

    Listener(EventLoop* loop, const std::string& addr/*local listening address : ip:port*/);
    ~Listener();

    void Listen();
    void Stop();

    void SetNewConnectionCallback(NewConnectionCallback cb) {
        new_conn_fn_ = cb;
    }

    bool listening() const {
        return listening_;
    }
private:
    void HandleAccept();

private:
    net_socket_t fd_;// The listening socket fd
    EventLoop* loop_;
    bool listening_;
    std::string addr_;
    std::unique_ptr<FdChannel> chan_;
    NewConnectionCallback new_conn_fn_;
};



