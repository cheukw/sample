#pragma once
#ifndef INTERFACEMGR_H__
#define INTERFACEMGR_H__
#include <memory>
#include <string>
#include <unordered_map>
#include "module.h"

class InterfaceMgr
{
public:
	InterfaceMgr();
	~InterfaceMgr();

	bool RegisterModule(const std::string& name, const ModulePtr& module);

	ModulePtr QueryModule(const std::string& name);

	void Run(unsigned long loop_interval);
	
	void Stop();

	enum Module_State {
		MS_STOP = 0,
		MS_RUNNING,
		MS_STOPPING,
	};
	int Update();

private:
	std::unordered_map<std::string, ModulePtr> modules_;
};

#endif /// INTERFACEMGR_H__

