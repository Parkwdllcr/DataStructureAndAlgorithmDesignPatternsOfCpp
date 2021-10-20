#include"CPrimerPlus/3thDataProcessing/3thDataProcessing.h"

int CProcessingData::m_iStaticTest = 30;
const int CProcessingData::m_iConstStatic = 500;
const std::string CProcessingData::m_strTestName = "Chongrui.Lu";


// CProcessingData::CProcessingData()
// {
//     //注意这种初始化与赋值是不一样的，
//     //这种初始化不用再创建临时变量，从而更加高效
// }
CProcessingData::CProcessingData(int iSize):m_iSize(iSize)
{
    //注意这种初始化与赋值是不一样的，
    //这种初始化不用再创建临时变量，从而更加高效
}
CProcessingData::~CProcessingData()
{

}


void CProcessingData::TestThisClass()
{
    ComputSizeOfVar();
	PrintSomeClass(0.3);
    //这里不能Startwork，没有注册函数地址
   // StartWork();

}

void CProcessingData::ComputSizeOfVar()
{
    int iTest = INT_MAX ;
    short sTest = SHRT_MAX;
    long  lTest = LONG_MAX;
    long long llTest = LLONG_MAX;

    std::cout<<"int is"<<sizeof(int)<<" bytes"<<std::endl;
    std::cout<<"short is "<<sizeof(short)<<" bytes"<<std::endl;
    std::cout<<"long is "<<sizeof(long)<<" bytes"<<std::endl;
    std::cout<<"longlong is "<<sizeof(long long)<<" bytes"<<std::endl;

    std::cout<<"INT_MAX values:"<<" int :"<<INT_MAX<<std::endl;
    std::cout<<"SHRT_MAX values:"<<" int :"<<SHRT_MAX<<std::endl;
    std::cout<<"LONG_MAX values:"<<" int :"<<LONG_MAX<<std::endl;
    std::cout<<"LLONG_MAX values:"<<" int :"<<LLONG_MAX<<std::endl;

}

void CProcessingData::PrintSomeClass(float fTest)
{
	float fTestSecond = 2.0;
	if (0.0 != fTestSecond)
	{
		float   fTub = fTest / fTestSecond;
		std::cout << "PrintFloat value: " << fTub << std::endl;
	}
	else
	{
		std::cout << "this is a wrong value" << std::endl;
	}
}



void CProcessingData:: StudyConstChar(const char* const pConstChar,std::string strNmae)
{
    
}
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