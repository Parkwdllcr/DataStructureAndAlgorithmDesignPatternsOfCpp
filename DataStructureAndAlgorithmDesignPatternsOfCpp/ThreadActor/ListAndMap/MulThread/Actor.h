#pragma once

#include "thread_os_define.h"
#include <stdio.h>
#include <stdint.h>

class ActorImpl;

class THREAD_EXPORT Actor
{
public:
	Actor(const char* ptName = NULL);
	virtual ~Actor();
	bool Start();
	bool Suspend(void);
	bool Kill(void);
	virtual void WaitForTermination(bool bEnforceKill, int64_t iTimeout);
	virtual void TerminateThread(void);
	void SetPriority(int64_t iPriority);
	virtual void svc() = 0;
private:
	ActorImpl* m_pImpl;

};


