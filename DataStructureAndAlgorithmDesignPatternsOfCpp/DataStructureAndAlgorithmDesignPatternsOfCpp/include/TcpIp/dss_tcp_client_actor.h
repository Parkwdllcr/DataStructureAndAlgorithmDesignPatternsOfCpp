//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystemClientContainee
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    dss_tcp_client_actor.h
///  \brief   define the TCP client actor
///
///  \version 1.0
///  \date    Nov. 04, 2011
//////////////////////////////////////////////////////////////////////////

#ifndef __DSS_TCP_CLIENT_ACTOR_H__
#define __DSS_TCP_CLIENT_ACTOR_H__

#include "Common/ThreadUtils/umr_actor.h"

#include "Device/Framework/dss_define.h"
#ifndef _MRDSS_UT_BUILD_
#include "Device/Framework/common/include/dss_semaphore.h"
#else
#include "Device/Framework/common_UTAssist/dss_semaphore_ut_assist.h"
#endif

// namespace
DSS_NAME_SPACE_BEGIN(MRDss)

// declare other class
class CTCPClient;

/// \class CTCPClientActor dss_tcp_client_actor.h
/// \brief define the TCP client actor
class CTCPClientActor : public Umr::Actor
{
public:
    CTCPClientActor(const char * ptName, CTCPClient* pTcpClient);
    virtual ~CTCPClientActor();

    virtual void svc();
    virtual void TerminateThread( void );

protected:
    CTCPClientActor() : Umr::Actor("") { m_pTcpClient = NULL; }

private:
    std::string m_strActorName;
    bool m_bShutdown;
    CTCPClient* m_pTcpClient;
    MRDss::CSemaphore m_Semaphore;
};

DSS_NAME_SPACE_END // namespace

#endif
