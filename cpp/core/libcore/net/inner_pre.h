#pragma once
#include "net/sockets.h"

#ifndef H_CASE_STRING_BIGIN
#define H_CASE_STRING_BIGIN(state) switch(state){
#define H_CASE_STRING(state) case state:return #state;break;
#define H_CASE_STRING_END()  default:return "Unknown";break;}
#endif

struct event;
int EventAdd(struct event* ev, const struct timeval* timeout);
int EventDel(struct event*);
int GetActiveEventCount();