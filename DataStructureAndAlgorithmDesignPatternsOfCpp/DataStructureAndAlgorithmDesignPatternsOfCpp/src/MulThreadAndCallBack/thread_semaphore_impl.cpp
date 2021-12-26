#include "MulThreadAndCallBack/thread_semaphore_impl.h"

#ifdef _THREAD_OS_LINUX_
#include <time.h>
#endif

namespace thread {
	SemaphoreImpl::SemaphoreImpl(int64_t iCount, int64_t iMaxCount)
#ifdef _THREAD_OS_LINUX_
		:m_iCount(iCount),m_iMaxCount(iMaxCount)
#endif
	{
#ifndef _THREAD_OS_LINUX_
		m_oSemaphore = CreateSemaphore(0, iCount, iMaxCount, 0);
#else
		sem_init(&m_oSemaphore, 0, iCount);
#endif

	}

	SemaphoreImpl::~SemaphoreImpl(void)
	{
#ifndef _THREAD_OS_LINUX_
		CloseHandle(m_oSemaphore);
#else
		sem_destroy(&m_oSemaphore);
#endif
	}

	bool SemaphoreImpl::Acquire(int64_t iTimeout)
	{
		bool bRet = false;
#ifndef _THREAD_OS_LINUX_
		switch (iTimeout)
		{
			//Wait forver
		case -1:
			bRet = WaitForSingleObject(static_cast<HANDLE>(m_oSemaphore), INFINITE) == 0x00000000L;
			break;
			// no wait
		case 0:
			bRet = WaitForSingleObject(static_cast<HANDLE>(m_oSemaphore), 0) == 0x00000000L;
			break;

			//wait for timeout 
		default:
			bRet = WaitForSingleObject(static_cast<HANDLE>(m_oSemaphore), iTimeout) ;
			break;
		}
#else
		struct timespec oTimeSpec;
		switch (iTimeout)
		{
		case -1:
			bRet = sem_wait(const_cast<sem_t*>(&m_oSemaphore)) == 0;
			break;
			//²»µÈ
		case 0:
			bRet = sem_trywait(const_cast<sem_t*>(&m_oSemaphore)) == 0;
			break;
		default:
			if (clock_gettime(CLOCK_REALTIME, &oTimeSpec) == 0)
			{
				// Calc the timeout time
				int64_t iTime = oTimeSpec.tv_nsec + iTimeout * 1000000;
				oTimeSpec.tv_sec += iTime / 1000000000;
				oTimeSpec.tv_nsec = iTime % 1000000000;
				bRet = (0 == sem_timedwait(&m_oSemaphore, &oTimeSpec));
			}
			break;
		}
		if (bRet)
		{
			--m_iCount;
		}
#endif
		return bRet;
	}

	bool SemaphoreImpl::Release(void)
	{
#ifndef _THREAD_OS_LINUX_
		return ReleaseSemaphore(static_cast<HANDLE>(m_oSemaphore), 1, 0) != 0;
#else
		bool bRet = false;
		if (m_iCount<m_iMaxCount)
		{
			++m_iCount;
			bRet = sem_wait(&m_oSemaphore) == 0;
		}
		return bRet;
#endif

	}

}