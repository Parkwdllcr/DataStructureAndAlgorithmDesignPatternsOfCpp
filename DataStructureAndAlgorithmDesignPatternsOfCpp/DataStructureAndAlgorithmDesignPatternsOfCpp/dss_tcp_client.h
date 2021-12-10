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

#ifndef __MR_DSS_TCP_CLIENT_H__
#define __MR_DSS_TCP_CLIENT_H__

#include "Device/Framework/dss_os_type.h"

#include <string>

#ifdef _MRDSS_OS_WIN_ // for windows impletement
#include <winsock2.h>
#endif

#include "Device/Framework/dss_define.h"
#include "Device/Framework/common/include/dss_mutex.h"

// namespace
DSS_NAME_SPACE_BEGIN(MRDss)

// declare other class
class CTCPClientActor;

/// \class CTCPClient dss_tcp_client.h
/// \brief define the tcp/ip client
class MRDSS_EXPORT CTCPClient
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

#ifndef _MRDSS_UT_BUILD_
private:
#else
public:
#endif
    void SetConnectFlag(const bool bFlag);

private:
    CTCPClientActor* m_pTcpClientActor;
// define socket
#ifdef _MRDSS_OS_WIN_ // for windows impletement
    SOCKET m_iSocket;
#elif defined(_MRDSS_OS_LINUX_)
    int m_iSocket;
#else
#error "Unsupported OS!"
#endif
    uint16_t m_usPeerPort;
	std::string m_strPeerHost;
    CMutex m_MutexConnected;
	bool m_bConnected;
    CMutex m_MutexSocket;

};

DSS_NAME_SPACE_END  // namespace

#endif // __MR_DSS_TCP_CLIENT_H__
