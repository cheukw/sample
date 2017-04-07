#pragma once
#ifndef _NETWORK_INTERFACE_H_
#define _NETWORK_INTERFACE_H_
#include <cstdint>
#include <memory>

class IPacketParser;
typedef std::shared_ptr<IPacketParser> PacketParserPtr ;

class ISession;
typedef std::shared_ptr<ISession> SessionPtr;

class ISessionFactory;
typedef std::shared_ptr<ISessionFactory> SessionFactoryPtr;

class IListener;
typedef std::shared_ptr<IListener> ListenerPtr;

class IConnector;
typedef std::shared_ptr<IConnector> ConnectorPtr;

class IConnection;
typedef std::shared_ptr<IConnection> ConnectionPtr;

class INetwork
{
public:
	virtual ConnectorPtr CreateConnector() = 0;

	virtual ListenerPtr CreateListener() = 0;

	virtual bool Run(int32_t threadCount) = 0;
};

class IConnection
{
public:
	virtual bool IsConnected() const = 0;

	virtual bool Send(const char* data, uint32_t len) = 0;
	
	virtual void Disconnect() = 0;

	virtual std::string GetLocalIP() const = 0;
	virtual uint16_t GetLocalPort() const = 0;

	virtual std::string GetRemoteIP() const = 0;
	virtual uint16_t GetRemotePort() const = 0;
};

class IListener
{
public:
	virtual void SetPacketParser(const PacketParserPtr& pkParser) = 0;

	virtual void SetSessionFactory(const SessionFactoryPtr& ssFactory) = 0;

	virtual void SetBufferSize(uint32_t recvBufSize, uint32_t sendBufSize) = 0;

	virtual bool Start(const char* ip, uint16_t port, bool reuseAddr = true) = 0;

	virtual bool Stop() = 0;
};

class IConnector
{
public:
	virtual void SetPacketParser(const PacketParserPtr& pkParser) = 0;

	virtual void SetBufferSize(uint32_t recvBufSize, uint32_t sendBufSize) = 0;

	virtual void SetSession(const SessionPtr& ss) = 0;

	virtual bool Connect(const char* ip, uint16_t port) = 0;
};

class IPacketParser
{
public:
	virtual int32_t ParsePacket(const char* buf, uint32_t len) = 0;
};

class ISession
{
public:
	virtual void SetConnection(const ConnectionPtr& conn) = 0;

	virtual void OnEstablish() = 0;

	virtual void OnTerminate() = 0;

	virtual void OnError(uint32_t errCode, const char* errMsg) = 0;

	virtual void OnRecv(const char* buf, uint32_t len) = 0;

	virtual void Release() = 0;
};

class ISessionFactory
{
public:
	virtual SessionPtr CreateSession(const ConnectionPtr& conn) = 0;
};
#endif /// _NETWORK_INTERFACE_H_


