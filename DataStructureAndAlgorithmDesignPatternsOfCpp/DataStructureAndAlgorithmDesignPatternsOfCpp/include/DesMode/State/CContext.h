#pragma once
#include <iostream>

class CContext;
class CState
{
public:
	virtual ~CState() {}
	virtual void Handle(CContext* pContext) = 0;
};

class CContext
{
public:
	CContext(CState* pState) :m_pState(pState) {}
	~CContext();
	
	void Request();
	
	void ChangeState(CState* pState);

private:
	CState* m_pState;
};

