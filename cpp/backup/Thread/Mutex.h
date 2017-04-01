#pragma once

#include <mutex>


class Mutex
{
public:
	Mutex(): mutex_(){}

	virtual ~Mutex(){}

	void lock() { mutex_.lock(); }
	bool trylock() { mutex_.try_lock(); }
	bool timedlock(int64_t milliseconds) { mutex_.try_lock_for(std::chrono::milliseconds(milliseconds)); }
	void unlock() { mutex_.unlock(); }
	std::timed_mutex* get() { return &mutex_; }
private:
	std::timed_mutex mutex_;
};

class LockGuard
{
public:
	LockGuard(Mutex& value, int64_t timeout = 0)
		: mutex_(&value)
	{
		if (timeout == 0) value.lock();
		else if (timeout < 0)
		{
			if (!value.trylock())
			{
				mutex_ = NULL;
			}
		}
		else 
		{
			if (!value.timedlock(timeout))
			{
				mutex_ = NULL;
			}
		}
	}

	~LockGuard()
	{
		if (mutex_)	mutex_->unlock();
	}

	operator bool() const { return (mutex_ != NULL); }

private:
	Mutex* mutex_;
};

