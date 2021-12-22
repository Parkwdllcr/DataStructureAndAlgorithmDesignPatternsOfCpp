#include "CMutex.h"

CMutex::CMutex()
{
	InitializeCriticalSection(&m_CritalSection);
}

CMutex::CMutex(const CMutex& mutex)
{

}

CMutex& CMutex::operator=(CMutex& cmutex)
{
	return *this;
}

CMutex::~CMutex()
{
	DeleteCriticalSection(&m_CritalSection);
}

void CMutex::Lock() const
{
	EnterCriticalSection(&m_CritalSection);
}

void CMutex::UnLock() const
{
	LeaveCriticalSection(&m_CritalSection);
}

int CMutex::Lock_Try() const
{
	return (TryEnterCriticalSection(&m_CritalSection) ? 0 : EBUSY);
}
