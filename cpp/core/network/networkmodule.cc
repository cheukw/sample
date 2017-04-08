#include "networkmodule.h"

NetworkModule::NetworkModule()
{

}

NetworkModule::~NetworkModule()
{

}

int NetworkModule::Init() 
{
	return 0;
}

int NetworkModule::Start()
{
	loop_ = std::make_shared<EventLoop>();
	thread_ = std::thread([this]() {this->loop_->Run(); });

	return 0;
}

int NetworkModule::Update()
{

	return 0;
}

int NetworkModule::Stop()
{
	loop_->Stop();
	thread_.join();
	return 0;
}

int NetworkModule::Release()
{
	return 0;
}

bool NetworkModule::Listen(const std::string& name, const std::string& address,
	const AcceptCallback& acc_cb, const RecvCallback& msg_cb, const DisconnectCallback& disc_cb, uint32_t thread_num /* = 0 */)
{
	if (servers_.find(name) != servers_.end()) {
		return false;
	}

	NetServer srv;
	srv.server_ = std::make_shared<TCPServer>(loop_.get(), address, name, thread_num);
	srv.server_->Init();
	srv.server_->SetConnectionCallback(std::bind(&NetworkModule::OnConnection, this, std::placeholders::_1));
	srv.server_->SetMessageCallback(std::bind(&NetworkModule::OnMessage, this, std::placeholders::_1, std::placeholders::_2));
	srv.acc_cb_ = acc_cb;
	srv.msg_cb_ = msg_cb;
	srv.disc_cb_ = disc_cb;

	servers_.insert(std::make_pair(name, srv));
	return true;
}

bool NetworkModule::Connect(const std::string& name, const std::string& address,
	const ConnectCallback& conn_cb, const RecvCallback& msg_cb, const DisconnectCallback& disc_cb)
{
	NetClient client;
	client.client_ = std::make_shared<TCPClient>(loop_.get(), address, name);
	client.client_->SetConnectionCallback(std::bind(&NetworkModule::OnConnection, this, std::placeholders::_1));
	client.client_->SetMessageCallback(std::bind(&NetworkModule::OnMessage, this, std::placeholders::_1, std::placeholders::_2));
	client.client_->Connect();
	client.conn_cb_ = conn_cb;
	client.msg_cb_ = msg_cb;
	client.disc_cb_ = disc_cb;

	clients_.insert(std::make_pair(name, client));
	return true;
}

void NetworkModule::OnConnection(const TCPConnPtr& conn) {
	if (loop_->IsInLoopThread()) {
		HandleConnection(conn);
	}
	else {
		loop_->RunInLoop(std::bind(&NetworkModule::HandleConnection, this, conn));
	}
}

#define PACKET_HEADER_LENGTH 2
void NetworkModule::OnMessage(const TCPConnPtr& conn, Buffer* msg) {
	// slice packet
	if (msg->Length() < PACKET_HEADER_LENGTH) {
		return;
	}

	msg->PeekInt16();


}

void NetworkModule::HandleConnection(const TCPConnPtr& conn) {
	assert(std::this_thread::get_id() == loop_->tid());
	if (conn->type() == TCPConn::kIncoming) {
		const std::string& name = conn->name();
		size_t pos = name.find('-');
		std::string sname = name.substr(0, pos);
		auto iter = servers_.find(sname);
		if (iter == servers_.end()) {
			return;
		}

		if (conn->IsConnected()) {
			{
				std::lock_guard<std::mutex> lock(mutex_);
				pending_functors_.emplace_back([&]() {
					iter->second.acc_cb_(conn->fd(), conn->local_addr(), conn->remote_addr());
				});
			}
			conns_[conn->fd()] = conn;
		}
		else {
			{
				std::lock_guard<std::mutex> lock(mutex_);
				pending_functors_.emplace_back([&]() {
					iter->second.disc_cb_(conn->fd());
				});
			}
			conns_.erase(conn->fd());
		}
		
	}
	else if(conn->type() == TCPConn::kOutgoing){
		const std::string& name = conn->name();
		auto iter = clients_.find(name);
		if (iter == clients_.end()) {
			return;
		}

		if (conn->IsConnected()) {
			{
				std::lock_guard<std::mutex> lock(mutex_);
				pending_functors_.emplace_back([&]() {
					iter->second.conn_cb_(conn->fd(), conn->local_addr(), conn->remote_addr());
				}); 
			}
			conns_[conn->fd()] = conn;
		}
		else {
			{
				std::lock_guard<std::mutex> lock(mutex_);
				pending_functors_.emplace_back([&]() {
					iter->second.disc_cb_(conn->fd());
				});
			}
			conns_.erase(conn->fd());
		}
	}

}

void NetworkModule::HandleMessage(const TCPConnPtr& conn, Buffer* msg) {
	assert(std::this_thread::get_id() == loop_->tid());


}
