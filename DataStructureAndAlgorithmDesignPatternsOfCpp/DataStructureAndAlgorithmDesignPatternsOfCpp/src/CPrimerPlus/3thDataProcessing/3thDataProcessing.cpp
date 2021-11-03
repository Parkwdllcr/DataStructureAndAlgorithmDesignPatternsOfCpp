#include"CPrimerPlus/3thDataProcessing/3thDataProcessing.h"

int CProcessingData::m_iStaticTest = 30;
const int CProcessingData::m_iConstStatic = 500;
const std::string CProcessingData::m_strTestName = "Chongrui.Lu";


//CProcessingData::CProcessingData(int& iSize) :m_iSize(iSize), m_iArray({}),
//                                             m_iTestArray({}),m_iTestCall(0),m_iTestCallSecond(0),m_func(nullptr)
//{
//    //注意这种初始化与赋值是不一样的，
//    //初始化列表不用再创建临时变量，从而更加高效
//}

CProcessingData::CProcessingData():m_iSize(10)
{
	m_iArray[FRISTSIZE] = { 0 };
	m_iTestArray[SECONDSIZE] = { 0 };
	m_iTestCall = 0;
	m_iTestCallSecond = 0;
	m_func = nullptr;
}

CProcessingData::~CProcessingData()
{

}


void CProcessingData::TestThisClass()
{
    ComputSizeOfVar();
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

//can add const here,because it is does not change!
//not ADT/UDT ,so not &
void CProcessingData::SimpleFourArithmetic(double dbTestOne, double dbTestTwo, int iCalculationType)
{
	try
	{
		switch (iCalculationType)
		{
		case ADDITION:
			throw(dbTestOne + dbTestTwo);
			break;
		case SUBTRACTION:
			throw(dbTestOne - dbTestTwo);
			break;
		case MULTIPLICATION:
			throw(dbTestOne * dbTestTwo);
			break;
		case DIVIDE:
		{
			if (dbTestTwo != 0)
			{
				throw(dbTestOne / dbTestTwo);
			}
			else
			{
				throw("dbTestTwo is 0");
			}
			break;
		}
		case MODULO:
		{
			int iTestOne = 3;
			int iTestTwo = 5;
			throw(iTestOne % iTestTwo);
			break;
		}
		default:
			throw"Do not input right iCalculationType! ";
			break;
		}
	}
	catch (double& dbResult)
	{
		std::cout << "this Result: "<<dbResult << std::endl;
	}
	catch (std::string & strErr)
	{
		std::cout << "The Wrong is: " << strErr << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknow Err !" << std::endl;		
	}

}

//Implicit conversion and explicit conversion
void CProcessingData::ClassToOtherClass()
{
	
	//1. Implicit Conversion
	//char is-a int ,int is-a long,long is-a float,float is-a double,Derived class is-a base class
	//A is-a B
	//1.1 int to long
	//1.2 long to float
	//1.3 float to double
	//Derived to base class
	//Implicit Conversion is safe.
	//Promote the 100 of int to a temporary variable of double, 
	//and then assign this temporary variable to dbB
	char chA = 'C';
	std::cout << "double size is: " << sizeof(chA) << std::endl;
	int iB = chA;
	std::cout << "double size is: " << sizeof(iB) << std::endl;
	long lC = iB;
	std::cout << "double size is: " << sizeof(lC) << std::endl;
	float fA = 10.2;
	std::cout << "double size is: " << sizeof(fA) << std::endl;
	double dbC = fA;
	std::cout << "double size is: " << sizeof(dbC) << std::endl;

	//2.Forced conversion
	double dbG = 10.2;
	int iH = (int)dbG;
	std::cout << "double size is: " << sizeof(dbG) << std::endl;
	std::cout << "double size is: " << sizeof(iH) << std::endl;
	//class between there are four 




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