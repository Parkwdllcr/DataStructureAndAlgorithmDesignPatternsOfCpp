//////////////////////////////////////////////////////////////////////////
///
///  Copyright, (c) Shanghai United Imaging Health_care Inc., 2011
///  All rights reserved.
///
///  \author   Shi Yaoming  yaoming.shi@united-imaging.com
///
///  \file    umr_mutex_ace_impl.h
///  \brief
///
///  \version 1.0
///  \date    Sep.15, 2011
///
///  \ChangedBy       NO
///  \ChangedDate     NO
///  \ChangedContent  NO
//////////////////////////////////////////////////////////////////////////
#ifndef UMR_MUTEX_IMPL_H_
#define UMR_MUTEX_IMPL_H_

#include "ThreadUtils/threadutils_os_type.h"

#ifndef _THREADUTILS_OS_LINUX_
#include <windows.h>
#else
#include <pthread.h>
#endif

// namespace
namespace threadutils {

/// \class MutexImpl umr_mutex_ace_impl.h
/// \brief Implementation of the Mutex with ACE
///
///
/// \par  Usage of this class:
/// \code
/// \code
////
class MutexImpl
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief Constructor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    MutexImpl(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Deconstructor, Release the instance
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~MutexImpl(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Acquire the mutex
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Acquire(void);

    bool TryAcquire(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Relase the mutex
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Release( void );

private:
#ifndef _THREADUTILS_OS_LINUX_
    CRITICAL_SECTION m_oMutex; /**< Window mutex */
#else
    pthread_mutex_t m_oMutex; /**< posix mutex */
#endif
    bool m_bLocked;
};

} // namespace

#endif // UMR_MUTEX_ACE_IMPL_H_
