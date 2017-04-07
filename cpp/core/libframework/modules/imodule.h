
#pragma once

#ifndef IMODULE_H
#define IMODULE_H

/*
	Game的流程将保证，	最先成功完成Init的Module，最后调用Release。
						最先成功完成Start的Module，最后调用Stop。
*/
#include "iinterfacemgr.h"	//每个模块都会使用


class IModule
{
	friend class Game;
public:
	enum
	{
		Succeed = 0,
		Fail,
		Pending,
	};
	enum
	{
		ST_Initing,
		ST_Inited,
		ST_Starting,
		ST_Started,
		ST_Updating,
		ST_Updated,
		ST_Stopping,
		ST_Stopped,
		ST_Releasing,
		ST_Released,
		ST_Fail,
	};
	IModule():interface_mgr_(0),module_state_(ST_Released){}
	
	virtual int Init()=0;
	virtual int Start()=0;
	virtual int Update()=0;
	virtual int Stop()=0;
	virtual int Release()=0;

	/* 此函数释放自己所占用的空间，调用此函数后，Game将不再使用此模块的指针 */
	virtual void Free()=0;

	int GetState()const{ return module_state_;}
protected:
	virtual ~IModule(){}
	IInterfaceMgr* Interface(){ return interface_mgr_; }
private:
	IInterfaceMgr* interface_mgr_;
	int module_state_;
};

#endif
