
#include "thread_condition_sync.h"

// namespace


ConditionSync::ConditionSync( void )
: m_bCondition(false), m_iNumOfPendings(0), m_oSemaphore(0)
{

}

ConditionSync::~ConditionSync( void )
{

}

bool ConditionSync::Wait(int64_t iTimeout)
{
    m_oMutex.Lock();

    bool bWait = !m_bCondition;

    if (bWait)
    {
        ++ m_iNumOfPendings;
    }

    m_oMutex.UnLock();

    bool bRet = true;

    if (bWait)
    {
        bRet = m_oSemaphore.Wait(iTimeout);

        if (! bRet)
        {
            m_oMutex.Lock();
            -- m_iNumOfPendings;
            m_oMutex.UnLock();
        }
    }

    return bRet;
}

void ConditionSync::Signal(bool bCondition)
{
    m_oMutex.Lock();

    m_bCondition = bCondition;
    if (m_bCondition)
    {
        if (m_iNumOfPendings > 0)
        {
            //if there is thread pending, release it
            //NOTE: if there are more than one thread, the sequence of release rely on OS schedule scheme
            m_oSemaphore.Trigger();
            -- m_iNumOfPendings;
        }
    }

    m_oMutex.UnLock();
}

int64_t ConditionSync::Broadcast(bool bCondition)
{
    int64_t iNumOfPendings = m_iNumOfPendings;

    m_oMutex.Lock();

    m_bCondition = bCondition;
    if (m_bCondition)
    {
        for (; m_iNumOfPendings > 0; -- m_iNumOfPendings)
        {
            m_oSemaphore.Trigger();
        }
    }

    m_oMutex.UnLock();

    return iNumOfPendings;
}


