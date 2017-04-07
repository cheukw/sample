

#pragma once

#ifndef IINTERFACEMGR_H
#define IINTERFACEMGR_H

class IModule;

class IInterfaceMgr
{
public:
	virtual ~IInterfaceMgr(){};
	/*
	 注册模块到IInterfaceMgr中
	 @name		模块名，要求是静态字符串，每个IModule的实现都必须声明一个静态字符串名，以字符串首地址来作为该模块的标识符
	 @module	被注册的模块
	 @Return	是否注册成功
	*/
	virtual bool RegisterModule(const char* name, IModule *module)=0;

	/*
	 查询模块
	 @name		模块名，静态字符串，必须使用注册时候的静态字符串
	 @Return	模块指针，查询失败则放回0
	*/
	virtual IModule* QueryModule(const char* name)=0;


	/*
	 阻塞运行至停止
	 @loop_interval 每次循环间隙时间
	 @work_path		游戏运行目录
	*/
	virtual void Run(unsigned long loop_interval)=0;
	
	/*
	 停止游戏
	*/
	virtual void Stop()=0;

	/*
	 获得游戏运行目录
	*/
	virtual int GetWorkPath(char *path, int max_len)const=0;

	/*
	 运行游戏，非阻塞，需循环调用
	 @return 返回游戏运行状态
	*/
	enum GameState
	{
		GS_STOP = 0,
		GS_RUNNING,
		GS_STOPPING,
	};
	virtual int Update()=0;
};

#endif
