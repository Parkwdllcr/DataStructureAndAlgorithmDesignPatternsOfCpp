#include "Actor.h"
#include "CThread.h"

unsigned long  ThreadFunc(void* ptr)
{
	Actor* pActor = (Actor*)ptr;
	pActor->svc();
	return 0;
}

Actor::Actor(std::string strName, CThread* pThread):
	m_strMyName(strName), m_bSpawned(false), m_bStarted(false),
	m_oStartSemaphore(strName), m_oTerminateSemaphore(strName), m_pCthread(pThread),
	m_iStackSize(1024 * 128), m_iPriority(10),m_Thread()
{

}

Actor::~Actor(void)
{
	TerminateThread();
}

bool Actor::Start(void)
{
	try
	{
		std::thread temThread(ThreadFunc, this);
		m_Thread = std::thread(ThreadFunc, this);
		m_bStarted = m_bSpawned;
		if (m_bStarted)
		{
			m_oStartSemaphore.Trigger();
		}
		return m_bStarted;
	}
	catch (...)
	{
		m_bSpawned = true;
		SetPriority(m_iPriority);
		return false;
	}
	
}

bool Actor::Suspend(void)
{
	return true;
}

bool Actor::Kill(void)
{
	try
	{
		if (m_bStarted)
		{
			m_Thread.join();
		}
		m_bSpawned = false;
		m_bStarted = false;
		m_oStartSemaphore.Trigger();
		m_oTerminateSemaphore.Trigger();
		return true;
	}
	catch (...)
	{
		return false;	
	}
	
}

void Actor::SetPriority(int64_t iPriority)
{
	m_iPriority = iPriority;
}

bool Actor::IsRunning(void)
{
	return m_bStarted;
}

void Actor::WaitForTermination(bool bEnforceKill, int64_t iTimeout)
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

void Actor::TerminateThread(void)
{
	if (IsRunning())
	{
		Kill();
	}
}

std::string Actor::GetThreadName()
{
	return m_strMyName;
}

void Actor::svc()
{
	// No wait
	m_oTerminateSemaphore.Wait(-1);

	// Wait for start semaphore, make sure the thread is started
	m_oStartSemaphore.Wait(-1);

	if (m_pCthread != nullptr)
	{
		m_pCthread->svc();
	}

	m_bSpawned = false;
	m_bStarted = false;

	// Release the start semaphore
	m_oStartSemaphore.Trigger();
	m_oTerminateSemaphore.Trigger();
}

