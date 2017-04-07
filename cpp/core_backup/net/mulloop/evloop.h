#pragma once
#ifndef _EV_LOOP_H_
#define _EV_LOOP_H_
#include "common.h"


class EvLoop {
public:
	EvLoop();
	~EvLoop();

	EvLoop(const EvLoop&) = delete;
	EvLoop& operator=(const EvLoop&) = delete;

	bool Run();

	void Stop();
	
protected:
	std::thread::id tid_;

	struct event_base* ev_base_;

	evutil_socket_t pipe_[2];
};
#endif // _EV_LOOP_H_
