//////////////////////////////////////////////////////////////////////////
/// \defgroup ThreadUtils
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author  Shi Yao Ming  yaoming.shi@united-imaging.com
///
///  \file    umr_mutex.h
///  \brief   Define the Mutex class
///
///  \version 1.0
///  \date    Sep. 13, 2011
//////////////////////////////////////////////////////////////////////////
#ifndef UMR_MUTEX_H_
#define UMR_MUTEX_H_

#include "ThreadUtils/threadutils_os_type.h"

// namespace
namespace threadutils {

class MutexImpl;

/// \class Mutex umr_mutex.h
/// \brief Implementation of the Mutex
///
///
/// \par  Usage of this class:
/// \code
///  Mutex oMutex;
///  oMutex.Acquire();
///  oMutex.Release();
/// \code
////
class THREADUTILS_EXPORT Mutex
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief Constructor, Create a instance of the Mutex Implementation
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    Mutex(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Deconstructor, Release the instance
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~Mutex(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Acquire the mutex, continue if get the mutex
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
    MutexImpl* m_pImpl;
};

} // namespace

#endif // UMR_MUTEX_H_
