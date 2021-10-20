#include "DesMode/State/CConcreteState.h"


CConcreteStateB::CConcreteStateB()
{

}

CConcreteStateB::~CConcreteStateB()
{

}

void CConcreteStateB::Handle(CContext* pContext)
{
	pContext->ChangeState(new CConcreteStateA());
}


CConcreteStateA::CConcreteStateA()
{

}

CConcreteStateA::~CConcreteStateA()
{

}

void CConcreteStateA::Handle(CContext* pContext)
{
	std::cout << "Handle by ConcreteStateA" << std::endl;
	if (nullptr != pContext)
		pContext->ChangeState(new CConcreteStateB());
}