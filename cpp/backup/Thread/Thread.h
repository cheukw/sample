#pragma once

#include <thread>
#include <memory>
#include "Runnable.h"

class Thread 
	: public std::enable_shared_from_this<Thread>
{
public:
	enum class STATE { 
		UNINITIALIZED, 
		STARTING, 
		STARTED, 
		JOINING, 
		STOPPING, 
		STOPPED 
	};

	typedef std::thread::id tid_t;

	explicit Thread(bool detached, std::shared_ptr<Runnable>& runnable);
	~Thread();

	static inline bool is_current(tid_t t) { return t == std::this_thread::get_id(); }
	static inline std::thread::id get_current() { return std::this_thread::get_id(); }

	void start();

	void join();

	tid_t getId();

	std::shared_ptr<Runnable> runnable() const;
protected:
	void runnable(std::shared_ptr<Runnable>& r);
	static void threadMain(std::shared_ptr<Thread>& t);
private:
	std::shared_ptr<Runnable> runnable_;

	std::unique_ptr<std::thread> thread_;
	STATE state_ = STATE::UNINITIALIZED;
	bool detached_ = false;
};