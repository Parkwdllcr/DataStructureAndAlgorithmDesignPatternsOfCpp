#pragma once

#include <stdint.h>
#include "thread_os_define.h"

namespace thread {
	class SemaphoreImpl;
	class THREAD_EXPORT Semaphore
	{
	public:
		Semaphore(int64_t iCount = 1, int64_t iMaxCout = 0x7FFFFFFF);
		virtual ~Semaphore(void);
		bool Acquire(int64_t iTimeout = -1);
		bool Release(void);

	private:
		SemaphoreImpl* m_pImpl;
	};

}