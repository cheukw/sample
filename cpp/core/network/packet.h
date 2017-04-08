#pragma once
#include <cstdint>
#include <limits>
static const uint16_t header_length = 2;
static const uint16_t max_pk_length = std::numeric_limits<uint16_t>::max();

class Packet
{
	Packet(const char* data, uint32_t length) {
	
	}
	~Packet(){
		delete[]data_;
	}

	char* data_;
	uint32_t length_;
};