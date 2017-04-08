#include "networkmodule.h"

NetworkModule::NetworkModule()
	: Module()
{

}

NetworkModule::~NetworkModule()
{

}

int NetworkModule::Init()
{
	return Module::Succeed;
}

int NetworkModule::Start()
{
	return Module::Succeed;
}

int NetworkModule::Update()
{
	return Module::Succeed;
}

int NetworkModule::Stop()
{
	return Module::Succeed;
}

int NetworkModule::Release()
{
	return Module::Succeed;
}

void NetworkModule::Free()
{

}

bool NetworkModule::Listen(const std::string& address , INetCallback* cb, uint32_t thread_num/* = 0*/)
{
	return true;
}

bool NetworkModule::Connect(const std::string& address, INetCallback* cb)
{
	return true;
}

bool NetworkModule::Send(NetID netid, const char* data, size_t length)
{
	return true;
}

void NetworkModule::Disconnect(NetID netid)
{

}
