//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    utilsbox_semaphore.cpp
///  \brief   implement CSemaphore
///
///  \version 1.0
///  \date    August. 20 2014
//////////////////////////////////////////////////////////////////////////

#include "UtilsBox/utilsbox_return_code.h"
#include "UtilsBox/utilsbox_semaphore.h"

// namespace
namespace utilsbox {

CSemaphore::CSemaphore() : m_oSemaphore(0, 1)
{
}

CSemaphore::~CSemaphore()
{
}

int32_t CSemaphore::Wait(int32_t iMilliseconds)
{
    if ( !m_oSemaphore.Acquire(iMilliseconds) )
    {
        return UTILSBOX_FAILED;
    }
    return UTILSBOX_OK;
}

void CSemaphore::Trigger()
{
    m_oSemaphore.Release();
}

}  // namespace
