#pragma once

#include "CSemaphore.h"
#include <thread>
#include <string>

class CThread;

class  Actor
{
public:
	Actor(std::string strName,CThread *pThread);
	virtual ~Actor(void);

	bool Start(void);
	bool Suspend(void);
	bool Kill(void);
	void SetPriority(int64_t iPriority);
	bool IsRunning(void);
	void WaitForTermination(bool bEnforceKill, int64_t iTimeout);
	void TerminateThread(void);
	std::string  GetThreadName();
	virtual void svc() ;
protected:
	CThread* m_pCthread;
private:
	std::string             m_strMyName;
	bool                    m_bStarted;
	bool                    m_bSpawned;
	int64_t                 m_iPriority;
	int64_t                 m_iStackSize;
	CSemaphore              m_oStartSemaphore;
	CSemaphore              m_oTerminateSemaphore;
	std::thread             m_Thread;
};