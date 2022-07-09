#include"CPrimerPlus/CPrimerPlus.h"

#include <exception>



int CStudyCPrimerPlus::m_iStaticTest = 30;
const int CStudyCPrimerPlus::m_iConstStatic = 500;
const std::string CStudyCPrimerPlus::m_strTestName = "Chongrui.Lu";


CStudyCPrimerPlus::CStudyCPrimerPlus():m_iSize(0),m_iCout(0),m_listTest(),m_pCOperation(nullptr)
{
	PrintfTestFunctionFlag("CStudyCPrimerPlus::CStudyCPrimerPlus");

}

CStudyCPrimerPlus::CStudyCPrimerPlus(int iSize):m_iSize(iSize), m_iCout(0), m_listTest(), m_pCOperation(nullptr)
{
	PrintfTestFunctionFlag("CStudyCPrimerPlus::CStudyCPrimerPlus(int iSize)");

}

CStudyCPrimerPlus::CStudyCPrimerPlus(COperation* pOperation):m_iSize(0),m_iCout(0),m_listTest(), m_pCOperation(pOperation)
{

}

CStudyCPrimerPlus::CStudyCPrimerPlus(const CStudyCPrimerPlus& otherCPrimer):m_iSize(0), m_pCOperation(nullptr)
{
	PrintfTestFunctionFlag("CStudyCPrimerPlus::CStudyCPrimerPlus(const CStudyCPrimerPlus& otherCPrimer)");

	m_iCout = otherCPrimer.m_iCout;
}



CStudyCPrimerPlus& CStudyCPrimerPlus::operator=(const CStudyCPrimerPlus& CStudyCPPObject)
{
	PrintfTestFunctionFlag("CStudyCPrimerPlus::operator=");

	//如果有动态内存，就要申请一个内存，赋值，消除内存，返回*this
	if (this != &CStudyCPPObject)
	{

	}
	return *this;
}

CStudyCPrimerPlus::~CStudyCPrimerPlus()
{
	PrintfTestFunctionFlag("CStudyCPrimerPlus::~CStudyCPrimerPlus()");

}


//can add const here,because it is does not change!
//not ADT/UDT ,so not &
void CStudyCPrimerPlus::SimpleFourArithmetic(double dbTestOne, double dbTestTwo, int iCalculationType)
{
	PrintfTestFunctionFlag("SimpleFourArithmetic");
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

bool CStudyCPrimerPlus::GetFourArithmeticResult(double& dbResult)
{
	try
	{
		m_pCOperation->GetResult(dbResult);
		return true;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	
	
}

//Implicit conversion and explicit conversion
void CStudyCPrimerPlus::ClassToOtherClass()
{
	PrintfTestFunctionFlag("ClassToOtherClass");
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
	ShowAndSize<char>(chA);
	int iB = chA;
	ShowAndSize<int>(iB);
	long lC = iB;
	ShowAndSize<long>(lC);
	float fA = 10.2;
	ShowAndSize<float>(fA);
	double dbC = fA;
	ShowAndSize<double>(dbC);


	//2.Forced conversion
	double dbG = 10.2;
	ShowAndSize<double>(dbG);
	int iH = (int)dbG;
	ShowAndSize<int>(iH);

}


COperation* CStudyCPrimerPlus::CreateOperation(uint32_t iCount)
{
	switch (iCount)
	{
	case ADDITION:
		m_pCOperation = new COperationAdd();
		break;
	case SUBTRACTION:
		m_pCOperation = new COperationSub();
		break;
	case MULTIPLICATION:
		m_pCOperation = new COperationMul();
		break;
	case DIVIDE:
		m_pCOperation = new COperationDiv();
		break;
	default:
		std::cout << "input error !" << std::endl;
		m_pCOperation = nullptr;
		break;
	}
	return m_pCOperation;
}

void CStudyCPrimerPlus:: StudyConstChar(const char* pConstCharConst,std::string strName)
{
	PrintfTestFunctionFlag("StudyConstChar");

	//const char* can not inital char*
	//char* pCh = "I am SB!";
	strName = pConstCharConst;
	std::string strToConstChar = "strToConstChar";
	ShowAndSize<std::string>(strToConstChar);

	const char* pFromString = strToConstChar.c_str();
	ShowAndSize<const char*>(pFromString);

	pFromString = "I am very important!!";
	ShowAndSize<const char*>(pFromString);

	//string cann't  direct conversion to char 
	//string to char*
	std::string strToConstPtrChar = "stringToConstPtrChar";
	char* pCharFromSting = const_cast<char*>(strToConstPtrChar.c_str());
	ShowAndSize<char*>(pCharFromSting);

}


//this is wrong ,pChar will create a copier ,so get a wrong ptr!
//类似一个传值参数，不会变化的
void CStudyCPrimerPlus::GetMemory(char* pChar, int iNum)
{
	//在函数里面用这种new不好，new完记得delete,最好是外面传进来的
	PrintfTestFunctionFlag(" CStudyCPrimerPlus::GetMemory");
	pChar = new char[iNum];
	delete[]pChar;
}

//this is right
//指针传递
//使用的时候是
//char* pChar ; 
//(&pChar,10)
void CStudyCPrimerPlus::GetMemory(char** pChar, int iNum)
{
	PrintfTestFunctionFlag(" CStudyCPrimerPlus::GetMemory");
	*pChar = new char[iNum];
}

void CStudyCPrimerPlus::GetMemory(char* pChar)
{
	PrintfTestFunctionFlag(" CStudyCPrimerPlus::GetMemory");
	std::string strTest = "Hello World!";
	memcpy(pChar,strTest.c_str(),sizeof(strTest));
}

//this is right
char* CStudyCPrimerPlus::GetMemory(int inum)
{
	PrintfTestFunctionFlag(" CStudyCPrimerPlus::GetMemory");
	char* pChar = new char[inum];
	memset(pChar, 0, sizeof(char) * inum);
	return pChar;
}

//this is wrong!! get a wild ptr
char* CStudyCPrimerPlus::GetString(void)
{
	PrintfTestFunctionFlag(" CStudyCPrimerPlus::GetString");
	char pCharArray[] = "hello world";
	//返回的是临时变量的地址是有问题的！
	return pCharArray;
}

void CStudyCPrimerPlus::PrintfTestFunctionFlag(std::string strFunctionNmae)
{
	std::cout << "<------------------------------------>" << std::endl;
	std::cout << strFunctionNmae << std::endl;
}
