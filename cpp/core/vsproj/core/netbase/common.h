#pragma once
#ifndef NET_COMMON_H_
#define NET_COMMON_H_

// define os support
#if defined(_WIN32) || defined(_WIN64)
#ifndef OS_WIN
#define OS_WIN
#endif
#else
#ifndef OS_POSIX
#define OS_POSIX
#endif
#endif

#include <cstdint>

#define OK 0

#if defined(OS_WIN)
#include <WinSock2.h>
#include <WS2tcpip.h>


#define socket_t SOCKET
#define invalid_socket_t INVALID_SOCKET
#define GET_SOCKET_ERROR() WSAGetLastError()
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define socket_t int
#define invalid_socket_t -1
#define GET_SOCKET_ERROR() (errno)
#endif


#endif // NET_COMMON_H_