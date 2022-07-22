#pragma once
#include "MulThreadAndCallBack/cutil_box.h"
#include "TcpIp/dss_tcp_client.h"
#include "TcpIp/dss_tcp_client_actor.h"

// namespace
namespace BaseCPrimerPlus {

	CTCPClientActor::CTCPClientActor(const char* ptName, CTCPClient* pTcpClient)
		: thread::Actor(ptName), m_strActorName(ptName), m_bShutdown(false), m_pTcpClient(pTcpClient)
	{
		m_strActorName += "TCPActor";
	}

	CTCPClientActor::~CTCPClientActor()
	{
		m_pTcpClient = NULL;
	}

	void CTCPClientActor::TerminateThread(void)
	{
		MRDSS_INFO("%s::TerminateThread()", m_strActorName.c_str());

		m_bShutdown = true;

		// wait for Exit
		if (MRDSS_OK != m_Semaphore.Wait(30 * 60 * 1000))
		{
			MRDSS_ERROR("Wait Thread Exit TimeOut!");
			return;
		}

		// wait svc() of Umr::Actor exit normally
		CUtils::MSleep(50);
	}

	void CTCPClientActor::svc()
	{
		// thread trap prepare
		DSS_THREAD_TRAP_PREPARE();

#ifndef _MRDSS_UT_BUILD_

		while (!m_bShutdown)
		{
			// every 2s
			for (int32_t i = 0; i < 2; i++)
			{
				CUtils::MSleep(1000);

				// for exit
				if (m_bShutdown)
				{
					break;
				}
			}

			if (!m_bShutdown)
			{
				if (m_pTcpClient)
				{
					if (!m_pTcpClient->IsConnected())
					{
						if (MRDSS_OK != m_pTcpClient->Connect())
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

}


