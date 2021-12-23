#pragma once
#include "Win32.h"

#define SEM_VALUE_MAX ((int) ((~0u) >> 1 ))

class CSemaphore
{
public:
	CSemaphore(int init = 0);
	~CSemaphore();
private:
	CSemaphore& operator=(const CSemaphore& S) {}
	CSemaphore(const CSemaphore& S) ;

public:
	void Wait() const;
	int Wait_Try()const;
	int Post() const;
	int Value() const;
	void Reset(int iSetValue = 0);
private:
	HANDLE  m_handle;

};

