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
	Update();
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