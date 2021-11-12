//////////////////////////////////////////////////////////////////////////
///
///  Copyright, (c) Shanghai United Imaging Health_care Inc., 2011
///  All rights reserved.
///
///  \author   Shi Yaoming  yaoming.shi@united-imaging.com
///
///  \file    umr_mutex.cpp
///  \brief
///
///  \version 1.0
///  \date    Sep.15, 2011
///
///  \ChangedBy       NO
///  \ChangedDate     NO
///  \ChangedContent  NO
//////////////////////////////////////////////////////////////////////////
#include "ThreadUtils/umr_mutex.h"

#include <stdio.h>

#include "umr_mutex_impl.h"

// namespace
namespace threadutils {

Mutex::Mutex( void ) : m_pImpl(NULL)
{
    // Create an instance of boost implmentation
    m_pImpl = new MutexImpl();
}

Mutex::~Mutex( void )
{
    if (m_pImpl != NULL)
    {
        delete m_pImpl;
        m_pImpl = NULL;
    }
}

/////////////////////////////////////////////////////////////////
///  \brief Acquire the mutex, continue if get the mutex
///
///  \param[in]    None
///  \param[out]   None
///  \return       None
///  \pre \e
/////////////////////////////////////////////////////////////////
bool Mutex::Acquire( void )
{
    if (m_pImpl != NULL)
    {
        return m_pImpl->Acquire();
    }

    return false;
}


bool Mutex::TryAcquire( void )
{
    if (m_pImpl != NULL)
    {
        return m_pImpl->TryAcquire();
    }

    return false;
}

/////////////////////////////////////////////////////////////////
///  \brief Release the mutex
///
///  \param[in]    None
///  \param[out]   None
///  \return       None
///  \pre \e
/////////////////////////////////////////////////////////////////
bool Mutex::Release( void )
{
    if (m_pImpl != NULL)
    {
        return m_pImpl->Release();
    }
    return false;
}

} // namespace
