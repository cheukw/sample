#pragma once
#ifndef _CONNECTOR_H_
#define _CONNECTOR_H_
#include "common.h"
#include "callbacks.h"

class Connector 
	: public std::enable_shared_from_this<Connector>
{
public:
	Connector(struct event_base* ev_base, const std::string& ip, uint16_t port);
	~Connector();

	bool Connect();

	bool AsyncConnect();

	void Close();
private:
	friend class Connection;

	void OnClose();

	struct event_base* ev_base_;
	TCPConnectionPtr conn_;

	ConnectCallbacksPtr callbacks_;
	ConnCallbacksPtr conn_cbs_;

	std::string ip_;
	uint16_t port_;
	bool closed_;
};
#endif /// _CONNECTOR_H_


