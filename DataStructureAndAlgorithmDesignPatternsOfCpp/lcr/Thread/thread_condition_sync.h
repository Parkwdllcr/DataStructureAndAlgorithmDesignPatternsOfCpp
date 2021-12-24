//////////////////////////////////////////////////////////////////////////
///  defgroup ThreadUtils
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
#pragma once

#include "thread_os_define.h"
#include "thread_semaphore.h"
#include "thread_mutex.h"

// namespace
namespace thread {

/// \class Actor umr_actor.h
/// \brief the implementation of the Condition
///
///
/// \par  Usage of this class:
/// \code
///  ConditionSync oCondition;
///  oCondition.Wait(100);
///  oCondition.Broadcast();
/// \code
////
class THREAD_EXPORT ConditionSync
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief constructor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    ConditionSync(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief deconstructor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~ConditionSync(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Start a thread
    ///
    ///  \param[in]    iTimeout: -1 - wait forever, other wait for the time
    ///  \param[out]   None
    ///  \return       bool: the resulte of starting the thread
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Wait(int64_t iTimeout = -1);

    /////////////////////////////////////////////////////////////////
    ///  \brief Signal a waitting client
    ///
    ///  \param[in]    bCondition:
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    void Signal(bool bCondition = true);

    /////////////////////////////////////////////////////////////////
    ///  \brief Signal all the waitting clients
    ///
    ///  \param[in]    bCondition:
    ///  \param[out]   None
    ///  \return       int32_t: the number of the clients released
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    int64_t Broadcast(bool bCondition = true);

private:

    bool m_bCondition;
    int64_t m_iNumOfPendings;
    CSemaphore m_oSemaphore;
    CMutex m_oMutex;
};

} // namespace


