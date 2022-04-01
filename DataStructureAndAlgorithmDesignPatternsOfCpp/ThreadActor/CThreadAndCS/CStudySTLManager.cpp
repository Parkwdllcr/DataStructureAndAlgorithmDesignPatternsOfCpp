#include "CStudySTLManager.h"
#include<iostream>

CStudySTLManager::CStudySTLManager():m_pListTestThread()
{
}

CStudySTLManager::~CStudySTLManager()
{
	try
	{
		if (!m_pListTestThread.empty())
		{
			ShutDown();
		}
	}
	catch (const std::exception&)
	{
		std::cout << "CStudySTLManager::~CStudySTLManager():UnKown errer!" << std::endl;
	}
}

int CStudySTLManager::StartProcessThread()
{
	for(auto it = m_pListTestThread.begin(); it != m_pListTestThread.end();++it)
	{
		if ((*it) == nullptr)
		{
			std::cout << "Thread is nullptr!" << std::endl;
			return 0;
		}
		(*it)->start();
	}
	return 1;
}

void CStudySTLManager::ShutDown()
{
	for (auto it = m_pListTestThread.begin(); it != m_pListTestThread.end(); ++it)
	{
		if ((*it) == nullptr)
		{
			std::cout << "Thread is nullptr!" << std::endl;
			return;
		}
		(*it)->stop();
	}
}

void CStudySTLManager::AddTestThread(std::shared_ptr<IThestThread> pTestThread)
{
	if (nullptr == pTestThread)
	{
		std::cout << "pTestThread is nullptr" << std::endl;
		return;
	}
	m_pListTestThread.push_back(pTestThread);
}
