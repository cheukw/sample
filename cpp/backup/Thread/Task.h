#pragma once
#include "Runnable.h"

/*
 * Task has expire
 */
class Task
{
public:
	enum class STATE { 
		WAITING, 
		EXECUTING, 
		CANCELLED, 
		COMPLETE 
	};

	Task(std::shared_ptr<Runnable> runnable, int64_t expiration = 0LL)
		: runnable_(runnable),
		state_(STATE::WAITING),
		expireTime_(expiration != 0LL ? std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) + expiration : 0LL)
	{

	}

	~Task() {}

	void run()
	{
		if (state_ == STATE::EXECUTING)
		{
			runnable_->run();
			state_ = STATE::COMPLETE;
		}
	}

	std::shared_ptr<Runnable> getRunnable() { return runnable_; }

	int64_t getExpireTime() const { return expireTime_; }

private:
	std::shared_ptr<Runnable> runnable_;
	STATE state_;
	int64_t expireTime_;
};


