#include "MulThreadAndCallBack/ActorImpl.h"
#include "MulThreadAndCallBack/Actor.h"

namespace thread {

#if defined( WIN32 ) || defined( WIN64 ) || defined( X64 )
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
		m_oStartSemaphore(1),m_oTerminateSemaphore(1),m_pThread(nullptr),
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
		if (0 !=    (&m_Thread, NULL, ThreadFunc, this))
		{
			return false;
		}
		m_bStarted = true;
		return true;
#else
		m_pThread = new boost::thread(boost::bind(&ThreadFunc, this));

		if (nullptr != m_pThread)
		{
			m_bSpawned = true;
			SetPriority(m_iPriority);
		}

		m_bStarted = m_bSpawned;

		if (m_bStarted)
		{
			m_oStartSemaphore.Release();
		}

		return m_bStarted;
#endif
	}

	void ActorImpl::svc(void)
	{
		// No wait
		m_oTerminateSemaphore.Acquire(-1);

		// Wait for start semaphore, make sure the thread is started
		m_oStartSemaphore.Acquire(-1);

		if (m_pActor != NULL)
		{
			m_pActor->svc();
		}

		m_bSpawned = false;
		m_bStarted = false;

		// Release the start semaphore
		m_oStartSemaphore.Release();
		m_oTerminateSemaphore.Release();
	}

	bool ActorImpl::Kill(void)
	{
		bool bRet = true;

		if (m_bStarted)
		{
			if (m_pThread)
			{
				m_pThread->interrupt();
				delete m_pThread;
				m_pThread = NULL;
			}
		}

		if (bRet)
		{
			m_bSpawned = false;
			m_bStarted = false;
			m_oStartSemaphore.Release();
			m_oTerminateSemaphore.Release();
		}

		return bRet;
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

		if (m_oTerminateSemaphore.Acquire(iTimeout))
		{
			m_oTerminateSemaphore.Release();
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

}
