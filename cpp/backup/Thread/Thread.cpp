#include "Thread.h"

Thread::Thread(bool detached, std::shared_ptr<Runnable>& runnable)
	: state_(STATE::UNINITIALIZED)
	, detached_(detached)
{
	this->runnable(runnable);
}

Thread::~Thread()
{
	if (!detached_)
	{
		try
		{
			join();
		}
		catch (...)
		{
			//...
		}
	}
}

void Thread::start()
{
	if (state_ != STATE::UNINITIALIZED)
	{
		return;
	}
	std::shared_ptr<Thread> selfRef = shared_from_this();
	state_ = STATE::STARTING;

	thread_ = std::unique_ptr<std::thread>(new std::thread(threadMain, selfRef));

	if (detached_)
		thread_->detach();
}

void Thread::join()
{
	if (!detached_ && state_ != STATE::UNINITIALIZED)
	{
		thread_->join();
	}
}

Thread::tid_t Thread::getId()
{
	return thread_.get() ? thread_->get_id() : std::thread::id();
}

std::shared_ptr<Runnable> Thread::runnable() const
{
	return runnable_;
}

void Thread::runnable(std::shared_ptr<Runnable>& runnable)
{
	runnable_ = runnable;
}

void Thread::threadMain(std::shared_ptr<Thread>& t)
{
	if (t == NULL)	return;

	if (t->state_ != STATE::STARTING) 
	{
		return;
	}

	t->state_ = STATE::STARTED;
	t->runnable()->run();

	if (t->state_ != STATE::STOPPING && t->state_ != STATE::STOPPED)
	{
		t->state_ = STATE::STOPPING;
	}
	return;
}



