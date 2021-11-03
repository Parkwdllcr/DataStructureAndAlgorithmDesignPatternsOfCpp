#include<iostream>
#include<climits>
#include<string>
//#include <unistd.h>



const int FRISTSIZE = 5;
const int SECONDSIZE = 10;
typedef void (*MyCallBack)(int a,int b);

enum enSimplearithmetic
{
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVIDE,
	MODULO
};

class CProcessingData
{
public:
	//关于构造函数的初始化列表也是需要学习一下，我写的有问题，已经注释掉了，
	//有时间要研究一下
    CProcessingData();
   // CProcessingData(int iSize);
    ~CProcessingData();

public:
    void TestThisClass();

public:
    void ComputSizeOfVar();
	//重载一下各个基本类型
    void StudyConstChar(const char* const pConstChar,std::string strNmae);
	void SimpleFourArithmetic(double dbTestOne,double dbTestTwo,int iCalculationType);
	void ClassToOtherClass();
 

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

    //study call back 
    //(1)声明一个callback，typedef一个
    //(2)注册一个callback，功能函数的指针注入到到这个申明的callback
    //(3)那么我想在什么时候去运行这个功能，就看具体情况了。
    //也就是功能函数和调用者是分开的，

    // 1、定义一个函数（普通函数即可）；
    //在这里就是在CCallBackReceiver中的OnCalBack
    // 2、将此函数的地址注册给调用者；
    // 3、特定的事件或条件发生时，调用者使用函数指针调用回调函数。
public:
    void StartWork();
    void RegCallBack(MyCallBack fun,int iFrist,int iSecond);
    void NowCall();//work 
private:
    int  m_iTestCall;
    int  m_iTestCallSecond;
    MyCallBack m_func;

};



