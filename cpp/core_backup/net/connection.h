#pragma once
#ifndef _TCP_LINK_H_
#define _TCP_LINK_H_
#include "common.h"
#include "callbacks.h"

class Connection
	: public std::enable_shared_from_this<Connection>
{
public:
	Connection(struct event_base* ev_base, evutil_socket_t fd);
	~Connection();

	void SetCallback(const ConnCallbacksPtr& cb);
	void SetConnector(const ConnectorPtr& connector);

	static TCPConnectionPtr Connect(struct event_base* ev_base, const std::string& ip, uint16_t port,
		const ConnectorPtr& connector, const ConnCallbacksPtr& cb);

	void Enable(); 
	void Disable();
	bool IsEnabled() const;
	bool Send(const char* data, uint32_t len);
	void Shutdown();
	void Close();

	std::string GetLocalIP() const { return local_ip_; }
	uint16_t GetLocalPort() const { return local_port_; }

	std::string GetRemoteIP() const { return remote_ip_; }
	uint16_t GetRemotePort() const { return remote_port_; }
	
private:
	Connection(struct event_base* ev_base, const ConnectorPtr& connector, const ConnCallbacksPtr& cb);

	bool Connect(const std::string& ip,	uint16_t port);

	void UpdateLocalAddress();
	void UpdateRemoteAddress();
	void DoActualShutdown();

	static void ReadCallback(struct bufferevent* bev, void *ctx);
	static void WriteCallback(struct bufferevent* bev, void *ctx);
	static void EventCallback(struct bufferevent* bev, short what, void *ctx);

	static void UpdateAddress(const sockaddr* addr, socklen_t a_AddrLen, std::string& ip, uint16_t& port);
private:
	struct bufferevent* bev_;

	TCPConnectionPtr self_;

	ConnCallbacksPtr callbacks_;
	ConnectorPtr connector_;

	std::string local_ip_;
	uint16_t local_port_;

	std::string remote_ip_;
	uint16_t remote_port_;

	bool enabled_;
	bool closing_;
};
#endif // _TCP_LINK_H_
