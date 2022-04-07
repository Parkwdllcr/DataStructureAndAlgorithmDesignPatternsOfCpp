#include "MulThread\CThread.h"
#include <iostream>

using namespace std;

CThread::CThread()
	: m_Thread(nullptr),
	m_PauseFlag(false),
	m_StopFlag(false),
	m_State(Stoped)
{

}

CThread::~CThread()
{
	Stop();
}

CThread::enState CThread::State() const
{
	return m_State;
}

void CThread::Start()
{
	if (m_Thread == nullptr)
	{
		m_Thread = new thread(&CThread::Run, this);
		m_PauseFlag = false;
		m_StopFlag = false;
		m_State = Running;
	}
}

void CThread::Stop()
{
	if (m_Thread != nullptr)
	{
		m_PauseFlag = false;
		m_StopFlag = true;
		m_Condition.notify_all();  // Notify one waiting thread, if there is one.
		m_Thread->join(); // wait for thread finished
		delete m_Thread;
		m_Thread = nullptr;
		m_State = Stoped;
	}
}

void CThread::Pause()
{
	if (m_Thread != nullptr)
	{
		m_PauseFlag = true;
		m_State = Paused;
	}
}

void CThread::Resume()
{
	if (m_Thread != nullptr)
	{
		m_PauseFlag = false;
		m_Condition.notify_all();
		m_State = Running;
	}
}

void CThread::Run()
{
	std::cout << "enter thread:" << this_thread::get_id() << std::endl;

	while (!m_StopFlag)
	{
		Process();
		if (m_PauseFlag)
		{
			unique_lock<mutex> locker(m_Mutex);
			while (m_PauseFlag)
			{
				m_Condition.wait(locker); // Unlock _mutex and wait to be notified
			}
			locker.unlock();
		}
	}
	m_PauseFlag = false;
	m_StopFlag = false;

	cout << "exit thread:" << this_thread::get_id() << endl;
}
