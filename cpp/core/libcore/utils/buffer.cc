#include "utils/buffer.h"

const char Buffer::kCRLF[] = "\r\n";
const size_t Buffer::kCheapPrependSize = 8;
const size_t Buffer::kInitialSize = 1024;

ssize_t Buffer::ReadFromFD(net_socket_t fd, int* saved_errno)
{
	// saved an ioctl()/FIONREAD call to tell how much to read
	char extrabuf[65536];
	struct iovec vec[2];
	const size_t writable = WritableBytes();
	vec[0].iov_base = Begin() + write_index_;
#if defined(_WIN64) || defined(_WIN32)
	vec[0].iov_len = (ULONG)writable;
#else
	vec[0].iov_len = writable;
#endif
	vec[1].iov_base = extrabuf;
	vec[1].iov_len = sizeof extrabuf;
	// when there is enough space in this buffer, don't read into extrabuf.
	// when extrabuf is used, we read 64k bytes at most.
	const int iovcnt = (writable < sizeof extrabuf) ? 2 : 1;
	const ssize_t n = ::readv(fd, vec, iovcnt);

	if (n < 0) {
		*saved_errno = SOCKET_ERROR;
	}
	else if (static_cast<size_t>(n) <= writable) {
		write_index_ += n;
	}
	else {
		write_index_ = capacity_;
		Append(extrabuf, n - writable);
	}

	return n;
}