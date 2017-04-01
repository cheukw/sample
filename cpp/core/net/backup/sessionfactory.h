#pragma once
#ifndef _SESSION_FACTORY_H_
#define _SESSION_FACTORY_H_
#include "networkinterface.h"

class SessionFactory : public ISessionFactory
{
public:
	virtual SessionPtr CreateSession(const ConnectionPtr& conn) override;
private:

};

#endif /// _SESSION_FACTORY_H_
