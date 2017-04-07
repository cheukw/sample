#pragma once
#ifndef _PACKET_PARSER_H_
#define _PACKET_PARSER_H_
#include "networkinterface.h"
class PacketParser : public IPacketParser
{
public:
	PacketParser();
	~PacketParser();

	virtual int32_t ParsePacket(const char* buf, uint32_t len) override;
private:

};


#endif /// _PACKET_PARSER_H_
