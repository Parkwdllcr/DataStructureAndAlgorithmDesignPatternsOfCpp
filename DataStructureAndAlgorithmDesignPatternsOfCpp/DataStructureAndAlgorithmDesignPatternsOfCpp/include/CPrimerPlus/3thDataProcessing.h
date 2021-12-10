#include"CPrimerPlus/CPublicClass.h"
#include<iostream>
#include<climits>
#include<list>
#include<string>


class CStudyCPrimerPlus
{
public:
	//构造函数，重载构造函数，拷贝构造函数，赋值函数，析构函数
	CStudyCPrimerPlus();
    ~CStudyCPrimerPlus();





private:

public:
	//第三章
	template<typename T>
	void PrintAndComputer(const T& showAndSize);
    void ComputSizeOfVar();
	//重载一下各个基本类型
    void StudyConstChar(const char* pConstCharConst,std::string strName);
	void SimpleFourArithmetic(double dbTestOne,double dbTestTwo,int iCalculationType);
	double power(double dbBase, int iExponent)
	{
		try
		{
			double dbResult = dbBase;
			if (iExponent < 0)
			{
				throw "input error iExponent !";
			}

			if (iExponent == 0)
			{
				dbResult = 1.0;
			}
			else
			{
				while (iExponent != 1)
				{
					dbResult = dbResult * dbBase;
					--iExponent;
				}
			}
			return dbResult;

		}
		catch (const char* strError)
		{
			std::cout << strError << std::endl;
			return 0.0;//当作错误码
		}

	}
	void ClassToOtherClass();

public:
	//第四章
	void  GetMemory(char* pChar, int iNum);
	void  GetMemory(char** pChar, int iNum);
	char* GetMemory(int inum);
	char* GetString(void);
private:
	template<typename T>
	void ShowAndSize(const T& testVar);
	void PrintfTestFunctionFlag(std::string strFunctionNmae);

	//初始化类中的常量和static
private:
	std::list<int>          m_listTest;
    const   int m_iSize;
	static int               m_iStaticTest;
	const static int         m_iConstStatic;
	const static std::string m_strTestName;

};

template<typename T>
void CStudyCPrimerPlus::PrintAndComputer(const T& showAndSize)
{
	std::cout << "The Test Value is: " << showAndSize<< std::endl;
	std::cout << "The Test Size  is: " << sizeof(showAndSize) << std::endl;
}

template<typename T>
void CStudyCPrimerPlus::ShowAndSize(const T& testVar)
{
	std::cout << "The Test Value is: " << testVar << std::endl;
	std::cout << "The Test Size is: " << sizeof(testVar) << std::endl;
}


