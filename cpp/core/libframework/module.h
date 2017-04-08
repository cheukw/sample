
#pragma once

#ifndef IMODULE_H__
#define IMODULE_H__
#include <memory>
#include "interfacemgr.h"



class Module
{
public:
	enum {
		Succeed = 0,
		Fail,
		Pending,
	};
	enum {
		ST_Init,
		ST_Start,
		ST_Update,
		ST_Stop,
		ST_Release,
		ST_Fail,
	};

	Module(): interface_mgr_(0), module_state_(ST_Release){}
	
	virtual int Init() = 0;
	virtual int Start() = 0;
	virtual int Update() = 0;
	virtual int Stop() = 0;
	virtual int Release() = 0;
	virtual void Free() = 0;

	int GetState()const{ return module_state_;}
protected:
	virtual ~Module(){}
	InterfaceMgr* Interface(){ return interface_mgr_; }
private:
	InterfaceMgr* interface_mgr_;
	int module_state_;
};
typedef std::shared_ptr<Module> ModulePtr;

#endif /// IMODULE_H__

