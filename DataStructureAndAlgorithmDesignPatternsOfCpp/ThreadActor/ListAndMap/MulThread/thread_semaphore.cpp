
#include "thread_semaphore.h"




	CSemaphore::CSemaphore(int64_t iCount /*= 1*/, int64_t iMaxCout /*= 0x7FFFFFFF*/) 
	{
		//m_pImpl = new SemaphoreImpl(iCount, iMaxCout);
	}



	CSemaphore::~CSemaphore(void)
	{
		/*if (nullptr != m_pImpl)
		{
			delete m_pImpl;
			m_pImpl = nullptr;
		}*/
	}

	bool CSemaphore::Wait(int64_t iTimeout /*= -1*/)
	{
		//if (nullptr != m_pImpl)
		{
			return m_pImpl.Acquire(iTimeout);
		}
		return false;
		
	}

	bool CSemaphore::Trigger()
	{
		//if (nullptr != m_pImpl)
		{
			return m_pImpl.Release();
		}
		return false;
	}


