
#include <map>
#include <thread>
#include <mutex>
#include <cassert>
#include "net/inner_pre.h"
#include "net/libevent_headers.h"

#ifndef _WIN32
struct OnStartup {
	OnStartup() {
#ifndef H_OS_WINDOWS
		if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
			exit(-1);
		}
#endif
	}
	~OnStartup() {
	}
} __s_onstartup;
#endif 

#ifdef _DEBUG
static std::map<struct event*, std::thread::id> evmap;
static std::mutex mutex;
#endif

int EventAdd(struct event* ev, const struct timeval* timeout) {
#ifdef _DEBUG
	{
		std::lock_guard<std::mutex> guard(mutex);
		if (evmap.find(ev) == evmap.end()) {
			auto id = std::this_thread::get_id();
			evmap[ev] = id;
		}
		else {
			assert("event_add twice");
		}
	}
#endif
	return event_add(ev, timeout);
}

int EventDel(struct event* ev) {
#ifdef _DEBUG
	{
		std::lock_guard<std::mutex> guard(mutex);
		auto it = evmap.find(ev);
		if (it == evmap.end()) {
			assert("event_del twice");
		}
		else {
			auto id = std::this_thread::get_id();
			if (id != it->second) {	
				assert(it->second == id);
			}
			evmap.erase(it);
		}
	}
	
#endif
	return event_del(ev);
}

int GetActiveEventCount() {
#ifdef _DEBUG
	return static_cast<int>(evmap.size());
#else
	return 0;
#endif
}