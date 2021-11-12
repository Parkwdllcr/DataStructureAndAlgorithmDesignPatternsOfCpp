//////////////////////////////////////////////////////////////////////////
/// \defgroup ThreadUtils
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author  Shi Yao Ming  yaoming.shi@united-imaging.com
///
///  \file    umr_semaphore.h
///  \brief   Define the Semaphore class
///
///  \version 1.0
///  \date    Sep. 13, 2011
//////////////////////////////////////////////////////////////////////////
#ifndef UMR_SEMAPHORE_H_
#define UMR_SEMAPHORE_H_

#include <stdint.h>

#include "ThreadUtils/threadutils_os_type.h"

// namespace
namespace threadutils {

class SemaphoreImpl;

/// \class Semaphore umr_semaphore.h
/// \brief Implementation of the Semaphore
///
///
/// \par  Usage of this class:
/// \code
///  Semaphore oSemaphore;
///  oSemaphore.Acquire();
///  oSemaphore.Release();
/// \code
////
class THREADUTILS_EXPORT Semaphore
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief Constructor, Create a instance of the Semaphore Implementation
    ///
    ///  \param[in]    iCount: the times of the semaphore being acqired
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    Semaphore(int64_t iCount = 1, int64_t iMaxCount = 0x7FFFFFFF);
    /////////////////////////////////////////////////////////////////
    ///  \brief Deconstructor, Release the instance
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~Semaphore( void );

    /////////////////////////////////////////////////////////////////
    ///  \brief Acquire the Semaphore, continue if get the Semaphore
    ///
    ///  \param[in]    iTimeout: ms. -1 forever waitting; 0 no waitting;
    ///  \param[out]   None
    ///  \return       bool: true if get the semaphore;false if fail or timeout
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Acquire(int64_t iTimeout = -1);

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
    ///< The implemetation for semaphore
    SemaphoreImpl* m_pImpl;
};

} // namespace

#endif // UMR_SEMAPHORE_H_
