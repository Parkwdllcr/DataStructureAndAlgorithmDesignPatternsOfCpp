#include "DesMode/State/CContext.h"

CContext::~CContext()
{
	delete m_pState;
	m_pState = nullptr;
}

void CContext::Request()
{
	{
		if (nullptr != m_pState)
			m_pState->Handle(this);
	}
}

void CContext::ChangeState(CState* pState)
{
	if (nullptr != m_pState)
	{
		delete m_pState;
		m_pState = nullptr;
	}
	m_pState = pState;
}
