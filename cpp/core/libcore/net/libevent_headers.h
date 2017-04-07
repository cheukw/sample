/********************************************************************
 *  Created:    2014/03/06 14:19
 *  File name:  libevent_headers.h
 *  Author:     weizili
 *  Purpose:
 *
 *  Copyright 2010-2013, All Rights Reserved.
 ********************************************************************/
#pragma once

#if defined(_WIN32) || defined(_WIN64)
#include <winsock2.h>
#else
#include <sys/queue.h>
#endif

#include <event2/event.h>
#include <event2/event_struct.h>
#include <event2/buffer.h>
#include <event2/bufferevent.h>
#include <event2/http.h>
#include <event2/http_compat.h>
#include <event2/http_struct.h>
#include <event2/event_compat.h>
#include <event2/dns.h>
#include <event2/dns_compat.h>
#include <event2/dns_struct.h>
#include <event2/listener.h>
#ifdef _DEBUG
#if LIBEVENT_VERSION_NUMBER >= 0x02010500
#define  ev_arg ev_evcallback.evcb_arg
#endif // LIBEVENT_VERSION_NUMBER
#endif // _DEBUG


#ifndef evtimer_new
#define evtimer_new(b, cb, arg)        event_new((b), -1, 0, (cb), (arg))
#endif

