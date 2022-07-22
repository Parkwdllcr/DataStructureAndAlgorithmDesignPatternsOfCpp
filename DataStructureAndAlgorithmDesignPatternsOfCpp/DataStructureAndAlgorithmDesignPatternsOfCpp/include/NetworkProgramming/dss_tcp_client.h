//////////////////////////////////////////////////////////////////////////
/// \defgroup MRDeviceSubSystem
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author   HUANG jintao jintao.huang@united-imaging.com
///
///  \file    dss_tcp_client.h
///  \brief   define the tcp/ip client
///
///  \version 1.0
///  \date    Nov. 04, 2011
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "MulThreadAndCallBack/thread_os_define.h"

#include <string>

#ifdef _THREAD_OS_WIN_ // for windows impletement
#include <winsock2.h>
#endif

#include "MulThreadAndCallBack/thread_os_define.h"
#include "MulThreadAndCallBack/thread_mutex.h"

// namespace
namespace BaseCPrimerPlus {
	class CTCPClientActor;

	class THREAD_EXPORT CTCPClient
	{

	public:
		CTCPClient();
		~CTCPClient();

		void SetPeerHost(const std::string& strPeerHost);
		const std::string& GetPeerHost() const;
		void SetPeerPort(const uint16_t usPeerPort);
		uint16_t GetPeerPort() const;
		int32_t Initialize();
		int32_t Send(const unsigned char* const pcData, const uint32_t uiDataLen);
		int32_t Recv(unsigned char* pcData, uint32_t uiMaxDataLen, uint32_t& uiDataLen);

		int32_t Connect();
		int32_t IsConnected();
		void Shutdown();

	public:
		void SetConnectFlag(const bool bFlag);

	private:
		CTCPClientActor* m_pTcpClientActor;
		// define socket
#ifdef _THREAD_OS_WIN_ // for windows impletement
		SOCKET m_iSocket;
#elif defined(_THREAD_OS_LINUX_)
		int m_iSocket;
#endif
		uint16_t m_usPeerPort;
		std::string m_strPeerHost;
		thread::
		thread::CMutex m_MutexConnected;
		bool m_bConnected;
		thread::CMutex m_MutexSocket;

	};

}


