

#pragma once

#ifndef INETWORKMODULE_H
#define INETWORKMODULE_H

#include "imodule.h"

static const char NETWORK_MODULE[] = "NetworkModule";

typedef	unsigned int		NetID;
typedef unsigned int		IP;
typedef unsigned short		Port;

class IEngineNetCallback
{
public:
	virtual ~IEngineNetCallback(){}

	virtual void OnAccept(Port listen_port, NetID netid, IP ip, Port port)=0;

	virtual void OnRecv(NetID netid, const char *data, int length)=0;

	virtual void OnDisconnect(NetID netid)=0;

	virtual void OnConnect(bool result, int handle, NetID netid, IP ip, Port port)=0;
};

class INetworkModule : public IModule
{

public:
	virtual int Init()=0;
	virtual int Start()=0;
	virtual int Update()=0;
	virtual int Stop()=0;
	virtual int Release()=0;
	virtual void Free()=0;

	virtual void RegisterCallback(IEngineNetCallback * callback)=0;

	virtual bool Listen(Port port, int backlog, NetID *netid_out=0, const char *ip_bind=0)=0;

	virtual bool Connect(const char *ip, Port port, NetID *netid_out, unsigned long time_out=3000)=0;

	virtual bool Connect(IP ip, Port port, NetID *netid_out, unsigned long time_out=3000)=0;

	virtual bool Send(NetID netid, const char *data, unsigned int length)=0;

	virtual void Disconnect(NetID netid)=0;

	virtual const char *GetPeerName(NetID netid)=0;
};

#endif
