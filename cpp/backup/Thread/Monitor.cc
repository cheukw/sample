#include <cassert>
#include "CommonDef.h"
#include "Monitor.h"

Monitor::Monitor()
	: ownedMutex_(new Mutex())
	, conditionVariable_()
	, mutex_(nullptr)
{
	init(ownedMutex_.get());
}

Monitor::Monitor(Mutex* mutex)
	: ownedMutex_()
	, conditionVariable_()
	, mutex_(nullptr)
{
	init(mutex_);
}

Monitor::Monitor(Monitor* monitor)
	: ownedMutex_()
	, conditionVariable_()
	, mutex_(nullptr)
{
	init(&(monitor->mutex()));
}

Monitor::~Monitor()
{

}

Mutex& Monitor::mutex() const
{
	return *mutex_;
}

void Monitor::lock() const
{
	mutex_->lock();
}

void Monitor::unlock() const
{
	mutex_->unlock();
}

int Monitor::waitForTimeRelative(int64_t timeout_ms) 
{
	if (timeout_ms == 0LL) {
		return waitForever();
	}

	assert(mutex_);
	std::timed_mutex* mutexImpl = static_cast<std::timed_mutex*>(mutex_->get());
	assert(mutexImpl);

	std::unique_lock<std::timed_mutex> lock(*mutexImpl, std::adopt_lock);
	bool timedout = (conditionVariable_.wait_for(lock, std::chrono::milliseconds(timeout_ms))
		== std::cv_status::timeout);
	lock.release();
	return (timedout ? SDK_ETIMEDOUT : 0);
}

int Monitor::waitForTime(const struct timeval* abstime)
{
	assert(mutex_);
	std::timed_mutex* mutexImpl = static_cast<std::timed_mutex*>(mutex_->get());
	assert(mutexImpl);

	struct timeval currenttime;
	auto now = std::chrono::system_clock::now();
	auto millisecs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());;
	currenttime.tv_sec = (long)(millisecs.count() / 1000);
	currenttime.tv_usec = (millisecs.count() % 1000) * 1000;

	
	long tv_sec = static_cast<long>(abstime->tv_sec - currenttime.tv_sec);
	long tv_usec = static_cast<long>(abstime->tv_usec - currenttime.tv_usec);
	if (tv_sec < 0)
		tv_sec = 0;
	if (tv_usec < 0)
		tv_usec = 0;

	std::unique_lock<std::timed_mutex> lock(*mutexImpl, std::adopt_lock);
	bool timedout = (conditionVariable_.wait_for(lock,
		std::chrono::seconds(tv_sec)
		+ std::chrono::microseconds(tv_usec))
		== std::cv_status::timeout);
	lock.release();

	return (timedout ? SDK_ETIMEDOUT : 0);
}

int Monitor::waitForever()
{
	assert(mutex_);
	std::timed_mutex* mutexImpl = static_cast<std::timed_mutex*>(mutex_->get());
	assert(mutexImpl);

	std::unique_lock<std::timed_mutex> lock(*mutexImpl, std::adopt_lock);
	conditionVariable_.wait(lock);
	lock.release();
	return 0;
}


void Monitor::wait(int64_t timeout_ms)
{
	waitForTimeRelative(timeout_ms);
}

void Monitor::notify()
{
	conditionVariable_.notify_one();
}

void Monitor::notifyAll()
{
	conditionVariable_.notify_all();
}

