#pragma once

#ifndef INETWORKMODULE_H__
#define INETWORKMODULE_H__
#include "module.h"

static const char NETWORK_MODULE[] = "NetworkModule";

typedef	unsigned int		NetID;
typedef unsigned int		IP;
typedef unsigned short		Port;

class INetCallback
{
public:
	virtual ~INetCallback() {}
	virtual void OnAccept(Port listen_port, NetID netid, IP ip, Port port) = 0;
	virtual void OnRecv(NetID netid, const char *data, int length) = 0;
	virtual void OnDisconnect(NetID netid) = 0;
	virtual void OnConnect(NetID netid, IP ip, Port port) = 0;

};

class NetworkModule : public Module
{
public:
	NetworkModule();
	~NetworkModule();

	virtual int Init() override;
	virtual int Start() override;
	virtual int Update() override;
	virtual int Stop() override;
	virtual int Release() override;
	virtual void Free() override;

	bool Listen(const std::string& address, INetCallback* cb, uint32_t thread_num = 0);

	bool Connect(const std::string& address, INetCallback* cb);

	bool Send(NetID netid, const char* data, size_t length);

	void Disconnect(NetID netid);
};

#endif /// INETWORKMODULE_H__
