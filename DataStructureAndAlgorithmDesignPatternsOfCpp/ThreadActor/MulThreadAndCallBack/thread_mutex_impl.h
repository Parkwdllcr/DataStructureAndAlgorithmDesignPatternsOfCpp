#pragma once
#include "thread_os_define.h"

#ifndef _THREAD_OS_LINUX_
#include <windows.h>
#else
#include <pthread.h>
#endif

namespace BaseCPrimerPlus {

	class MutexImpl
	{
	public:
		MutexImpl(void);
		virtual ~MutexImpl(void);
		bool Lock(void);
		bool LockTry(void);
		bool UnLock(void);

	private:
#ifndef _THREAD_OS_LINUX_
		CRITICAL_SECTION m_oMutex;
#else
		pthread_mutex_t m_oMutex;
#endif
		bool m_bLocked;
	};
}