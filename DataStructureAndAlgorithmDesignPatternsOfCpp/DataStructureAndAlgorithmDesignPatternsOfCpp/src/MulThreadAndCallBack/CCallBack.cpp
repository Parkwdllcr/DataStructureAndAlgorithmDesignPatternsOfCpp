#include"MulThreadAndCallBack/CCallBack.h"

//call back
void CProcessingData::NowCall()
{
    m_func(m_iStaticTest,m_iConstStatic);
    m_func(m_iTestCall,m_iTestCallSecond);
}

void CProcessingData::RegCallBack(MyCallBack fun,int iFrist,int iSecond)
{
    m_func = fun;
    m_iTestCall = iFrist;
    m_iTestCallSecond = iSecond;
}

void CProcessingData::StartWork()
{
    for (size_t i = 0; i < 7; i++)
    {
        NowCall();
        ///sleep(2);
    }
    
}