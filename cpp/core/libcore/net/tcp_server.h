#pragma once

#include "net/inner_pre.h"
#include "net/event_loop.h"
#include "net/event_loop_thread_pool.h"
#include "net/tcp_callbacks.h"
#include "net/thread_dispatch_policy.h"

#include <map>

class Listener;

class TCPServer : public ThreadDispatchPolicy {
public:
    TCPServer(EventLoop* loop,  const std::string& listen_addr, const std::string& name, uint32_t thread_num);
    ~TCPServer();

    bool Init();
    bool Start();
    void Stop(); // TODO ADD a parameter : bool wait_until_stopped

public:
    // Set a connection event relative callback when the TCPServer
    // receives a new connection or an exist connection breaks down.
    // When these two events happened, the value of the parameter in the callback is:
    //      1. Received a new connection : TCPConn::IsConnected() == true
    //      2. An exist connection broken down : TCPConn::IsDisconnecting() == true
    void SetConnectionCallback(const ConnectionCallback& cb) {conn_fn_ = cb; }
    void SetMessageCallback(MessageCallback cb) { msg_fn_ = cb; }

    bool IsRunning() const;
    bool IsStopped() const;
    const std::string& listen_addr() const { return listen_addr_; }
private:
    void StopInLoop();
    void RemoveConnection(const TCPConnPtr& conn);
    void HandleNewConn(net_socket_t sockfd, const std::string& remote_addr, const struct sockaddr_in* raddr);
    EventLoop* GetNextLoop(const struct sockaddr_in* raddr);
private:
    EventLoop* loop_;  // the listening loop
    const std::string listen_addr_; // ip:port
    const std::string name_;
    std::unique_ptr<Listener> listener_;
    std::shared_ptr<EventLoopThreadPool> tpool_;
    ConnectionCallback conn_fn_;
    MessageCallback msg_fn_;

    // always in the listening loop thread
    uint64_t next_conn_id_;
    typedef std::map<std::string, TCPConnPtr> ConnectionMap;
    ConnectionMap connections_;
};
