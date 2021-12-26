#include "MulThreadAndCallBack/thread_mutex.h"
#include "MulThreadAndCallBack/thread_mutex_impl.h"

#include <stdio.h>

namespace thread {

	CMutex::CMutex(void):m_pImpl(nullptr)
	{
		m_pImpl = new MutexImpl();
	}


	CMutex::~CMutex(void)
	{
		if (nullptr != m_pImpl)
		{
			delete m_pImpl;
			m_pImpl = nullptr;
		}
	}

	bool CMutex::Lock(void)
	{
		if (nullptr != m_pImpl)
		{
			return m_pImpl->Lock();
		}
		return false;
	}

	bool CMutex::LockTry(void)
	{
		if (nullptr != m_pImpl)
		{
			return m_pImpl->LockTry();
		}
		return false;
	}

	bool CMutex::UnLock(void)
	{
		if (nullptr != m_pImpl)
		{
			return m_pImpl->UnLock();
		}
		return false;
	}

}
