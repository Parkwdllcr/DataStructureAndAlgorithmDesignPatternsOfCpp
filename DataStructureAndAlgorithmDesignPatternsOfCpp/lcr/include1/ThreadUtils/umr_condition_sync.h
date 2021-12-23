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
#ifndef UMR_CONDITION_SYNC_H_
#define UMR_CONDITION_SYNC_H_

#include "ThreadUtils/threadutils_os_type.h"
#include "ThreadUtils/umr_semaphore.h"
#include "ThreadUtils/umr_mutex.h"

// namespace
namespace threadutils {

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
class THREADUTILS_EXPORT ConditionSync
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
    Semaphore m_oSemaphore;
    Mutex m_oMutex;
};

} // namespace

#endif // UMR_CONDITION_SYNC_H_
