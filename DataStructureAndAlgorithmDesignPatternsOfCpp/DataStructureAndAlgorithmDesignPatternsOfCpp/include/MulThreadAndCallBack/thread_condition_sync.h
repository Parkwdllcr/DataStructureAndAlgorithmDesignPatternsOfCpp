
#pragma once

#include "thread_os_define.h"
#include "thread_semaphore.h"
#include "thread_mutex.h"

// namespace
namespace thread {

class THREAD_EXPORT ConditionSync
{
public:

    ConditionSync(void);
    virtual ~ConditionSync(void);
    bool Wait(int64_t iTimeout = -1);
    void Signal(bool bCondition = true);
    int64_t Broadcast(bool bCondition = true);

private:

    bool m_bCondition;
    int64_t m_iNumOfPendings;
    CSemaphore m_oSemaphore;
    CMutex m_oMutex;
};

} 


