//////////////////////////////////////////////////////////////////////////
///
///  Copyright, (c) Shanghai United Imaging Health_care Inc., 2011
///  All rights reserved.
///
///  \author   Shi Yaoming  yaoming.shi@united-imaging.com
///
///  \file    umr_semaphore_ace_impl.h
///  \brief
///
///  \version 1.0
///  \date    Sep.15, 2011
///
///  \ChangedBy       NO
///  \ChangedDate     NO
///  \ChangedContent  NO
//////////////////////////////////////////////////////////////////////////

#ifndef UMR_SEMAPHORE_IMPL_H_
#define UMR_SEMAPHORE_IMPL_H_

#include "ThreadUtils/threadutils_os_type.h"

#ifndef _THREADUTILS_OS_LINUX_
#include <windows.h>
#else
#include <semaphore.h>
#endif


// namespace
namespace threadutils {

    /// \class SemaphoreImpl umr_semaphore_ace_impl.h
    /// \brief Implementation of the Semaphore with ACE
    ///
    ///
    /// \par  Usage of this class:
    /// \code
    /// \code
    ////
class SemaphoreImpl
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief Constructor, Create a instance of the ACE Semaphore Implementation
    ///
    ///  \param[in]    iCount: the times of the semaphore being acqired
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    SemaphoreImpl(int64_t iCount = 1, int64_t iMaxCount = 0x7FFFFFFF);

    /////////////////////////////////////////////////////////////////
    ///  \brief Deconstructor, Release the instance
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~SemaphoreImpl( void );

    /////////////////////////////////////////////////////////////////
    ///  \brief Acquire the ACE Semaphore, continue if get the semaphore
    ///
    ///  \param[in]    iTimeout: ms. -1 forever waitting; 0 no waitting;
    ///  \param[out]   None
    ///  \return       bool: true if get the semaphore;false if fail or timeout
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Acquire(int64_t iTimeout);

    /////////////////////////////////////////////////////////////////
    ///  \brief Release the Semaphore
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Release(void);

private:

#ifndef _THREADUTILS_OS_LINUX_
    HANDLE m_oSemaphore; /**< Win semaphore*/
#else
    sem_t m_oSemaphore; /**< Posix semaphore*/
    int64_t m_iMaxCount;
    int64_t m_iCount;
#endif
};

} // namespace

#endif // UMR_SEMAPHORE_ACE_IMPL_H_
