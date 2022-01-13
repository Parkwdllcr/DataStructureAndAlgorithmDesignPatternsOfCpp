#pragma once
#include "thread_os_define.h"
#include "thread_semaphore.h"
//这个boost库可以使用c++11之后的标准来替代
//#include <boost/thread/thread.hpp>
//#include <boost/bind.hpp>
#include<thread>
#ifndef _THREAD_OS_LINUX_
#else
#include <pthread.h>
#endif


class Actor;
class ActorImpl
{
public:
	ActorImpl(const char* ptName, Actor* pActor);
	virtual ~ActorImpl(void);

	bool Start(void);
	bool Suspend(void);
	bool Kill(void);
	void SetPriority(int64_t iPriority);
	bool IsRunning(void);
	void WaitForTermination(bool bEnforceKill, int64_t iTimeout);
	void TerminateThread(void);
	virtual void svc(void);
protected:
	Actor* m_pActor;
private:
	bool m_bStarted;
#ifndef _THREAD_OS_LINUX_
	bool m_bSpawned;
	int64_t m_iPriority;
	int64_t m_iStackSize;
	CSemaphore m_oStartSemaphore;
	CSemaphore m_oTerminateSemaphore;
	//std::thread  m_pThread;
	std::thread m_pThread;
#else
	pthread_t m_Thread;
#endif
		
};
