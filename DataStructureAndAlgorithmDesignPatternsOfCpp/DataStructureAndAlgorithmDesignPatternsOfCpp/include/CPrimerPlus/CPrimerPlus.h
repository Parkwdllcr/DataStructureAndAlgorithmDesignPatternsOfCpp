#pragma once
#include<iostream>
#include<climits>
#include<list>
#include<string>
#include "COperation.h"
#include "CPrimerPlus/COperationAdd.h"
#include "CPrimerPlus/COperationSub.h"
#include "CPrimerPlus/COperationMul.h"
#include "CPrimerPlus/COperationDiv.h"



#define STUDY_OK    1
#define STUDY_FAIL    0

class COperation;
class COperationAdd;
class COperationSub;
class COperationMul;
class COperationDiv;

enum enComputeChar
{
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVIDE,
	MODULO
};

class CStudyCPrimerPlus
{
public:
	//构造函数，重载构造函数，拷贝构造函数，赋值函数，析构函数
	CStudyCPrimerPlus();
	CStudyCPrimerPlus(int iSize);
	CStudyCPrimerPlus(COperation* pOperation);

    ~CStudyCPrimerPlus();

private:
	//拷贝构造函数和赋值函数，如果没有用到，就不需要去写
	//分为浅拷贝和深拷贝
	//如果属性中有指针（动态内存），要使用深拷贝，
	//之后加了线程的，就使用深拷贝进行练习
	CStudyCPrimerPlus(const CStudyCPrimerPlus& otherCPrimer);
	CStudyCPrimerPlus& operator=(const CStudyCPrimerPlus& CStudyCPPObject);


public:
	//第三章
	//重载一下各个基本类型
	void SimpleFourArithmetic(double dbTestOne, double dbTestTwo, int iCalculationType);
	bool GetFourArithmeticResult(double& dbResult);

	COperation* CreateOperation(uint32_t iCount);
    void StudyConstChar(const char* pConstCharConst,std::string strName);

	template<typename T>
	int Power(T &tResult, int iExponent);
	//隐式转换或者强制转换，ADT/UD和默认类型的扩张与截断
	void ClassToOtherClass();
public:
	//第四章

	//注意这几种区别
	void  GetMemory(char* pChar, int iNum);
	void  GetMemory(char** pChar, int iNum);
	char* GetMemory(int inum);
	//得到一个野指针
	char* GetString(void);

public:
	template<typename T>
	void ShowAndSize(const T& testVar);
	void PrintfTestFunctionFlag(std::string strFunctionNmae);

	//初始化类中的常量和static
private:
	int                      m_iCout;
	std::list<int>           m_listTest;
    const int                m_iSize;
	//初始化static类型的类属性
	static int               m_iStaticTest;
	const static int         m_iConstStatic;
	const static std::string m_strTestName;
	COperation*              m_pCOperation;

};


template<typename T>
int CStudyCPrimerPlus::Power(T &tResult, int iExponent)
{
	PrintfTestFunctionFlag("CStudyCPrimerPlus::Power");
	try
	{
		T tBase = tResult;
		if (iExponent < 0)
		{
			throw "input error iExponent !";
		}

		if (iExponent == 0)
		{
			tResult = 1;
		}
		else
		{
			while (iExponent != 1)
			{
				tResult = tResult * tBase;
				--iExponent;
			}
		}
		return STUDY_OK;

	}
	catch (const char* strError)
	{
		std::cout << strError << std::endl;
		return STUDY_FAIL;
	}
}

template<typename T>
void CStudyCPrimerPlus::ShowAndSize(const T& testVar)
{
	PrintfTestFunctionFlag("CStudyCPrimerPlus::ShowAndSize");

	std::cout << "The Test Value is: " << testVar << std::endl;
	std::cout << "The Test Size is: " << sizeof(testVar) << std::endl;
}

