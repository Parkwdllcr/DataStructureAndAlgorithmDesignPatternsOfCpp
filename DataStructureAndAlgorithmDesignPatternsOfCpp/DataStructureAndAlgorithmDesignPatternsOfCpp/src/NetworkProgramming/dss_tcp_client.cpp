#pragma once

#include "TcpIp/dss_tcp_client_actor.h"
#include "TcpIp/dss_tcp_client.h"
#include <string.h>

#ifdef _THREAD_OS_WIN_ // for windows impletement
#elif defined(_THREAD_OS_LINUX_)
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#endif

// namespace
namespace BaseCPrimerPlus {

#ifdef _MRDSS_OS_WIN_ // for windows impletement
	CTCPClient::CTCPClient() : m_pTcpClientActor(NULL), m_iSocket(INVALID_SOCKET), m_strPeerHost(""), m_MutexConnected(), m_bConnected(false), m_MutexSocket()
	{
	}
#elif defined(_MRDSS_OS_LINUX_)
	CTCPClient::CTCPClient() : m_pTcpClientActor(NULL), m_iSocket(-1), m_strPeerHost(""), m_MutexConnected(), m_bConnected(false), m_MutexSocket()
	{
	}
#else
#endif

	CTCPClient::~CTCPClient()
	{
		try
		{
			Shutdown();

			// free socket
#ifdef _MRDSS_OS_WIN_ // for windows impletement
			if (INVALID_SOCKET != m_iSocket)
			{
				closesocket(m_iSocket);
			}
			m_iSocket = INVALID_SOCKET;

			// clearup
			WSACleanup();

#elif defined(_MRDSS_OS_LINUX_)
			if (m_iSocket)
			{
				close(m_iSocket);
			}
			m_iSocket = -1;
#else
#error "Unsupported OS!"
#endif
		}
		catch (...)
		{
		}
	}

	void CTCPClient::SetPeerHost(const std::string& strPeerHost)
	{
		m_strPeerHost = strPeerHost;
	}

	const std::string& CTCPClient::GetPeerHost() const
	{
		return m_strPeerHost;
	}

	void CTCPClient::SetPeerPort(const uint16_t usPeerPort)
	{
		m_usPeerPort = usPeerPort;
	}

	uint16_t CTCPClient::GetPeerPort() const
	{
		return m_usPeerPort;
	}

	int32_t CTCPClient::Initialize()
	{
		if ((0 == m_usPeerPort) ||
			(m_strPeerHost.empty()))
		{
			MRDSS_ERROR("PeerHost or PeerPort(%u) Error!", m_usPeerPort);
			return MRDSS_OK;
		}

		// new socket
#ifdef _MRDSS_OS_WIN_ // for windows impletement
	// Initializing Winsock
		WSADATA wsaData;
		int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (0 != iResult)
		{
			MRDSS_ERROR("WinSocket WSAStartup Failed!Result = %d.", iResult);
			return 1;
		}
#endif

		// new a actor
		if (!m_pTcpClientActor)
		{
			std::string strActorName = m_strPeerHost;
			char acTmp[32] = "";
			sprintf(acTmp, "_%d_", m_usPeerPort);
			strActorName += acTmp;
			m_pTcpClientActor = new CTCPClientActor(strActorName.c_str(), this);
			if (!m_pTcpClientActor->Start())
			{
				MRDSS_ERROR("Start Actor Failed!");
				delete m_pTcpClientActor;
				m_pTcpClientActor = NULL;
				return MRDSS_FAILED;
			}
		}
		return MRDSS_OK;
	}

	int32_t CTCPClient::Send(const unsigned char* const pcData, const uint32_t uiDataLen)
	{
		if ((!pcData) ||
			(0 == uiDataLen))
		{
			MRDSS_ERROR("Input Error!");
			return MRDSS_FAILED;
		}

		if (MRDSS_OK != IsConnected())
		{
			MRDSS_ERROR("Tcp Not Connect, Can Not Send Out Data!");
			return MRDSS_FAILED;
		}
#ifndef _MRDSS_UT_BUILD_

#ifdef _MRDSS_OS_WIN_ // for windows impletement
		// lock
		m_MutexSocket.Lock();

		if (INVALID_SOCKET == m_iSocket)
		{
			MRDSS_ERROR("Socket Not Initialized!");

			// unlock
			m_MutexSocket.UnLock();
			return MRDSS_FAILED;
		}

		fd_set fd_WriteMask;
		FD_ZERO(&fd_WriteMask);
		FD_SET(m_iSocket, &fd_WriteMask);
		struct timeval timeout;
		timeout.tv_sec = 0;
		timeout.tv_usec = 0;
		int ret = select(0, NULL, &fd_WriteMask, NULL, &timeout);
		if ((0 == ret) || (SOCKET_ERROR == ret))
		{
			MRDSS_ERROR("Select Error!Errno=%d\r\n", WSAGetLastError());

			// unlock
			m_MutexSocket.UnLock();
			return MRDSS_FAILED;
		}
		if (!FD_ISSET(m_iSocket, &fd_WriteMask))
		{
			MRDSS_ERROR("Client Socket Error!Errno=%d\r\n", WSAGetLastError());

			// unlock
			m_MutexSocket.UnLock();
			return MRDSS_FAILED;
		}

		/* Send Packets */
		int iSendBytes = send(m_iSocket, reinterpret_cast<const char*>(pcData), uiDataLen, 0);
		if ((SOCKET_ERROR == iSendBytes) || (static_cast<uint32_t>(iSendBytes) != uiDataLen))
		{
			MRDSS_ERROR("Network Send(want:%u, real:%d) Error!Errno=%d\r\n", uiDataLen, iSendBytes, WSAGetLastError());

			// unlock
			m_MutexSocket.UnLock();
			return MRDSS_FAILED;
		}

		// unlock
		m_MutexSocket.UnLock();
#elif defined(_MRDSS_OS_LINUX_)
		// lock
		m_MutexSocket.Lock();

		if (0 >= m_iSocket)
		{
			MRDSS_ERROR("Socket Not Initialized!");

			// unlock
			m_MutexSocket.UnLock();
			return MRDSS_FAILED;
		}

		fd_set fd_WriteMask;
		FD_ZERO(&fd_WriteMask);
		FD_SET(m_iSocket, &fd_WriteMask);
		struct timeval timeout;
		timeout.tv_sec = 0;
		timeout.tv_usec = 0;
		if (0 >= select(m_iSocket + 1, NULL, &fd_WriteMask, NULL, &timeout))
		{
			MRDSS_ERROR("Select Error!Errno=%d\r\n", errno);

			// unlock
			m_MutexSocket.UnLock();
			return MRDSS_FAILED;
		}
		if (!FD_ISSET(m_iSocket, &fd_WriteMask))
		{
			MRDSS_ERROR("Client Socket Error!Errno=%d\r\n", errno);

			// unlock
			m_MutexSocket.UnLock();
			return MRDSS_FAILED;
		}

		/* Send Packets */
		int iSendBytes = send(m_iSocket, pcData, uiDataLen, MSG_NOSIGNAL);
		if ((0 > iSendBytes) || (static_cast<uint32_t>(iSendBytes) != uiDataLen))
		{
			MRDSS_ERROR("Network Send(want:%u, real:%d) Error!Errno=%d\r\n", uiDataLen, iSendBytes, errno);

			// unlock
			m_MutexSocket.UnLock();
			return MRDSS_FAILED;
		}

		// unlock
		m_MutexSocket.UnLock();
#else
#error "Unsupported OS!"
#endif

#endif
		return MRDSS_OK;
	}

	int32_t CTCPClient::Recv(unsigned char* pcData, uint32_t uiMaxDataLen, uint32_t& uiDataLen)
	{
		if ((!pcData) ||
			(0 == uiMaxDataLen))
		{
			MRDSS_ERROR("Input Error!");
			return MRDSS_FAILED;
		}

		uiDataLen = 0;

		if (MRDSS_OK != IsConnected())
		{
			return MRDSS_OK;
		}

		//MRDSS_ERROR("=========Beging==============CTCPClient::Recv() \r\n");
#ifndef _MRDSS_UT_BUILD_

#ifdef _MRDSS_OS_WIN_ // for windows impletement
		if (INVALID_SOCKET == m_iSocket)
		{
			MRDSS_ERROR("Socket Not Initialized!");
			return MRDSS_FAILED;
		}

		fd_set fd_ReadMask;
		FD_ZERO(&fd_ReadMask);
		FD_SET(m_iSocket, &fd_ReadMask);
		struct timeval timeout;
		timeout.tv_sec = 0;
		timeout.tv_usec = 0;
		int ret = select(0, &fd_ReadMask, NULL, NULL, &timeout);
		if ((0 == ret) || (SOCKET_ERROR == ret))
		{
			return MRDSS_OK;
		}
		if (!FD_ISSET(m_iSocket, &fd_ReadMask))
		{
			return MRDSS_OK;
		}

		// Receive packet from socket
		int iRecvBytes = recv(m_iSocket, reinterpret_cast<char*>(pcData), uiMaxDataLen, 0);
		if (SOCKET_ERROR == iRecvBytes)
		{
			MRDSS_ERROR("Network Recv Error(errno:%d)!", WSAGetLastError());

			// set unconnect
			SetConnectFlag(false);
			return MRDSS_FAILED;
		}
		else if (0 == iRecvBytes)
		{
			MRDSS_ERROR("Client Close Connection!");

			// set unconnect
			SetConnectFlag(false);
			return MRDSS_FAILED;
		}
		else if (uiMaxDataLen != static_cast<uint32_t>(iRecvBytes))
		{
			MRDSS_ERROR("Recv Data Len Different(WantDataLen: %u, ReadDataLen: %d)!", uiMaxDataLen, iRecvBytes);
		}
		uiDataLen = static_cast<uint32_t>(iRecvBytes);

#elif defined(_MRDSS_OS_LINUX_)
		if (0 >= m_iSocket)
		{
			MRDSS_ERROR("Socket Not Initialized!");
			return MRDSS_FAILED;
		}

		fd_set fd_ReadMask;
		FD_ZERO(&fd_ReadMask);
		FD_SET(m_iSocket, &fd_ReadMask);
		struct timeval timeout;
		timeout.tv_sec = 0;
		timeout.tv_usec = 0;
		if (0 >= select(m_iSocket + 1, &fd_ReadMask, NULL, NULL, &timeout))
		{
			return MRDSS_OK;
		}
		if (!FD_ISSET(m_iSocket, &fd_ReadMask))
		{
			return MRDSS_OK;
		}

		// Receive packet from socket
		int iRecvBytes = recv(m_iSocket, pcData, uiMaxDataLen, 0);
		if (0 > iRecvBytes)
		{
			MRDSS_ERROR("Network Recv Error(errno:%d)!", errno);

			// set unconnect
			SetConnectFlag(false);
			return MRDSS_FAILED;
		}
		else if (0 == iRecvBytes)
		{
			MRDSS_ERROR("Client Clost Connection!");

			// set unconnect
			SetConnectFlag(false);
			return MRDSS_FAILED;
		}
		else if (uiMaxDataLen != static_cast<uint32_t>(iRecvBytes))
		{
			MRDSS_INFO("Recv Data Len Different(WantDataLen: %u, ReadDataLen: %d)!", uiMaxDataLen, iRecvBytes);
		}
		uiDataLen = static_cast<uint32_t>(iRecvBytes);
#else
#error "Unsupported OS!"
#endif

#endif
	//MRDSS_ERROR("=========End   ==============CCTCPClient::Recv() Len = %u\r\n", uiDataLen);
		return MRDSS_OK;
	}

	int32_t CTCPClient::Connect()
	{
		if ((0 == m_usPeerPort) ||
			(m_strPeerHost.empty()))
		{
			MRDSS_ERROR("PeerHost or PeerPort(%u) Error!", m_usPeerPort);
			return MRDSS_FAILED;
		}

		MRDSS_INFO("Start Connect To Server(%s:%u)....", m_strPeerHost.c_str(), m_usPeerPort);
#ifndef _MRDSS_UT_BUILD_

#ifdef _MRDSS_OS_WIN_ // for windows impletement
		// lock
		m_MutexSocket.Lock();

		// close old socket
		if (INVALID_SOCKET != m_iSocket)
		{
			closesocket(m_iSocket);
		}
		m_iSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (INVALID_SOCKET == m_iSocket)
		{
			MRDSS_ERROR("Create Socket Failed!! Errno=%d\r\n", WSAGetLastError());

			// unlock
			m_MutexSocket.UnLock();
			return MRDSS_FAILED;
		}

		// unlock
		m_MutexSocket.UnLock();

		int flag = 1;
		if (-1 == setsockopt(m_iSocket, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char*>(&flag), sizeof(flag)))
		{
			MRDSS_ERROR("Set Socket Failed!! Errno=%d\r\n", WSAGetLastError());
			return MRDSS_FAILED;
		}
		if (-1 == setsockopt(m_iSocket, IPPROTO_TCP, TCP_NODELAY, reinterpret_cast<const char*>(&flag), sizeof(flag)))
		{
			MRDSS_ERROR("Set Socket Failed!! Errno=%d\r\n", WSAGetLastError());
			return MRDSS_FAILED;
		}

		int snd_size = 32 * 1024;    // recv buffer size id 32K
		if (0 > setsockopt(m_iSocket, SOL_SOCKET, SO_RCVBUF, reinterpret_cast<const char*>(&snd_size), sizeof(snd_size)))
		{
			MRDSS_ERROR("Set Socket Failed!! Errno=%d\r\n", WSAGetLastError());
			return MRDSS_FAILED;
		}

		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(m_strPeerHost.c_str());
		addr.sin_port = htons(m_usPeerPort);
		if (SOCKET_ERROR == connect(m_iSocket, (struct sockaddr*) & addr, sizeof(addr)))
		{
			MRDSS_ERROR("Connect socket Error(Errno==%d)!", WSAGetLastError());
			return MRDSS_FAILED;
		}
#elif defined(_MRDSS_OS_LINUX_)
		// lock
		m_MutexSocket.Lock();

		// close old socket
		if (0 < m_iSocket)
		{
			close(m_iSocket);
		}
		m_iSocket = socket(AF_INET, SOCK_STREAM, 0);
		if (-1 == m_iSocket)
		{
			MRDSS_ERROR("Create Socket Failed!! Errno=%d\r\n", errno);

			// unlock
			m_MutexSocket.UnLock();
			return MRDSS_FAILED;
		}

		// unlock
		m_MutexSocket.UnLock();

		int flag = 1;
		if (-1 == setsockopt(m_iSocket, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag)))
		{
			MRDSS_ERROR("Set Socket Failed!! Errno=%d\r\n", errno);
			return MRDSS_FAILED;
		}
		if (-1 == setsockopt(m_iSocket, IPPROTO_TCP, TCP_NODELAY, &flag, sizeof(flag)))
		{
			MRDSS_ERROR("Set Socket Failed!! Errno=%d\r\n", errno);
			return MRDSS_FAILED;
		}

		int snd_size = 32 * 1024;    // recv buffer size id 32K
		socklen_t optlen = sizeof(snd_size);
		if (0 > setsockopt(m_iSocket, SOL_SOCKET, SO_RCVBUF, &snd_size, optlen))
		{
			MRDSS_ERROR("Set Socket Failed!! Errno=%d\r\n", errno);
			return MRDSS_FAILED;
		}

		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(m_strPeerHost.c_str());
		addr.sin_port = htons(m_usPeerPort);
		if (0 > connect(m_iSocket, (struct sockaddr*) & addr, sizeof(addr)))
		{
			MRDSS_ERROR("Connect socket Error(Errno==%d)!", errno);
			return MRDSS_FAILED;
		}
#else
#error "Unsupported OS!"
#endif

		MRDSS_INFO("Connect To Server Successfully!");
#endif

		// set connect
		SetConnectFlag(true);
		return MRDSS_OK;
	}

	int32_t CTCPClient::IsConnected()
	{
		// lock
		m_MutexConnected.Lock();

		if (!m_bConnected)
		{
			// unlock
			m_MutexConnected.UnLock();
			return MRDSS_FAILED;
		}

		// unlock
		m_MutexConnected.UnLock();
		return MRDSS_OK;
	}

	void CTCPClient::SetConnectFlag(const bool bFlag)
	{
		// lock
		m_MutexConnected.Lock();

		m_bConnected = bFlag;

		// unlock
		m_MutexConnected.UnLock();
	}

	void CTCPClient::Shutdown()
	{
		if (m_pTcpClientActor)
		{
			m_pTcpClientActor->TerminateThread();
			delete m_pTcpClientActor;
			m_pTcpClientActor = NULL;
		}
	}

}


