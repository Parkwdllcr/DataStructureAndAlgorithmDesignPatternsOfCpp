#pragma once

#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>

class CThread
{
public:
	CThread();
	virtual ~CThread();

	enum enState
	{
		Stoped,     ///<ֹͣ״̬��������δ��������������ֹͣ
		Running,    ///<����״̬
		Paused      ///<��ͣ״̬
	};
	enState State() const;

	void Start();
	void Stop();
	void Pause();
	void Resume();

protected:
	virtual void Process() = 0;

private:
	void Run();

private:
	std::thread*              m_Thread;
	std::mutex                m_Mutex;
	std::condition_variable   m_Condition;
	std::atomic_bool          m_PauseFlag;   ///<��ͣ��ʶ
	std::atomic_bool          m_StopFlag;   ///<ֹͣ��ʶ
	enState                   m_State;
};



