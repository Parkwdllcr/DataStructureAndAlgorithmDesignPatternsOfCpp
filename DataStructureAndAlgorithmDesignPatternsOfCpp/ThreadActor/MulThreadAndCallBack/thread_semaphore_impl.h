#pragma once
#include "thread_os_define.h"
#include <stdint.h>

//实际上我添加了pthread库，也是可以用的
#ifndef _THREAD_OS_LINUX_
#include <windows.h>
#else
#include <semaphore.h>
#endif

namespace BaseCPrimerPlus {

	class SemaphoreImpl
	{
	public:
		SemaphoreImpl(int64_t iCount = 1, int64_t iMaxCount = 0x7FFFFFFF);
		virtual ~SemaphoreImpl(void);
		//请求时间
		bool Acquire(int64_t iTimeout);
		bool Release(void);
	private:
#ifndef _THREAD_OS_LINUX_
		HANDLE m_oSemaphore; /**< Win semaphore*/
#else
		sem_t m_oSemaphore; /**< Posix semaphore*/
		int64_t m_iMaxCount;
		int64_t m_iCount;
#endif

	};

}

