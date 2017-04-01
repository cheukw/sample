#include "ThreadFactory.h"

ThreadFactory::ThreadFactory(bool detached)
	: detached_(detached)
{}

ThreadFactory::~ThreadFactory() { }

std::shared_ptr<Thread> ThreadFactory::newThread(std::shared_ptr<Runnable> runnable) const
{
	std::shared_ptr<Thread> ret = std::make_shared<Thread>(detached_, runnable);
	runnable->setThread(ret);
	return ret;
}

Thread::tid_t ThreadFactory::getCurrentThreadId() const
{
	return std::this_thread::get_id();
}

void ThreadFactory::setDetached(bool detached)
{
	detached_ = detached;
}

bool ThreadFactory::isDetached() const
{
	return detached_;
}