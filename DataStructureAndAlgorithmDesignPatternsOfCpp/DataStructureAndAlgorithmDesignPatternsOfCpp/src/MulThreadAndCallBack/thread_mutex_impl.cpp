#include "thread_mutex_impl.h"

namespace thread {

	MutexImpl::MutexImpl(void):m_bLocked(false)
	{
#ifndef _THREAD_OS_LINUX_
		InitializeCriticalSection(&m_oMutex);
#else
		pthread_mutexattr_t oAttr;
		pthread_mutexattr_init(&oAttr);
		pthread_mutexatter_settype(&oAttr, PTHREAD_MUTEX_RECURSIVE);
		pthread_mutex_init(&m_oMutex, &oAttr);
		pthread_mutexattr_destroy(&oAttr);
#endif
	}

	MutexImpl::~MutexImpl(void)
	{
#ifndef _THREAD_OS_LINUX_
		DeleteCriticalSection(&m_oMutex);
#else
		pthread_mutex_unlock(&m_oMutex);
		pthread_mutex_destroy(&m_oMutex);
#endif
	}

	bool MutexImpl::Lock(void)
	{
		m_bLocked = true;
#ifndef _THREAD_OS_LINUX_
		EnterCriticalSection(&m_oMutex);
		return true;
#else
		return pthread_mutex_lock(&m_oMutex) == 0;
#endif
	}

	bool MutexImpl::LockTry(void)
	{
		m_bLocked = true;
#ifndef _THREAD_OS_LINUX_
		return TryEnterCriticalSection(&m_oMutex);
#else
		return pthread_mutex_trylock(&m_oMutex) == 0;
#endif
	}

	bool MutexImpl::UnLock(void)
	{
		m_bLocked = false;
#ifndef _THREAD_OS_LINUX_
		LeaveCriticalSection(&m_oMutex);
		return true;
#else
		return pthread_mutex_unlock(&m_oMutex) == 0;
#endif
	}

}