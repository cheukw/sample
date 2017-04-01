#pragma once
#include "networkinterface.h"

class Listener : public IListener
{
public:
	Listener();
	~Listener();

	virtual void SetPacketParser(const PacketParserPtr& pkParser) override;

	virtual void SetSessionFactory(const SessionFactoryPtr& ssFactory) override;

	virtual void SetBufferSize(uint32_t recvBufSize, uint32_t sendBufSize) override;

	virtual bool Start(const char* ip, uint16_t port, bool reuseAddr = true) override;

	virtual bool Stop() override;
private:

};