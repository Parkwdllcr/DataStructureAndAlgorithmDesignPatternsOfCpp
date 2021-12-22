#include "CSemaphore.h"

CSemaphore::CSemaphore(int init /*= 0*/):m_handle()
{
	m_handle = CreateSemaphore(0, init, SEM_VALUE_MAX, 0);
}

CSemaphore::CSemaphore(const CSemaphore& S):m_handle()
{

}

CSemaphore::~CSemaphore()
{
	CloseHandle(m_handle);
}

void CSemaphore::Wait() const
{
	WaitForSingleObject((HANDLE)m_handle, INFINITE);
}

int CSemaphore::Wait_Try() const
{
	return ((WaitForSingleObject((HANDLE)m_handle, INFINITE) == WAIT_OBJECT_0) ? 0 : EAGAIN);
}

int CSemaphore::Post() const
{
	return (ReleaseSemaphore((HWND)m_handle, 1, 0) ? 0 : ERANGE);
}

int CSemaphore::Value() const
{
	LONG lValue = -1;
	ReleaseSemaphore((HANDLE)m_handle, 0, &lValue);
	return lValue;
}

void CSemaphore::Reset(int iSetValue /*= 0*/)
{
	CloseHandle(m_handle);
	m_handle = CreateSemaphore(0, iSetValue, SEM_VALUE_MAX, 0);
}
