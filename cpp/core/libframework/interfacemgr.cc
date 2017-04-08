#include <thread>
#include <chrono>
#include "interfacemgr.h"

InterfaceMgr::InterfaceMgr()
{

}

InterfaceMgr::~InterfaceMgr()
{

}

bool InterfaceMgr::RegisterModule(const std::string& name, const ModulePtr& module)
{
	auto iter = modules_.find(name);
	if (iter != modules_.end()) {
		return false;
	}
	modules_[name] = module;
	return true;
}

ModulePtr InterfaceMgr::QueryModule(const std::string& name)
{
	auto iter = modules_.find(name);
	if (iter != modules_.end()) {
		return iter->second;
	}
	return nullptr;
}

void InterfaceMgr::Run(unsigned long loop_interval)
{
	while (1) {
		if (Update() == MS_STOP) {
			break;
		}
		//std::this_thread::sleep_for(std::chrono::seconds * 1);
		//std::this_thread::sleep_for(std::chrono::milliseconds);
	}
	
}

void InterfaceMgr::Stop()
{
	for (auto m : modules_) {
		m.second->Stop();
	}
}

int InterfaceMgr::Update()
{
	for (auto m: modules_) {
		if (m.second->Update() != MS_RUNNING) {

		}
	}
}