#pragma once
#include <mutex>
class CMutex
{
public:
	CMutex(void);
	~CMutex();
public:
	//»¥³âËø
	void Lock(void);
	bool LockTry(void);
	void UnLock(void);

private:
	std::mutex  m_Mutex;
	bool m_bLocked;
};

