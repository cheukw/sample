#pragma once
#ifndef _BUFFER_H_
#define _BUFFER_H_
#include <vector>
#include <cstring>

class Buffer
{
public:
	Buffer(): data_(), rpos_(0), wpos_(0) { data_.resize(1024 * 4);	}
	Buffer(std::size_t sz) : data_(), rpos_(0), wpos_(0) { data_.resize(sz); }

	Buffer(const Buffer&) = delete;
	Buffer& operator=(const Buffer&) = delete;

	void Reset() { rpos_ = 0; wpos_ = 0; }
	void Resize(std::size_t sz) { data_.resize(sz); }

	char* Data() { return data_.data(); }
	char* ReadBegin() { return Data() + rpos_; }
	char* WriteBegin() { return Data() + wpos_; }

	void ReadBytes(std::size_t bytes) { rpos_ += bytes; }
	void WriteBytes(std::size_t bytes) { wpos_ += bytes; }

	std::size_t Size() const { return wpos_ - rpos_; }
	std::size_t ValidSize() const { return data_.size() - wpos_; }
	std::size_t Capacity() const { return data_.size(); }

	void Normalize() {
		if (rpos_ > 0) {
			if (rpos_ != wpos_)
				memmove(Data(), ReadBegin(), Size());

			wpos_ -= rpos_;
			rpos_ = 0;
		}
	}

	void EstimateSize(std::size_t size) {
		if (ValidSize() < size)
			data_.resize((data_.size() + size) * 3 / 2);
	}

	void Write(const char* data, std::size_t size) {
		if (size > 0) {
			EstimateSize(size);
			memcpy(WriteBegin(), data, size);
			WriteBytes(size);
		}
	}

	void Swap(Buffer& rhs)
	{
		data_.swap(rhs.data_);
		std::swap(wpos_, rhs.wpos_);
		std::swap(rpos_, rhs.rpos_);
	}
private:
	std::vector<char> data_;
	std::size_t rpos_;
	std::size_t wpos_;
};
#endif