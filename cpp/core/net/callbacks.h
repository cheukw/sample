#pragma once
#ifndef _CALLBACK_H_
#define _CALLBACK_H_
#include "common.h"

class ConnCallbacks
{
public:
	virtual ~ConnCallbacks() {}
	virtual void OnEstablished(TCPConnectionPtr link) = 0;
	virtual void OnRecv(const char* data, size_t length) = 0;
	virtual void OnClosed() = 0;
	virtual void OnError(int ec, const std::string& err) = 0;
};
typedef std::shared_ptr<ConnCallbacks> ConnCallbacksPtr;


class AcceptCallbacks {
public:
	virtual ~AcceptCallbacks() {}
	virtual void OnAccepted(const TCPConnectionPtr& link) = 0;
	virtual void OnError(int ec, const std::string& err) = 0;
};
typedef std::shared_ptr<AcceptCallbacks> AcceptCallbacksPtr;

class ConnectCallbacks {
public:
	virtual ~ConnectCallbacks(){}
	virtual void OnConnected(const TCPConnectionPtr& link) = 0;
	virtual void OnError(int ec, const std::string& err) = 0;
};
typedef std::shared_ptr<ConnectCallbacks> ConnectCallbacksPtr;


#endif  /// _CALLBACK_H_

