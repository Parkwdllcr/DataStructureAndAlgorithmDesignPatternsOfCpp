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

#pragma once

#include "MulThreadAndCallBack/Actor.h"

#include "MulThreadAndCallBack/thread_os_define.h"

#include "MulThreadAndCallBack/thread_semaphore.h"


namespace BaseCPrimerPlus {
	// declare other class
	class CTCPClient;

	/// \class CTCPClientActor dss_tcp_client_actor.h
	/// \brief define the TCP client actor
	class CTCPClientActor : public thread::Actor
	{
	public:
		CTCPClientActor(const char* ptName, CTCPClient* pTcpClient);
		virtual ~CTCPClientActor();

		virtual void svc();
		virtual void TerminateThread(void);

	protected:
		CTCPClientActor() : thread::Actor("") { m_pTcpClient = NULL; }

	private:
		std::string m_strActorName;
		bool m_bShutdown;
		CTCPClient* m_pTcpClient;
		thread::CSemaphore m_Semaphore;
	};

}

