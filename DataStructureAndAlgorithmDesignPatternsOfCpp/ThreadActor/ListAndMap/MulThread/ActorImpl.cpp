#include "ActorImpl.h"
#include "Actor.h"
#include <functional>

#ifndef _THREAD_OS_LINUX_
	static unsigned long __cdecl ThreadFunc(void* ptr)
	{
		ActorImpl* pImpl = (ActorImpl*)ptr;
		pImpl->svc();
		return 0;
	}
#else // Linux system
	static void* ThreadFunc(void* ptr)
	{
		ActorImpl* pImpl = (ActorImpl*)ptr;
		pImpl->svc();
		return NULL;
	}
#endif

ActorImpl::ActorImpl(const char* ptName, Actor* pActor):
	m_pActor(pActor),m_bSpawned(false),m_bStarted(false),
	m_oStartSemaphore(1),m_oTerminateSemaphore(1),
	m_iStackSize(1024*128),m_iPriority(10)
{


}

ActorImpl::~ActorImpl(void)
{
#ifndef _THREAD_OS_LINUX_
	TerminateThread();
#else
	void* thread_result;
	if (m_bStarted)
	{
		pthread_cancel(m_Thread);
		pthread_join(m_Thread, &thread_result);
	}
#endif	
}

bool ActorImpl::Start(void)
{
#ifdef _THREAD_OS_LINUX_
	if (0 != m_Thread(&m_Thread, NULL, ThreadFunc, this))
	{
		return false;
	}
	m_bStarted = true;
	return true;
#else
	m_pThread = std::thread(std::bind(ThreadFunc, this));
	
	{
		m_bSpawned = true;
		SetPriority(m_iPriority);
	}

	m_bStarted = m_bSpawned;
	return m_bStarted;
#endif
}

bool ActorImpl::Suspend(void)
{
	return false;
}

void ActorImpl::svc(void)
{
	// No wait
	m_oTerminateSemaphore.Wait(-1);

	// Wait for start semaphore, make sure the thread is started
	m_oStartSemaphore.Wait(-1);

	if (m_pActor != NULL)
	{
		m_pActor->svc();
	}

	m_bSpawned = false;
	m_bStarted = false;

}

bool ActorImpl::Kill(void)
{
	if (m_bStarted)
	{	
		m_pThread.join();					
	}
	return true;
}

void ActorImpl::SetPriority(int64_t iPriority)
{
	m_iPriority = iPriority;
}

bool ActorImpl::IsRunning(void)
{
	return m_bStarted;
}

void ActorImpl::WaitForTermination(bool bEnforceKill, int64_t iTimeout)
{
	if (!IsRunning())
	{
		return;
	}

	if (m_oTerminateSemaphore.Wait(iTimeout))
	{
		m_oTerminateSemaphore.Trigger();
	}
	else
	{
		if (bEnforceKill && IsRunning())
		{
			Kill();
		}
	}
}

void ActorImpl::TerminateThread(void)
{
	if (IsRunning())
	{
		Kill();
	}
}


