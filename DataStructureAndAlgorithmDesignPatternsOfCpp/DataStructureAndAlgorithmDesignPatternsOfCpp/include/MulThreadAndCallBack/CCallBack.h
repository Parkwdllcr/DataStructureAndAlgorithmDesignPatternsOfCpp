#pragma once

	//study call back 
//(1)声明一个callback，typedef一个
//(2)注册一个callback，功能函数的指针注入到到这个申明的callback
//(3)那么我想在什么时候去运行这个功能，就看具体情况了。
//也就是功能函数和调用者是分开的，

// 1、定义一个函数（普通函数即可）；
//在这里就是在CCallBackReceiver中的OnCalBack
// 2、将此函数的地址注册给调用者；
// 3、特定的事件或条件发生时，调用者使用函数指针调用回调函数。

typedef void (*MyCallBack)(int a,int b);

class CCallBack
{

public:
	void StartWork();
	void RegCallBack(MyCallBack fun, int iFrist, int iSecond);
	void NowCall();//work 
private:
	int  m_iTestCall;
	int  m_iTestCallSecond;
	MyCallBack m_func;
};
