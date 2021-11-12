//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    utilsbox_mutex.h
///  \brief   define mutex
///
///  \version 1.0
///  \date    August. 20 2014
//////////////////////////////////////////////////////////////////////////

#ifndef __UTILS_BOX_MUTEX_H__
#define __UTILS_BOX_MUTEX_H__

#include "ThreadUtils/umr_mutex.h"

#include "UtilsBox/utilsbox_os_type.h"

// namespace
namespace utilsbox {

/// \class CMutex utilsbox_mutex.h
/// \brief define mutex
class UTILSBOX_EXPORT CMutex
{

public:
    virtual ~CMutex();

    CMutex();
    void Lock();
    void UnLock();

private:
    threadutils::Mutex m_oMutex;

};

}  // namespace

#endif // __UTILS_BOX_MUTEX_H__

