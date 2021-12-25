//////////////////////////////////////////////////////////////////////////
///
///  Copyright, (c) Shanghai United Imaging Health_care Inc., 2011
///  All rights reserved.
///
///  \author   Shi Yaoming  yaoming.shi@united-imaging.com
///
///  \file    umr_command_queue.h
///  \brief
///
///  \version 1.0
///  \date    Sep.15, 2011
///
///  \ChangedBy       NO
///  \ChangedDate     NO
///  \ChangedContent  NO
//////////////////////////////////////////////////////////////////////////
#pragma once

#include <stdio.h>

#include "thread_mutex.h"
#include "thread_semaphore.h"

// namespace
namespace thread {

/// \class CommandQueue umr_command_queue.h
/// \brief Implementation of the CommandQueue
///
///
/// \par  Usage of this class:
/// \code
///  CommandQueue oQueue;
///  oQueue.SendCmd();
///  oQueue.GetCmd();
/// \code
////

template<class COMMAND, class RETURN, int64_t QUEUESIZE>
class CommandElement
{
public:
    CommandElement() : m_bSync(false), m_oSyncSemaphore(0), m_pReturn(NULL), m_pNextElement(NULL) {};
    virtual ~CommandElement() {};

    bool m_bSync;
    CSemaphore m_oSyncSemaphore;

    COMMAND m_oCmd;
    RETURN* m_pReturn;

    CommandElement* m_pNextElement;

#ifdef _DEBUG
    void PrintList()
    {
        CommandElement* pCurElement = this;
        //std::cout << "(thread id: " << __threadid() << ") ";
        while(pCurElement)
        {
            std::cout << pCurElement->m_oCmd << "->";
            pCurElement = pCurElement->m_pNextElement;
        }
        //std::cout << "#" << std::endl;
    }
#endif
};

template <class COMMAND, class RETURN, int64_t QUEUESIZE = 8>
class CommandQueue
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief Constructor, initalize the queue
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    CommandQueue(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Deconstructor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~CommandQueue(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Send a command object into the queue asynchronously
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       bool: the resulte of sending a command
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool SendCmd(const COMMAND& oCmd);

    /////////////////////////////////////////////////////////////////
    ///  \brief Get a command from the queue, the method will be blocked if no command
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       bool: the resulte of getting a command
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool GetCmd(COMMAND& rCmd,  int64_t iTimeout);

    /////////////////////////////////////////////////////////////////
    ///  \brief Send a command object into the queue synchronously
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       bool: the resulte of sending a command
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    RETURN SendSyncCmd(const COMMAND& oCmd, int64_t iTimeout);

    /////////////////////////////////////////////////////////////////
    ///  \brief Set the return data for a sync command
    ///
    ///  \param[in]    RETURN: return data
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    void SetRetun(const RETURN& oReturn);

    /////////////////////////////////////////////////////////////////
    ///  \brief Release the pending sync command
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    void FinishActiveSyncCmd(void);

    /////////////////////////////////////////////////////////////////
    ///  \brief Empty the Command in the queue
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    void Empty();

private:
    ///< The queue of the commands
    CommandElement<COMMAND, RETURN, QUEUESIZE> m_oCmdQueue[QUEUESIZE];

    CommandElement<COMMAND, RETURN, QUEUESIZE>* GetFreeElement();
    CommandElement<COMMAND, RETURN, QUEUESIZE>* GetReadyElement(int64_t iTimeout_ms);
    void FreeElement(CommandElement<COMMAND, RETURN, QUEUESIZE>* pElement);
    void ReadyElement(CommandElement<COMMAND, RETURN, QUEUESIZE>* pElement);

    ///< Mutex for accessing the queue
    CMutex m_oMutex;
    CSemaphore m_oFreeSemaphore;
    CSemaphore m_oReadySemaphore;

    CommandElement<COMMAND, RETURN, QUEUESIZE>* m_pFirstFreeElement;
    CommandElement<COMMAND, RETURN, QUEUESIZE>* m_pFirstReadyElement;
    CommandElement<COMMAND, RETURN, QUEUESIZE>* m_pActiveElement;

    //Number of pending threads which are waiting for the ReadySemaphore.
    int64_t m_iNumOfWaittingForReadySemaphore;
    //Number of pending threads which are waiting for the FreeSemaphore.
    int64_t m_iNumOfWaittingForFreeSemaphore;
};

template<class COMMAND, class RETURN, int64_t QUEUESIZE>
CommandQueue<COMMAND, RETURN, QUEUESIZE>::CommandQueue(void)
    : m_oFreeSemaphore(0),
    m_oReadySemaphore(0),
    m_pFirstFreeElement(NULL),
    m_pFirstReadyElement(NULL),
    m_pActiveElement(NULL),
    m_iNumOfWaittingForReadySemaphore(0),
    m_iNumOfWaittingForFreeSemaphore(0)
{
    for (int64_t i = 0; i < QUEUESIZE -1;  ++ i)
    {
        m_oCmdQueue[i].m_pNextElement = &m_oCmdQueue[i + 1];
    }

    m_pFirstFreeElement = &m_oCmdQueue[0];
}

template<class COMMAND, class RETURN, int64_t QUEUESIZE>
CommandQueue<COMMAND, RETURN, QUEUESIZE>::~CommandQueue(void)
{

}

/////////////////////////////////////////////////////////////////
///  \brief Send a command object into the queue asynchronously
///
///  \param[in]    None
///  \param[out]   None
///  \return       bool: the result of sending a command
///  \pre \e
/////////////////////////////////////////////////////////////////
template<class COMMAND, class RETURN, int64_t QUEUESIZE>
bool CommandQueue<COMMAND, RETURN, QUEUESIZE>::SendCmd(const COMMAND& oCmd)
{
    if (NULL == m_pFirstFreeElement)
    {
        return false;
    }
    CommandElement<COMMAND, RETURN, QUEUESIZE>* pElement = GetFreeElement();

    pElement->m_oCmd = oCmd;
    pElement->m_bSync = false;
    pElement->m_pReturn = NULL;

    ReadyElement(pElement);

    return true;
}

/////////////////////////////////////////////////////////////////
///  \brief Get a command from the queue, the method will be blocked if no command
///
///  \param[in]    iTimeout: wait timeout
///  \param[out]   CmdDataBase: The command object pointer
///  \return       bool: the resulte of getting a command
///  \pre \e
/////////////////////////////////////////////////////////////////
template<class COMMAND, class RETURN, int64_t QUEUESIZE>
bool CommandQueue<COMMAND, RETURN, QUEUESIZE>::GetCmd(COMMAND& oCmd,  int64_t iTimeout)
{
    // Release the last sync command
    FinishActiveSyncCmd();

    CommandElement<COMMAND, RETURN, QUEUESIZE>* pElement = GetReadyElement(iTimeout);
    if (NULL == pElement)
    {
        return false;
    }

    oCmd = pElement->m_oCmd;
    if (pElement->m_bSync)
    {
        m_pActiveElement = pElement;
    }
    else
    {
        FreeElement(pElement);
    }
    return true;
}

/////////////////////////////////////////////////////////////////
///  \brief Send a command object into the queue synchronously
///
///  \param[in]    CmdDataBase: The command object
///  \param[in]    iTimeout: wait timeout
///  \param[out]   None
///  \return       bool: the resulte of sending a command
///  \pre \e
/////////////////////////////////////////////////////////////////
template<class COMMAND, class RETURN, int64_t QUEUESIZE>
RETURN CommandQueue<COMMAND, RETURN, QUEUESIZE>::SendSyncCmd(const COMMAND& oCmd, int64_t iTimeout)
{
    RETURN oReturn;
    iTimeout = iTimeout;
    /* 不能发送同步命令给自己，可以判断一下*/
    //normally, no such occation

    CommandElement<COMMAND, RETURN, QUEUESIZE>* pElement = GetFreeElement();

    pElement->m_oCmd = oCmd;
    pElement->m_bSync = true;
    pElement->m_pReturn = &oReturn;
    pElement->m_oSyncSemaphore.Acquire(0);

    ReadyElement(pElement);

    pElement->m_oSyncSemaphore.Acquire();
    FreeElement(pElement);

    return (oReturn);
}

template<class COMMAND, class RETURN, int64_t QUEUESIZE>
void CommandQueue<COMMAND, RETURN, QUEUESIZE>::SetRetun(const RETURN& oReturn)
{
    if (m_pActiveElement && m_pActiveElement->m_pReturn)
    {
        *m_pActiveElement->m_pReturn = oReturn;
    }
}

template<class COMMAND, class RETURN, int64_t QUEUESIZE>
void CommandQueue<COMMAND, RETURN, QUEUESIZE>::FinishActiveSyncCmd(void)
{
    if (NULL != m_pActiveElement)
    {
        m_pActiveElement->m_oSyncSemaphore.Release();
        m_pActiveElement = NULL;
    }
}

template<class COMMAND, class RETURN, int64_t QUEUESIZE>
CommandElement<COMMAND, RETURN, QUEUESIZE>* CommandQueue<COMMAND, RETURN, QUEUESIZE>::GetFreeElement()
{
    CommandElement<COMMAND, RETURN, QUEUESIZE>* pElement = NULL;

    do
    {
        m_oMutex.Acquire();
        if (m_pFirstFreeElement)
        {
            pElement = m_pFirstFreeElement;
            m_pFirstFreeElement = m_pFirstFreeElement->m_pNextElement;
        }
        else
        {
            ++ m_iNumOfWaittingForFreeSemaphore;
        }
        m_oMutex.Release();

        if (! pElement)
        {
            m_oFreeSemaphore.Acquire();
        }
    } while (! pElement);

    return pElement;
}

template<class COMMAND, class RETURN, int64_t QUEUESIZE>
inline CommandElement<COMMAND, RETURN, QUEUESIZE>* CommandQueue<COMMAND, RETURN, QUEUESIZE>::GetReadyElement(int64_t iTimeout_ms)
{
    CommandElement<COMMAND, RETURN, QUEUESIZE> * pElement = NULL;

    m_oMutex.Acquire();

    while (true)
    {
        if (NULL != m_pFirstReadyElement)
        {
            pElement = m_pFirstReadyElement;
            m_pFirstReadyElement = m_pFirstReadyElement->m_pNextElement;
            break;
        }
        else
        {
            ++ m_iNumOfWaittingForReadySemaphore;
            m_oMutex.Release();

            bool bTimeout = !m_oReadySemaphore.Acquire(iTimeout_ms);

            m_oMutex.Acquire();
            -- m_iNumOfWaittingForReadySemaphore;

            if (bTimeout)
            {
                break;
            }
        }
    }

    m_oMutex.Release();
    return pElement;
}

template<class COMMAND, class RETURN, int64_t QUEUESIZE>
inline void CommandQueue<COMMAND, RETURN, QUEUESIZE>::FreeElement(CommandElement<COMMAND, RETURN, QUEUESIZE>* pElement)
{
    m_oMutex.Acquire();

    pElement->m_bSync = false;
    pElement->m_pReturn = NULL;

    pElement->m_pNextElement = m_pFirstFreeElement;
    m_pFirstFreeElement = pElement;

    if (0 < m_iNumOfWaittingForFreeSemaphore)
    {
        m_oFreeSemaphore.Release();
        -- m_iNumOfWaittingForFreeSemaphore;
    }

    m_oMutex.Release();
}


template<class COMMAND, class RETURN, int64_t QUEUESIZE>
inline void CommandQueue<COMMAND, RETURN, QUEUESIZE>::ReadyElement(CommandElement<COMMAND, RETURN, QUEUESIZE> * pElement)
{
    m_oMutex.Acquire();

    pElement->m_pNextElement = NULL;
    if (NULL != m_pFirstReadyElement)
    {
        CommandElement<COMMAND, RETURN, QUEUESIZE> * pCurElement = m_pFirstReadyElement;

        while (pCurElement->m_pNextElement)
        {
            pCurElement = pCurElement->m_pNextElement;
        }

        pCurElement->m_pNextElement = pElement;
    }
    else
    {
        m_pFirstReadyElement = pElement;
    }

    if (m_iNumOfWaittingForReadySemaphore)
    {
        m_oReadySemaphore.Release();
    }

    m_oMutex.Release();
}

template<class COMMAND, class RETURN, int64_t QUEUESIZE>
inline void CommandQueue<COMMAND, RETURN, QUEUESIZE>::Empty(void)
{
    m_oMutex.Acquire();

    CommandElement<COMMAND, RETURN, QUEUESIZE> * pTempElement = NULL;
    //empty the queue
    while(m_pFirstReadyElement)
    {
        m_pFirstReadyElement->m_bSync = false;
        m_pFirstReadyElement->m_pReturn = NULL;

        //m_pFirstReadyElement point to the next
        pTempElement = m_pFirstReadyElement;
        m_pFirstReadyElement = m_pFirstReadyElement->m_pNextElement;

        //the current one put to the free queue
        pTempElement->m_pNextElement = m_pFirstFreeElement;
        m_pFirstFreeElement = pTempElement;

        if (0 < m_iNumOfWaittingForFreeSemaphore)
        {
            m_oFreeSemaphore.Release();
            -- m_iNumOfWaittingForFreeSemaphore;
        }
    }

    m_oMutex.Release();
}

} // namespace

