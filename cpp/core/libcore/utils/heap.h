#pragma once
#ifndef HEAP_H__
#define HEAP_H__

#include <stdlib.h>
#include <memory.h>

template<class T>
class Heap
{
public:
	Heap() :data_(0), size_(0), max_size_(0){Resize(128);}

	~Heap()	{
		if (data_ != 0)
			free(data_);
	}

	void Push(const T &val)
	{
		if (size_ == max_size_) Resize(max_size_ * 2);

		int s = size_;
		++size_;
		while (s > 0){
			int f = (s - 1) / 2;
			if (!(val < data_[f])) break;

			data_[s] = data_[f];
			s = f;
		}
		data_[s] = val;
	}

	void PopFront()
	{
		if (size_ == 0) return;

		--size_;

		if (size_ == 0) return;

		T tmp = data_[size_];
		int f = 0;
		int half_size = size_ / 2;
		while (f < half_size){
			int s = f * 2 + 1;
			if (s + 1 < size_ && data_[s + 1] < data_[s]) ++s;

			if (!(data_[s] < tmp)) break;

			data_[f] = data_[s];
			f = s;
		}
		data_[f] = tmp;
	}

	T & Front() { return data_[0]; }
	bool Front(T *v)
	{
		if (size_ != 0){
			*v = data_[0];
			return true;
		}
		return false;
	}
	int Size() { return size_; }
	void Clear() { size_ = 0; }

protected:
	T *data_;
	int size_;
	int max_size_;

	void Resize(int size)
	{
		if (size <= max_size_) return;
		T *new_data = (T*)malloc(size * sizeof(T));
		if (data_ != 0){
			memcpy(new_data, data_, size_ * sizeof(T));
			free(data_);
		}
		data_ = new_data;
		max_size_ = size;
	}
};

#endif

