#pragma once
#include "CContext.h"

class CConcreteStateA :
	public CState
{
public:
	CConcreteStateA();
	~CConcreteStateA();
public:
	void Handle(CContext* pContext);
};

class CConcreteStateB :
	public CState
{
public:
	CConcreteStateB();
	~CConcreteStateB();
public:
	void Handle(CContext* pContext);
};

