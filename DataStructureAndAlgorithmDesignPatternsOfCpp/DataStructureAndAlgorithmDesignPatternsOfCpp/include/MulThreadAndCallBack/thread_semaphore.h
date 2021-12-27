#pragma once

#include <stdint.h>
#include "thread_os_define.h"

namespace BaseCPrimerPlus {
	class SemaphoreImpl;
	class THREAD_EXPORT CSemaphore
	{
	public:
		CSemaphore(int64_t iCount = 1, int64_t iMaxCout = 0x7FFFFFFF);
		virtual ~CSemaphore(void);
		bool  Wait(int64_t iTimeout = -1);
		bool     Trigger();
		/*bool Acquire(int64_t iTimeout = -1);
		bool Release(void);*/

	private:
		SemaphoreImpl* m_pImpl;
	};

}