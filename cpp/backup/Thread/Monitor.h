#pragma once
#include <memory>
#include <condition_variable>
#include "Mutex.h"

class Mutex;
class Monitor
{
public:
	Monitor();

	explicit Monitor(Mutex* mutex);

	explicit Monitor(Monitor* monitor);

	virtual ~Monitor();

	Mutex& mutex() const;

	void lock() const;

	void unlock() const;

	int waitForTimeRelative(int64_t timeout_ms);

	//int waitForTime(const THRIFT_TIMESPEC* abstime) const;

	int waitForTime(const struct timeval* abstime);

	int waitForever();

	
	void wait(int64_t timeout_ms = 0LL);

	void notify();


	void notifyAll();


private:
	void init(Mutex* mutex) { mutex_ = mutex; }

	const std::unique_ptr<Mutex> ownedMutex_;
	std::condition_variable_any conditionVariable_;
	Mutex* mutex_;
};

class Synchronized {
public:
	Synchronized(const Monitor* monitor) : g(monitor->mutex()) {}
	Synchronized(const Monitor& monitor) : g(monitor.mutex()) {}

private:
	LockGuard g;
};

