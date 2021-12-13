#include"CPrimerPlus/CPrimerPlus.h"



int CStudyCPrimerPlus::m_iStaticTest = 30;
const int CStudyCPrimerPlus::m_iConstStatic = 500;
const std::string CStudyCPrimerPlus::m_strTestName = "Chongrui.Lu";


//CProcessingData::CProcessingData(int& iSize) :m_iSize(iSize), m_iArray({}),
//                                             m_iTestArray({}),m_iTestCall(0),m_iTestCallSecond(0),m_func(nullptr)
//{
//    //注意这种初始化与赋值是不一样的，
//    //初始化列表不用再创建临时变量，从而更加高效
//}

CProcessingData::CProcessingData():m_iSize(10),m_pPublicClass(nullptr)
{

}

CProcessingData::~CProcessingData()
{

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
void CStudyCPrimerPlus::ClassToOtherClass()
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


//All commented out are wrong
void CFourthComplexDataType::TestFourthComplexDataType()
{
	std::cout << "test this void CFourthComplexDataType::GetMemory(char* pChar, int iNum)" << std::endl;
	size_t iSize = 0;
	char* pChar = nullptr;
	GetMemory(pChar, 100);//pChar ��Ȼ����nullptr
	iSize = sizeof(pChar);
	std::cout << "pChar size is :" << iSize << std::endl;
	//std::strcpy(pChar,"hello");//����ʱ�����why?

	//std::cout << "test this void CFourthComplexDataType::GetMemory(char** pChar, int iNum)" << std::endl;
	//char* pStr = nullptr;
	//GetMemory(&pStr, 100);
	//iSize = sizeof(pStr);
	//std::cout << "pStr size is :" << iSize << std::endl;
	//strcpy(pStr, "hello");//this is ok
	//iSize = sizeof(pStr);
	//std::cout << "after strcpy pStr size is :" << iSize << std::endl;
	//std::cout << "after strcpy Value of pStr is :" << pStr << std::endl;
	//free(pStr);//�ɶԳ���malloc/free

	//std::cout << "test this char* CFourthComplexDataType::GetMemory(int inum)" << std::endl;
	//char* pChar3 = nullptr;
	//pChar3 = GetMemory(100);
	//iSize = sizeof(pChar3);
	//std::cout << "before strcpy pChar3 size is :" << iSize << std::endl;
	//strcpy(pChar3,"hellolcr");
	//iSize = sizeof(pChar3);
	//std::cout << "after strcpy pChar3 size is :" << iSize << std::endl;
	//std::cout << "after strcpy Value of pChar3  is :" << pChar3 << std::endl;
	//free(pChar3);

	//std::cout << "test this char* CFourthComplexDataType::GetString(void)" << std::endl;
	//char* pCharGetString = nullptr;
	//pCharGetString = GetString();
	//iSize = sizeof(pCharGetString);
	//std::cout << "PCharGetString size is :" << iSize << std::endl;
	//std::cout << "Value of PCharGetString  is :" << pCharGetString << std::endl;

	//std::cout << "test this char* CFourthComplexDataType::GetStringSecond(void)" << std::endl;
	//char* pCharGetStringSecond = nullptr;
	//pCharGetStringSecond = GetStringSecond();
	//iSize = sizeof(pCharGetStringSecond);
	//std::cout << "pCharGetStringSecond size is :" << iSize << std::endl;
	//std::cout << "Value of pCharGetStringSecond  is :" << pCharGetStringSecond << std::endl;

}

//this is wrong ,pChar will create a copier ,so get a wrong ptr!
void CFourthComplexDataType::GetMemory(char* pChar, int iNum)
{
	pChar = (char*)std::malloc(sizeof(char) * iNum);
}
//this is right
void CFourthComplexDataType::GetMemory(char** pChar, int iNum)
{
	*pChar = (char*)std::malloc(sizeof(char) * iNum);
}

//this is wrong!! get a wild ptr
//delete a temporary variables，ptr donot delete
char* CFourthComplexDataType::GetMemory(int inum)
{
	char* pChar = (char*)std::malloc(sizeof(char) * inum);
	return pChar;
}

char* CFourthComplexDataType::GetString(void)
{
	char pCharArray[] = "hello world";
	//返回的是临时变量的地址是有问题的！
	return pCharArray;
}

//char* CFourthComplexDataType::GetStringSecond(void)
//{
//	//char* pChar = "hello world";//�����д���
//	//return pChar;
//}

#include "CPrimerPlus/CPublicClass.h"

void CPublicClass::PrintfTestFunctionFlag(std::string strFunctionNmae)
{
	std::cout << "<------------------------------------>" << std::endl;
	std::cout << strFunctionNmae << std::endl;
}
