#pragma once
#include"CThread.h"

class IThestThread :public CThread
{
public:
	virtual ~IThestThread() {}
	virtual void TerminateThread() = 0;
};