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

CProcessingData::CProcessingData():m_iSize(10),m_pPublicClass(nullptr)
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
	SimpleFourArithmetic(0.3, 5.7, ADDITION);



}

void CProcessingData::ComputSizeOfVar()
{
	std::cout << "<--------------->" << std::endl;
	std::cout << "ComputSizeOfVar" << std::endl;
    int iTest = INT_MAX ;
	m_pPublicClass->ShowAndSize<int>(iTest);
    short sTest = SHRT_MAX;
	m_pPublicClass->ShowAndSize<short>(sTest);
    long  lTest = LONG_MAX;
	m_pPublicClass->ShowAndSize<long>(lTest);
    long long llTest = LLONG_MAX;
	m_pPublicClass->ShowAndSize<long long>(llTest);

}

//can add const here,because it is does not change!
//not ADT/UDT ,so not &
void CProcessingData::SimpleFourArithmetic(double dbTestOne, double dbTestTwo, int iCalculationType)
{
	std::cout << "<--------------->" << std::endl;
	std::cout << "SimpleFourArithmetic" << std::endl;
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
	std::cout << "<--------------->" << std::endl;
	std::cout << "ClassToOtherClass" << std::endl;
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
	m_pPublicClass->ShowAndSize<char>(chA);
	int iB = chA;
	m_pPublicClass->ShowAndSize<int>(iB);
	long lC = iB;
	m_pPublicClass->ShowAndSize<long>(lC);
	float fA = 10.2;
	m_pPublicClass->ShowAndSize<float>(fA);
	double dbC = fA;
	m_pPublicClass->ShowAndSize<double>(dbC);


	//2.Forced conversion
	double dbG = 10.2;
	m_pPublicClass->ShowAndSize<double>(dbG);
	int iH = (int)dbG;
	m_pPublicClass->ShowAndSize<int>(iH);

}

void CProcessingData:: StudyConstChar(const char* pConstCharConst,std::string strName)
{
	std::cout << "<--------------->" << std::endl;
	std::cout << "StudyConstChar" << std::endl;

	//const char* can not inital char*
	//char* pCh = "I am SB!";
	strName = pConstCharConst;
	std::string strToConstChar = "strToConstChar";
	m_pPublicClass->ShowAndSize<std::string>(strToConstChar);

	const char* pFromString = strToConstChar.c_str();
	m_pPublicClass->ShowAndSize<const char*>(pFromString);

	pFromString = "I am very important!!";
	m_pPublicClass->ShowAndSize<const char*>(pFromString);

	//string cann't  direct conversion to char 
	//string to char*
	std::string strToConstPtrChar = "stringToConstPtrChar";
	char* pCharFromSting = const_cast<char*>(strToConstPtrChar.c_str());
	m_pPublicClass->ShowAndSize<char*>(pCharFromSting);

}
