#pragma once
#include <string>
#include "utils/duration.h"

#if defined(_WIN64) || defined(_WIN32)
//#include <windows.h>

#include <ws2tcpip.h>
#include <winsock2.h>
//#include <io.h>
//#include <ws2ipdef.h>

#ifndef net_socket_t
#define net_socket_t intptr_t
#endif // net_socket_t

typedef int ssize_t;
#define iovec _WSABUF
#define iov_base buf
#define iov_len  len

#define SOCKET_ERRNO WSAGetLastError()
#define CLOSESOCKET closesocket

#define usleep(us) Sleep((us)/1000)
#define snprintf  _snprintf

#ifndef MSG_NOSIGNAL
#define MSG_NOSIGNAL 0
#endif

#ifndef MSG_DONTWAIT
#define MSG_DONTWAIT 0
#endif
#else
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/uio.h>
#ifndef net_socket_t
#   define net_socket_t int           /**< SOCKET definition */
#endif
#ifndef INVALID_SOCKET
#   define INVALID_SOCKET -1    /**< invalid socket definition */
#endif
#define SOCKET_ERRNO errno
#define CLOSESOCKET close
#endif 

// Copied from libevent2.0/util-internal.h
#if defined(_WIN64) || defined(_WIN32)
#define EVUTIL_ERR_RW_RETRIABLE(e)                  \
    ((e) == WSAEWOULDBLOCK ||						\
     (e) == WSAETIMEDOUT ||							\
     (e) == WSAEINTR)

#define EVUTIL_ERR_CONNECT_RETRIABLE(e)				\
    ((e) == WSAEWOULDBLOCK ||						\
     (e) == WSAEINTR ||								\
     (e) == WSAEINPROGRESS ||						\
     (e) == WSAEINVAL)

#define EVUTIL_ERR_ACCEPT_RETRIABLE(e)				\
    EVUTIL_ERR_RW_RETRIABLE(e)

#define EVUTIL_ERR_CONNECT_REFUSED(e)               \
    ((e) == WSAECONNREFUSED)

#else
/* True iff e is an error that means a read/write operation can be retried. */
#define EVUTIL_ERR_RW_RETRIABLE(e)              \
    ((e) == EINTR || (e) == EAGAIN)
/* True iff e is an error that means an connect can be retried. */
#define EVUTIL_ERR_CONNECT_RETRIABLE(e)         \
    ((e) == EINTR || (e) == EINPROGRESS)
/* True iff e is an error that means a accept can be retried. */
#define EVUTIL_ERR_ACCEPT_RETRIABLE(e)          \
    ((e) == EINTR || (e) == EAGAIN || (e) == ECONNABORTED)

/* True iff e is an error that means the connection was refused */
#define EVUTIL_ERR_CONNECT_REFUSED(e)                   \
    ((e) == ECONNREFUSED)

#endif

#if defined(_WIN32) || defined(_WIN64)
int readv(net_socket_t sockfd, struct iovec* iov, int iovcnt);
#endif

namespace sockets {
net_socket_t CreateNonblockingSocket();
bool SetNonBlocking(net_socket_t fd);
bool SetKeepAlive(net_socket_t fd, bool on);
bool SetReuseAddr(net_socket_t fd);
bool SetReusePort(net_socket_t fd);
bool SetTCPNoDelay(net_socket_t fd, bool on);
bool SetTimeout(net_socket_t fd, uint32_t timeout_ms);
bool SetTimeout(net_socket_t fd, const Duration& timeout);
bool ParseFromIPPort(const char* address, struct sockaddr_in* sadd);
bool GetLocalAddr(net_socket_t sockfd, struct sockaddr_in* sadd);
bool ToIPPort(const struct sockaddr_storage* ss, std::string& saddr);
bool ToIPPort(const struct sockaddr* ss, std::string& saddr);
bool ToIPPort(const struct sockaddr_in* ss, std::string& saddr);
bool ToIP(const struct sockaddr* ss, std::string& saddr);

template<typename To, typename From>
inline To implicit_cast(From const& f) {
	return f;
}

inline const struct sockaddr* sockaddr_cast(const struct sockaddr_in* addr) {
	return static_cast<const struct sockaddr*>(sockets::implicit_cast<const void*>(addr));
}

inline struct sockaddr* sockaddr_cast(struct sockaddr_in* addr) {
	return static_cast<struct sockaddr*>(sockets::implicit_cast<void*>(addr));
}

inline struct sockaddr* sockaddr_cast(struct sockaddr_storage* addr) {
	return static_cast<struct sockaddr*>(sockets::implicit_cast<void*>(addr));
}

inline const struct sockaddr_in* sockaddr_in_cast(const struct sockaddr* addr) {
	return static_cast<const struct sockaddr_in*>(sockets::implicit_cast<const void*>(addr));
}

inline struct sockaddr_in* sockaddr_in_cast(struct sockaddr* addr) {
	return static_cast<struct sockaddr_in*>(sockets::implicit_cast<void*>(addr));
}

inline struct sockaddr_in* sockaddr_in_cast(struct sockaddr_storage* addr) {
	return static_cast<struct sockaddr_in*>(sockets::implicit_cast<void*>(addr));
}

inline struct sockaddr_in6* sockaddr_in6_cast(struct sockaddr_storage* addr) {
	return static_cast<struct sockaddr_in6*>(sockets::implicit_cast<void*>(addr));
}

inline const struct sockaddr_in* sockaddr_in_cast(const struct sockaddr_storage* addr) {
	return static_cast<const struct sockaddr_in*>(sockets::implicit_cast<const void*>(addr));
}

inline const struct sockaddr_in6* sockaddr_in6_cast(const struct sockaddr_storage* addr) {
	return static_cast<const struct sockaddr_in6*>(sockets::implicit_cast<const void*>(addr));
}

inline const struct sockaddr_storage* sockaddr_storage_cast(const struct sockaddr* addr) {
	return static_cast<const struct sockaddr_storage*>(sockets::implicit_cast<const void*>(addr));
}

inline const struct sockaddr_storage* sockaddr_storage_cast(const struct sockaddr_in* addr) {
	return static_cast<const struct sockaddr_storage*>(sockets::implicit_cast<const void*>(addr));
}

inline const struct sockaddr_storage* sockaddr_storage_cast(const struct sockaddr_in6* addr) {
	return static_cast<const struct sockaddr_storage*>(sockets::implicit_cast<const void*>(addr));
}
} // namespace sockets

