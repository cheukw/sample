#include "Thread.h"


class ThreadFactory final
{
public:
	ThreadFactory(bool detached = true);

	~ThreadFactory();

	std::shared_ptr<Thread> newThread(std::shared_ptr<Runnable> runnable) const;

	static const Thread::tid_t unknown_thread_id;

	virtual Thread::tid_t getCurrentThreadId() const;

	void setDetached(bool detached);

	bool isDetached() const;

private:
	bool detached_;
};


