#pragma once

#ifndef INETWORKMODULE_H__
#define INETWORKMODULE_H__

#include "module.h"

static const char NETWORK_MODULE[] = "NetworkModule";

class INetworkModule : public Module
{

public:
	virtual int Init()=0;
	virtual int Start()=0;
	virtual int Update()=0;
	virtual int Stop()=0;
	virtual int Release()=0;
	virtual void Free()=0;

	virtual bool Listen()=0;

	virtual bool Connect()=0;

	virtual bool Send()=0;

	virtual void Disconnect()=0;

	virtual const char *GetPeerName()=0;
};

#endif /// INETWORKMODULE_H__
