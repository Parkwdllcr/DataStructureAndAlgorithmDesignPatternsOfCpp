#include "CThread.h"

//
//CThread::CThread():m_uiThreadId(-1),m_strName(""),m_bRun(),m_pThreadFunc(nullptr)
//{
//	m_hThread = (HANDLE)_beginthreadex(nullptr, 0, StaticThreadFunc, this, 0, &m_uiThreadId);
//	m_hThreadEvent = CreateEvent(nullptr, false, false, nullptr);
//}
//
//CThread::~CThread()
//{
//
//}
//
////�߼���ͨ��
//bool CThread::Start()
//{
//	if (m_bRun || nullptr == m_hThread)
//	{
//		return false;
//	}
//
//	m_bRun = true;
//	SetEvent(m_hThreadEvent);
//	return m_bRun;
//}
//
//void CThread::Join(int itimeout /*= -1*/)
//{
//	if (nullptr == m_hThread || !m_bRun)
//	{
//		return;
//	}
//
//	if (itimeout<=0)
//	{
//		itimeout = INFINITE;
//	}
//
//	//�����ȴ��߳̽���
//	m_Semaphore.Wait();
//}
//
//void CThread::SetThreadEnd()
//{
//	m_bEnd = true;
//}
//
//unsigned int WINAPI CThread::StaticThreadFunc(void* arg)
//{
//	CThread* pThread = (CThread*)arg;
//
//	while (true)
//	{
//		pThread->m_bRun = false;
//		m_Semaphore.Wait();
//		pThread->m_bRun = true;
//
//		if (nullptr != pThread->m_pThreadFunc )
//		{
//			pThread->m_pThreadFunc->Run();
//		}
//		else
//		{
//			pThread->Run();
//		}
//
//		//�Ƿ��˳��߳�
//		if (pThread->m_bEnd)
//		{
//			break;
//		}
//	}
//
//	return 1;
//}
//
////�����߳�
//void CThread::Resume()
//{
//	if (nullptr == m_hThread || !m_bRun)
//	{
//		return;
//	}
//
//	::ResumeThread(m_hThread);
//}
//
////�����߳�
//void CThread::Suspend()
//{
//	if (nullptr == m_hThread || m_bRun)
//	{
//		return;
//	}
//	::SuspendThread(m_hThread);
//
//}
//
//void CThread::Run()
//{
//
//}
//
//void CThread::AddWorkThread(CThreadFunc* pThreadFunc)
//{
//	m_pThreadFunc = pThreadFunc;
//}
