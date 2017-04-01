#pragma once
#ifndef NET_SOCKET_OPTS_H_
#define NET_SOCKET_OPTS_H_
#include "common.h"

socket_t CreateSocket();
void CloseSocket(socket_t sockfd);

int BindAndListen(socket_t sockfd, const char* ip, uint16_t port);
int Connect(socket_t sockfd, const char* ip, uint16_t port);

int SetNoDelay(socket_t sockfd, bool flag);
int SetNonBlocking(socket_t sockfd, bool flag);
int SetReuseAddress(socket_t sockfd, bool flag);
int SetLinger(socket_t sockfd, uint16_t onoff, uint16_t linger);
int SetKeepAlive(socket_t sockfd, bool flag);

int SetReceiveBufferSize(socket_t sockfd, int32_t sz);
int SetSendBufferSize(socket_t sockfd, int32_t sz);

int GetLocalAddress(socket_t sockfd, struct sockaddr_storage* sa);

int GetPeerAddress(socket_t sockfd, struct sockaddr_storage* sa);

#endif // NET_SOCKET_OPTS_H_
