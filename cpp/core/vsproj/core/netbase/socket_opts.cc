#include "socket_opts.h"

socket_t CreateSocket()
{
	return socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

void CloseSocket(socket_t sockfd)
{
#if defined(OS_WIN)
	closesocket(sockfd);
#else
	close(sockfd);
#endif
}

int BindAndListen(socket_t sockfd, const char* ip, uint16_t port) 
{
	sockaddr_in	sin;
	memset(&sin, 0, sizeof(sockaddr_in));
	sin.sin_family = AF_INET;
	sin.sin_port = port;
	if (inet_pton(AF_INET, ip, &sin.sin_addr) != 1) {
		int err = GET_SOCKET_ERROR();
		return err;
	}
	if (bind(sockfd, reinterpret_cast<struct sockaddr*>(&sin), sizeof(struct sockaddr_in)) != 0) {
		int err = GET_SOCKET_ERROR();
		return err;
	}
	int ret = SetNonBlocking(sockfd, true);
	if (ret != OK) {
		return ret;
	}

	if (listen(sockfd, 0) != 0) {
		return GET_SOCKET_ERROR();
	}
	return OK;
}

int Connect(socket_t sockfd, const char* ip, uint16_t port)
{
	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(struct sockaddr_in));
	sin.sin_family = AF_INET;
	sin.sin_port = ::htons(port);
	if (inet_pton(AF_INET, ip, &sin.sin_addr) != 1) {
		int err = GET_SOCKET_ERROR();
		return err;
	}
	if (connect(sockfd, (const sockaddr*)&sin, sizeof(struct sockaddr_in)) != 0) {
		int err = GET_SOCKET_ERROR();
		return err;
	}
	return OK;
}

int SetNoDelay(socket_t sockfd, bool flag)
{
	int arg = int(flag);
	return setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (char*)&arg, sizeof(int));
}

int SetNonBlocking(socket_t sockfd, bool flag)
{
#if defined(OS_WIN)
	u_long val = flag ? 1 : 0;
	return ioctlsocket(sockfd, FIONBIO, &val);
#else
	int val = flag ? O_NONBLOCK : 0;
	return fcntl(sockfd, F_SETFL, val);
#endif
}

int SetReuseAddress(socket_t sockfd, bool flag)
{
#if defined(OS_WIN)
	bool val;
#else
	int val;
#endif
	val = flag ? 1 : 0;
	return setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char*)&val, sizeof(val));
}

int SetLinger(socket_t sockfd, uint16_t onoff, uint16_t linger)
{
	struct linger l = { 0 };
	l.l_onoff = onoff;
	l.l_linger = linger;
	return setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (const char *)&l, sizeof(l));
}

int SetKeepAlive(socket_t sockfd, bool flag)
{
#if defined(OS_WIN)
	bool val;
#else
	int val;
#endif
	val = flag ? 1 : 0;
	return setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (char*)&val, sizeof(val));
}

int SetReceiveBufferSize(socket_t sockfd, int32_t sz) {
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, reinterpret_cast<const char*>(&sz), sizeof(sz)) != 0)
	{
		return GET_SOCKET_ERROR();
	}
	return OK;
}

int SetSendBufferSize(socket_t sockfd, int32_t sz) {
	if (setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, reinterpret_cast<const char*>(&sz), sizeof(sz)) != 0)
	{
		return GET_SOCKET_ERROR();
	}
	return OK;
}

int GetLocalAddress(socket_t sockfd, struct sockaddr_storage* sa)
{
	socklen_t salen = static_cast<socklen_t>(sizeof(*sa));
	if (getsockname(sockfd, reinterpret_cast<sockaddr *>(sa), &salen) != 0) {
		int err = GET_SOCKET_ERROR();
		return err;
	}
	return OK;
}

int GetPeerAddress(socket_t sockfd, struct sockaddr_storage* sa)
{
	socklen_t salen = static_cast<socklen_t>(sizeof(*sa));
	if (getpeername(sockfd, reinterpret_cast<sockaddr *>(sa), &salen) != 0) {
		int err = GET_SOCKET_ERROR();
		return err;
	}
	return OK;
}


