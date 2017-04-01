#pragma once
#include <thread>
#include <memory>

class Thread;
class Runnable
{
public:
	virtual ~Runnable() {}

	virtual void run() = 0;

	virtual std::shared_ptr<Thread> getThread() { return thread_.lock(); }

	virtual void setThread(std::shared_ptr<Thread>& t) { thread_ = t; }

protected:
	std::weak_ptr<Thread> thread_;
};

