
#include"MulThreadAndCallBack/CCallBackReceiver.h"
#include"MulThreadAndCallBack/CCallBack.h"
#include<iostream>


CCallBackReceiver::CCallBackReceiver(void)
{
    m_pCaller = new CProcessingData;
}

CCallBackReceiver::~CCallBackReceiver(void)
{
    if (m_pCaller != nullptr)
    {
       delete m_pCaller;
       m_pCaller = nullptr;
    }
}

   void CCallBackReceiver::WorkFunction(void)
   {
       //将CCallBackReceiver类里面的函数注册到CPrimerPlus类里面了，
       //这一步还只是注册，就是函数的指针注册到了RegCallBack
       //之后只要操作这个地址就可以了
       m_pCaller->RegCallBack(OnCalBack,7,9);
       //这里是运行,这个运行的时间是根据接受者定的
       m_pCaller->StartWork();

   }
   void CCallBackReceiver:: OnCalBack(int iA,int iB)
   {
       std::cout<<iA<<std::endl<<iB<<std::endl;
       std::cout<<"this is our CallBack function being call !!"<<std::endl;

   }