#pragma once
#ifndef _CONNECTOR_H_
#define _CONNECTOR_H_
#include "networkinterface.h"

class Connector : public IConnector
{
public:
	Connector();
	~Connector();

	virtual void SetPacketParser(const PacketParserPtr& pkParser) override;

	virtual void SetBufferSize(uint32_t recvBufSize, uint32_t sendBufSize) override;

	virtual void SetSession(const SessionPtr& ss) override;

	virtual bool Connect(const char* ip, uint16_t port) override;
private:

};
#endif /// _CONNECTOR_H_

