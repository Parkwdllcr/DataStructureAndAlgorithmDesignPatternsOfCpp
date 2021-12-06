#include"CPrimerPlus/CPublicClass.h"
#include<iostream>
#include<climits>
#include<string>
//#include <unistd.h>



const int FRISTSIZE = 5;
const int SECONDSIZE = 10;



class CProcessingData
{
public:
	//关于构造函数的初始化列表也是需要学习一下，我写的有问题，已经注释掉了，
	//有时间要研究一下
    CProcessingData();
   // CProcessingData(int iSize);
    ~CProcessingData();
public:
	enum enSimplearithmetic
	{
		ADDITION,
		SUBTRACTION,
		MULTIPLICATION,
		DIVIDE,
		MODULO
	};
public:
    void TestThisClass();

public:
	template<typename T>
	void PrintAndComputer(const T& showAndSize);
    void ComputSizeOfVar();
	//重载一下各个基本类型
    void StudyConstChar(const char* pConstCharConst,std::string strName);
	void SimpleFourArithmetic(double dbTestOne,double dbTestTwo,int iCalculationType);
	void ClassToOtherClass();
private:
	CPublicClass* m_pPublicClass;
 

//const in class
private:
    //const   int m_iSize = 100;//this is wrong,initial const member is wrong in class 
    //int m_iarray[m_iSize];//this is wrong ,do not know m_iSize 

    // Initialze member variables through the constructor initialization list,
    // but the constants in this way only belong to the object,not to the class.
    //this is very important

    //(1)use Constructor initialization list
    const   int m_iSize;
    // To get a const belonging to the class ,there are the following methods:
	//(2) this way can define any class
	static int               m_iStaticTest;
	const static int         m_iConstStatic;
	const static std::string m_strTestName;

    //(3) use enum constants
    int m_iArray[FRISTSIZE];
    int m_iTestArray[SECONDSIZE];

};

template<typename T>
void CProcessingData::PrintAndComputer(const T& showAndSize)
{
	std::cout << "The Test Value is: " << showAndSize<< std::endl;
	std::cout << "The Test Size  is: " << sizeof(showAndSize) << std::endl;

}


