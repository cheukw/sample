#include "listener.h"

Listener::Listener() {

}

Listener::~Listener() {

}

void Listener::SetPacketParser(const PacketParserPtr& pkParser) {

}

void Listener::SetSessionFactory(const SessionFactoryPtr& ssFactory) {

}

void Listener::SetBufferSize(uint32_t recvBufSize, uint32_t sendBufSize) {

}

bool Listener::Start(const char* ip, uint16_t port, bool reuseAddr /* = true */) {
	return true;
}

bool Listener::Stop() {
	return true;
}