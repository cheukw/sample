#pragma once
#include <memory>
#include <vector>
#include <string>
#include <cstdint>
#include <functional>
#include <unordered_map>

#include <net/tcp_server.h>
#include <net/tcp_conn.h>
#include <net/tcp_client.h>
#include <net/event_loop.h>

#if defined(_WIN32) || defined(_WIN64)
typedef intptr_t NetID;
#else
typedef int NetID;
#endif

typedef std::function<void(NetID, std::string, std::string)> AcceptCallback;
typedef std::function<void(NetID, std::string, std::string)> ConnectCallback;
typedef std::function<void(NetID, const char*, uint32_t)> RecvCallback;
typedef std::function<void(NetID)> DisconnectCallback;

class NetworkModule
{
	typedef std::function<void()> Functor;
public:
	NetworkModule();
	~NetworkModule();

	int Init();
	int Start();
	int Update();
	int Stop();
	int Release();

	bool Listen(const std::string& name, const std::string& address,
		const AcceptCallback& acc_cb, const RecvCallback& msg_cb, const DisconnectCallback& disc_cb,uint32_t thread_num = 0);

	bool Connect(const std::string& name, const std::string& address,
		const ConnectCallback& acc_cb, const RecvCallback& msg_cb, const DisconnectCallback& disc_cb);

protected:
	void OnConnection(const TCPConnPtr& conn);
	void OnMessage(const TCPConnPtr& conn, Buffer* msg);

	void HandleConnection(const TCPConnPtr& conn);
	void HandleMessage(const TCPConnPtr& conn, Buffer* msg);
private:
	std::thread thread_;
	std::shared_ptr<EventLoop> loop_;

	struct NetServer {
		std::shared_ptr<TCPServer> server_;
		AcceptCallback acc_cb_;
		RecvCallback msg_cb_;
		DisconnectCallback disc_cb_;
	};
	std::unordered_map<std::string, NetServer> servers_; // 
	
	
	struct NetClient {
		std::shared_ptr<TCPClient> client_;
		ConnectCallback conn_cb_;
		RecvCallback msg_cb_;
		DisconnectCallback disc_cb_;
	};
	std::unordered_map<std::string, NetClient> clients_; // 
	

	std::mutex mutex_;
	std::vector<Functor> pending_functors_; // @Guarded By mutex_
	std::atomic<int> pending_functor_count_;

	std::unordered_map<NetID, TCPConnPtr> conns_;
};
