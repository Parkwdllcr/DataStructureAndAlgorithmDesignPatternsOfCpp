#include "CMutex.h"

CMutex::CMutex(void):m_bLocked(false), m_Mutex()
{

}

CMutex::~CMutex()
{

}

void CMutex::Lock(void)
{
	m_bLocked = true;
	m_Mutex.lock();
}

bool CMutex::LockTry(void)
{
	m_bLocked = true;
	return m_Mutex.try_lock() == 0;
}

void CMutex::UnLock(void)
{
	m_bLocked = false;
	m_Mutex.unlock();
	
}
