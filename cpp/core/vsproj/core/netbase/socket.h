#pragma once
#ifndef NET_SOCKET_H_
#define NET_SOCKET_H_
#include "common.h"
#include "socket_opts.h"

class Socket 
{
public:
	Socket(socket_t fd);
	~Socket();

	
private:
	const socket_t fd_;
};
#endif // SOCKET_H_

