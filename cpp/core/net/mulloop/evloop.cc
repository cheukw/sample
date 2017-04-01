#include "evloop.h"

EvLoop::EvLoop() {

}

EvLoop::~EvLoop() {

}

bool EvLoop::Run() {
	tid_ = std::this_thread::get_id();
	return true;
}

void EvLoop::Stop() {

}