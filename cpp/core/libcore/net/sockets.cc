#include <string>
#include <cassert>
#include "net/sockets.h"

int readv(net_socket_t sockfd, struct iovec* iov, int iovcnt)
{
	DWORD readn = 0;
	DWORD flags = 0;
	if (::WSARecv(sockfd, iov, iovcnt, &readn, &flags, nullptr, nullptr) == 0) {
		return readn;
	}
	return -1;
}


namespace sockets {
net_socket_t CreateNonblockingSocket() {
	/* Create listen socket */
	net_socket_t fd = ::socket(AF_INET, SOCK_STREAM, 0);
	if (fd == INVALID_SOCKET) {
		return INVALID_SOCKET;
	}

	if (!SetNonBlocking(fd)) {
		goto out;
	}

#ifndef _WIN32
	if (fcntl(fd, F_SETFD, 1) == -1) {
		serrno = errno;
		goto out;
	}
#endif

	SetKeepAlive(fd, true);
	SetReuseAddr(fd);
	SetReusePort(fd);
	return fd;
out:
	CLOSESOCKET(fd);
	return INVALID_SOCKET;
}

bool SetNonBlocking(net_socket_t fd)
{
#if defined(_WIN32) || defined(_WIN64)
	u_long nonblocking = 1;
	if (ioctlsocket(fd, FIONBIO, &nonblocking) == SOCKET_ERROR) {
		return false;
	}
#else
	int flags;
	if ((flags = fcntl(fd, F_GETFL, NULL)) < 0) {
		return false;
	}
	if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
		return false;
	}
#endif
	return true;
}

// address ip:port
bool ParseFromIPPort(const char* address, struct sockaddr_in* addr) {
	std::string a = address;
	size_t index = a.rfind(':');
	if (index == std::string::npos) {
		return false;
	}

	addr->sin_family = AF_INET;
	addr->sin_port = htons(::atoi(&a[index + 1]));
	a[index] = '\0';

	int rc = ::inet_pton(AF_INET, a.data(), &addr->sin_addr);
	if (rc == 0) {
		return false;
	}
	else if (rc < 0) {
		return false;
	}
	//TODO add ipv6 support
	return true;
}

bool GetLocalAddr(net_socket_t sockfd, struct sockaddr_in* laddr) {
	socklen_t addrlen = static_cast<socklen_t>(sizeof laddr);
	if (::getsockname(sockfd, sockaddr_cast(laddr), &addrlen) < 0) {	
		return false;
	}
	return true;
}

bool ToIPPort(const struct sockaddr_storage* ss, std::string& saddr) {
	int port = 0;
	if (ss->ss_family == AF_INET) {
		struct sockaddr_in* addr4 = const_cast<struct sockaddr_in*>(sockaddr_in_cast(ss));
		char buf[INET_ADDRSTRLEN] = {};
		const char* addr = ::inet_ntop(ss->ss_family, &addr4->sin_addr, buf, INET_ADDRSTRLEN);
		if (addr) {
			saddr = addr;
		}
		port = ntohs(addr4->sin_port);
	}
	else if (ss->ss_family == AF_INET6) {
		struct sockaddr_in6* addr6 = const_cast<struct sockaddr_in6*>(sockaddr_in6_cast(ss));
		char buf[INET6_ADDRSTRLEN] = {};
		const char* addr = ::inet_ntop(ss->ss_family, &addr6->sin6_addr, buf, INET6_ADDRSTRLEN);
		if (addr) {
			saddr = addr;
		}
		port = ntohs(addr6->sin6_port);
	}
	else {
		
		return false;
	}

	if (!saddr.empty()) {
		saddr.append(":", 1).append(std::to_string(port));
	}

	return true;
}

bool ToIPPort(const struct sockaddr* ss, std::string& saddr) {
	return ToIPPort(sockaddr_storage_cast(ss), saddr);
}

bool ToIPPort(const struct sockaddr_in* ss, std::string& saddr) {
	return ToIPPort(sockaddr_storage_cast(ss), saddr);
}

bool ToIP(const struct sockaddr* s, std::string& saddr) {
	auto ss = sockaddr_storage_cast(s);
	if (ss->ss_family == AF_INET) {
		struct sockaddr_in* addr4 = const_cast<struct sockaddr_in*>(sockaddr_in_cast(ss));
		char buf[INET_ADDRSTRLEN] = {};
		const char* addr = ::inet_ntop(ss->ss_family, &addr4->sin_addr, buf, INET_ADDRSTRLEN);
		if (addr) {
			saddr = std::string(addr);
			return true;
		}
	}
	else if (ss->ss_family == AF_INET6) {
		struct sockaddr_in6* addr6 = const_cast<struct sockaddr_in6*>(sockaddr_in6_cast(ss));
		char buf[INET6_ADDRSTRLEN] = {};
		const char* addr = ::inet_ntop(ss->ss_family, &addr6->sin6_addr, buf, INET6_ADDRSTRLEN);
		if (addr) {
			saddr = std::string(addr);
			return true;
		}
	}
	else {
		return false;
	}

	return false;
}

bool SetTimeout(net_socket_t fd, uint32_t timeout_ms) {
#if defined(_WIN32) || defined(_WIN64)
	DWORD tv = timeout_ms;
#else
	struct timeval tv;
	tv.tv_sec = timeout_ms / 1000;
	tv.tv_usec = (timeout_ms % 1000) * 1000;
#endif
	int ret = ::setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
	return (ret == 0);
}

bool SetTimeout(net_socket_t fd, const Duration& timeout) {
	return SetTimeout(fd, (uint32_t)(timeout.Milliseconds()));
}

bool SetKeepAlive(net_socket_t fd, bool on) {
	int optval = on ? 1 : 0;
	int rc = ::setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, reinterpret_cast<const char*>(&optval), static_cast<socklen_t>(sizeof optval));
	return (rc == 0);
}

bool SetReuseAddr(net_socket_t fd) {
	int optval = 1;
	int rc = ::setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,	reinterpret_cast<const char*>(&optval), static_cast<socklen_t>(sizeof optval));
	return (rc == 0);
}

bool SetReusePort(net_socket_t fd) {
#ifdef SO_REUSEPORT
	int optval = 1;
	int rc = ::setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, reinterpret_cast<const char*>(&optval), static_cast<socklen_t>(sizeof optval));
	return (rc == 0);
#endif
	return true;
}


bool SetTCPNoDelay(net_socket_t fd, bool on) {
	int optval = on ? 1 : 0;
	int rc = ::setsockopt(fd, IPPROTO_TCP, TCP_NODELAY,	reinterpret_cast<const char*>(&optval), static_cast<socklen_t>(sizeof optval));
	return (rc == 0);
}
} // namespace sockets


