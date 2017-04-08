#pragma once

#include "interfacemgr.h"

class ServerApp
{
public:

	void Run(unsigned long loop_interval);

	int GetWorkPath(char *path, int max_len) const;
private:
	InterfaceMgr* inerface_mgr_;
};