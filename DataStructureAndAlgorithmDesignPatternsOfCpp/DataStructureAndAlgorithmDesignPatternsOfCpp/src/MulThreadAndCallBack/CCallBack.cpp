#include"MulThreadAndCallBack/CCallBack.h"


	
//call back
	CCallBack::CCallBack()
	{
		m_iTestCall = 0;
		m_iTestCallSecond = 0;
		m_func = nullptr;
	}


	CCallBack::~CCallBack()
	{

	}

void CCallBack::StartWork()
{
	for (size_t i = 0; i < 7; i++)
	{
		NowCall();
		///sleep(2);
	}
}

void CCallBack::RegCallBack(MyCallBack fun, int iFrist, int iSecond)
{
	m_func = fun;
	m_iTestCall = iFrist;
	m_iTestCallSecond = iSecond;
}

void CCallBack::NowCall()
{
	m_func(m_iTestCall, m_iTestCallSecond);
}
