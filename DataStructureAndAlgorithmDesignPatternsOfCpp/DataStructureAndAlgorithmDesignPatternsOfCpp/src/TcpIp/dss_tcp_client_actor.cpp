//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    dss_tcp_client_actor.cpp
///  \brief   Implement CTCPClientActor
///
///  \version 1.0
///  \date    Nov. 04, 2011
//////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "Device/Framework/common/include/dss_utils.h"
#include "Device/CarryChannel/common/include/dss_tcp_client.h"
#include "dss_tcp_client_actor.h"

// namespace
DSS_NAME_SPACE_BEGIN(MRDss)

CTCPClientActor::CTCPClientActor(const char * ptName, CTCPClient* pTcpClient)
                : Umr::Actor(ptName), m_strActorName(ptName), m_bShutdown(false), m_pTcpClient(pTcpClient)
{
    m_strActorName += "TCPActor";
}

CTCPClientActor::~CTCPClientActor()
{
    m_pTcpClient = NULL;
}

void CTCPClientActor::TerminateThread( void )
{
    MRDSS_INFO("%s::TerminateThread()", m_strActorName.c_str());

    m_bShutdown = true;

    // wait for Exit
    if ( MRDSS_OK!=m_Semaphore.Wait(30*60*1000) )
    {
        MRDSS_ERROR("Wait Thread Exit TimeOut!");
        return ;
    }

    // wait svc() of Umr::Actor exit normally
    CUtils::MSleep(50);
}

void CTCPClientActor::svc()
{
    // thread trap prepare
    DSS_THREAD_TRAP_PREPARE();

#ifndef _MRDSS_UT_BUILD_

    while ( !m_bShutdown )
    {
        // every 2s
        for ( int32_t i=0;i<2;i++ )
        {
            CUtils::MSleep(1000);

            // for exit
            if ( m_bShutdown )
            {
                break;
            }
        }

        if ( !m_bShutdown )
        {
            if ( m_pTcpClient )
            {
                if ( !m_pTcpClient->IsConnected() )
                {
                    if ( MRDSS_OK!=m_pTcpClient->Connect() )
                    {
                    }
                }
            }
        }

        // thread trap run
        DSS_THREAD_TRAP_RUN();
    }

#endif

    // exit
    DSS_THREAD_TRAP_FINISH();
    CUtils::MSleep(50);
    m_Semaphore.Trigger();
}

DSS_NAME_SPACE_END  // namespace
