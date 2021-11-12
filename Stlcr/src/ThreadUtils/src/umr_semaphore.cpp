//////////////////////////////////////////////////////////////////////////
///
///  Copyright, (c) Shanghai United Imaging Health_care Inc., 2011
///  All rights reserved.
///
///  \author   Shi Yaoming  yaoming.shi@united-imaging.com
///
///  \file    umr_semaphore.cpp
///  \brief
///
///  \version 1.0
///  \date    Sep.15, 2011
///
///  \ChangedBy       NO
///  \ChangedDate     NO
///  \ChangedContent  NO
//////////////////////////////////////////////////////////////////////////
#include "ThreadUtils/umr_semaphore.h"

#include <stdio.h>

#include "umr_semaphore_impl.h"

// namespace
namespace threadutils {

Semaphore::Semaphore(int64_t iCount, int64_t iMaxCount) : m_pImpl(NULL)
{
    // Create an instance
    m_pImpl = new SemaphoreImpl(iCount, iMaxCount);
}

Semaphore::~Semaphore( void )
{
    if (m_pImpl != NULL)
    {
        delete m_pImpl;
        m_pImpl = NULL;
    }
}

/////////////////////////////////////////////////////////////////
///  \brief Acquire the Semaphore, continue if get the Semaphore
///
///  \param[in]    iTimeout: ms. -1 forever waitting; 0 no waitting;
///  \param[out]   None
///  \return       bool: true if get the semaphore;false if fail or timeout
///  \pre \e
/////////////////////////////////////////////////////////////////
bool Semaphore::Acquire(int64_t iTimeout)
{
    if (m_pImpl == NULL)
    {
        return false;
    }
    return m_pImpl->Acquire(iTimeout);
}

/////////////////////////////////////////////////////////////////
///  \brief Release the Semaphore
///
///  \param[in]    None
///  \param[out]   None
///  \return       None
///  \pre \e
/////////////////////////////////////////////////////////////////
bool Semaphore::Release( void )
{
    if (m_pImpl == NULL)
    {
        return false;
    }
    return m_pImpl->Release();
}

} // namespace
