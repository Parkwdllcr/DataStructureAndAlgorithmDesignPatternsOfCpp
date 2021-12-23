//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    utilsbox_semaphore.h
///  \brief   define CSemaphore
///
///  \version 1.0
///  \date    August. 20 2014
//////////////////////////////////////////////////////////////////////////

#ifndef __UTILS_BOX_SEMAPHORE_H__
#define __UTILS_BOX_SEMAPHORE_H__

#include "ThreadUtils/umr_semaphore.h"
#include "UtilsBox/utilsbox_os_type.h"

// namespace
namespace utilsbox {

/// \class CSemaphore utilsbox_semaphore.h
/// \brief define CSemaphore
class UTILSBOX_EXPORT CSemaphore
{

public:
    virtual ~CSemaphore();
    CSemaphore();
    int32_t Wait(int32_t iMilliseconds);
    void Trigger();
private:
    threadutils::Semaphore m_oSemaphore;

};

}  // namespace

#endif // __UTILS_BOX_SEMAPHORE_H__

