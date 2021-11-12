//////////////////////////////////////////////////////////////////////////
///
///  Copyright, (c) Shanghai United Imaging Health_care Inc., 2011
///  All rights reserved.
///
///  \author   Shi Yaoming  yaoming.shi@united-imaging.com
///
///  \file    umr_mutex_ace_impl.cpp
///  \brief
///
///  \version 1.0
///  \date    Sep.15, 2011
///
///  \ChangedBy       NO
///  \ChangedDate     NO
///  \ChangedContent  NO
//////////////////////////////////////////////////////////////////////////
#include "umr_mutex_impl.h"

// namespace
namespace threadutils {

MutexImpl::MutexImpl(void) : m_bLocked(false)
{
#ifndef _THREADUTILS_OS_LINUX_
    InitializeCriticalSection(&m_oMutex);
#else
    pthread_mutexattr_t oAttr;
    pthread_mutexattr_init(&oAttr);
    pthread_mutexattr_settype(&oAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&m_oMutex, &oAttr);
    pthread_mutexattr_destroy(&oAttr);
#endif
}

MutexImpl::~MutexImpl( void )
{
#ifndef _THREADUTILS_OS_LINUX_
    DeleteCriticalSection(&m_oMutex);
#else
    pthread_mutex_unlock(&m_oMutex);
    pthread_mutex_destroy(&m_oMutex);
#endif
}

/////////////////////////////////////////////////////////////////
///  \brief Acquire the mutex, continue if get the mutex
///
///  \param[in]    None
///  \param[out]   None
///  \return       None
///  \pre \e
/////////////////////////////////////////////////////////////////
bool MutexImpl::Acquire(void)
{
    m_bLocked = true;
#ifndef _THREADUTILS_OS_LINUX_
    EnterCriticalSection(&m_oMutex);
    return true;
#else
    return pthread_mutex_lock(&m_oMutex) == 0;
#endif
}


bool MutexImpl::TryAcquire(void)
{
    m_bLocked = true;
#ifndef _THREADUTILS_OS_LINUX_
    return TryEnterCriticalSection(&m_oMutex);
#else
    return pthread_mutex_trylock(&m_oMutex) == 0;
#endif
}

/////////////////////////////////////////////////////////////////
///  \brief Release the mutex
///
///  \param[in]    None
///  \param[out]   None
///  \return       None
///  \pre \e
/////////////////////////////////////////////////////////////////
bool MutexImpl::Release(void)
{
    m_bLocked = false;
#ifndef _THREADUTILS_OS_LINUX_
    LeaveCriticalSection(&m_oMutex);
    return true;
#else
    return pthread_mutex_unlock(&m_oMutex) == 0;
#endif
}

} // namespace
