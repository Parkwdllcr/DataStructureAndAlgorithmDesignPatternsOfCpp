#pragma once
#include <mutex>
#include <condition_variable>

class CSemaphore
{
public:
	CSemaphore(int iCount,int iMaxCount);
	~CSemaphore();

	void Wait(int64_t iTimeOut);
	void Trigger();
private:
	int m_iCount;
	std::mutex  m_mutex;
	std::condition_variable m_condition;
};

