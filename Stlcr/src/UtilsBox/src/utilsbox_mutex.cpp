//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    utilsbox_mutex.cpp
///  \brief   implement CMutex
///
///  \version 1.0
///  \date    August. 20 2014
//////////////////////////////////////////////////////////////////////////

#include "UtilsBox/utilsbox_mutex.h"

// namespace
namespace utilsbox {

CMutex::CMutex() : m_oMutex()
{
}

CMutex::~CMutex()
{
}

void CMutex::Lock()
{
    m_oMutex.Acquire();
}


void CMutex::UnLock()
{
    m_oMutex.Release();
}

}  // namespace

