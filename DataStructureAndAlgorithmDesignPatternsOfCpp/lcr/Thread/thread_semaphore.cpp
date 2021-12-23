#include "thread_semaphore.h"
#include "thread_semaphore_impl.h"

namespace thread
{

	Semaphore::Semaphore(int64_t iCount /*= 1*/, int64_t iMaxCout /*= 0x7FFFFFFF*/):m_pImpl(nullptr)
	{
		m_pImpl = new SemaphoreImpl(iCount, iMaxCout);
	}



	Semaphore::~Semaphore(void)
	{
		if (nullptr != m_pImpl)
		{
			delete m_pImpl;
			m_pImpl = nullptr;
		}
	}

	bool Semaphore::Acquire(int64_t iTimeout /*= -1*/)
	{
		if (nullptr == m_pImpl)
		{
			return false;
		}
		return m_pImpl->Acquire(iTimeout);
	}

	bool Semaphore::Release(void)
	{
		if (nullptr == m_pImpl)
		{
			return false;
		}
		return m_pImpl->Release();
	}
}


