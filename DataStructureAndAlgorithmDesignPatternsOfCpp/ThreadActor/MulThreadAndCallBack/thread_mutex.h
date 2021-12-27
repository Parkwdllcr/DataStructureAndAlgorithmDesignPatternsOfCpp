#pragma once
#include "thread_os_define.h"

namespace BaseCPrimerPlus {
	class MutexImpl;

	class THREAD_EXPORT CMutex
	{
	public:
		CMutex(void);
		virtual ~CMutex(void);
		bool Lock(void);
		bool LockTry(void);
		bool UnLock(void);

	private:
		MutexImpl* m_pImpl;
	
	};

}