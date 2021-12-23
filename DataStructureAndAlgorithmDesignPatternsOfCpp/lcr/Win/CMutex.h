#pragma once
#include "Win32.h"

class CMutex
{
public:
	CMutex();
	~CMutex();

private:
	CMutex(const CMutex& mutex);
	CMutex& operator=(CMutex& cmutex);

public:
	void Lock() const;
	void UnLock() const;

#if (_WIN32_WINNT >= 0x0400)
	int Lock_Try() const;
#endif

private:
	mutable CRITICAL_SECTION  m_CritalSection;
};

