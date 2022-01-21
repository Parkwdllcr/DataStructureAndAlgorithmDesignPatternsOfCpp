// testptrchar.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CThread.h"
#include <string>


//可以设置成毫秒之类的
void mySleep(int s)
{
	std::this_thread::sleep_for(std::chrono::duration<double>(s));
}

class MyThread : public CThread
{
protected:
	virtual void process() override
	{
		std::cout << "do my something" << std::endl;
		mySleep(1);
	}
};

int main()
{
	MyThread thread;

	std::cout << "start thread" << std::endl;
	thread.start();
	std::cout << "thread state:" << thread.state() << std::endl;
	mySleep(3);

	std::cout << "pause thread" << std::endl;
	thread.pause();
	std::cout << "thread state:" << thread.state() << std::endl;
	mySleep(3);

	std::cout << "resume thread" << std::endl;
	thread.resume();
	std::cout << "thread state:" << thread.state() << std::endl;
	mySleep(3);

	std::cout << "stop thread" << std::endl;
	thread.stop();
	std::cout << "thread state:" << thread.state() << std::endl;
	mySleep(3);

}





