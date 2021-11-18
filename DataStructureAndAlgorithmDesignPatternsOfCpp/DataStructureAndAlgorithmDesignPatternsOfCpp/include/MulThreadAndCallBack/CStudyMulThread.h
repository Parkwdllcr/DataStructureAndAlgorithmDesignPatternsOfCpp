// reference:https://www.cnblogs.com/jwk000/p/3560086.html
// reference: http://www.cplusplus.com/reference/future/launch/
// reference: http://www.cplusplus.com/reference/future/async/
// reference:https://www.cnblogs.com/haippy/p/3252041.html
// reference:https://blog.csdn.net/sjc_0910/article/details/118861539?spm=1001.2014.3001.5501
// reference:https://blog.csdn.net/fengbingchun/article/details/104133494
// reference:https://blog.csdn.net/xy_cpp/article/details/81910513
// reference:https://blog.csdn.net/weixin_44537992/article/details/108438379

#pragma once

#include <mutex>
#include <atomic>
#include <future>
#include <chrono>
#include <list>
#include <iostream>
#include <condition_variable>

typedef std::chrono::duration<int, std::ratio<60 * 60>>          hourse_type;
typedef std::chrono::duration<int, std::ratio<60>>               minutes_type;
typedef std::chrono::duration<int>                               seconds_type;
typedef std::chrono::duration<int, std::milli>                   milliseconds_type;
typedef std::chrono::duration<int, std::ratio<1, 1000000>>       microseconds_type;
typedef std::chrono::duration<int, std::ratio<1, 1000000000>>    nanosecons_type;

class CStudyMulThread
{
	//base function,must write them
public:
	CStudyMulThread();
	~CStudyMulThread();

public:
	void  ThreadProc();
	void  TestThreadFrist();
	void  CountNumber(int id, unsigned int n);
	void  TestThreadSecond();
	template<typename T>
	void  ChangeValue(T& x, T v);
	void  TestThreadThrid();
	void  CountNumberSecond();
	void  TestThreadFourth();
	void  CountNumberMutex();
	void  TestThreadFifth();
	void  CountNumberAtomic();
	void  TestThreadSixth();
	void  AddToList(int iNewValue);
	void  FuncConsum();
	void  FuncProducer();
	void  TestConditionVariable();
	int   TestAsyncFrist();
	int   TestAsyncSecond();
	std::future<int> Funasync();
	void  CountBigNumber();
	void  TestAsyncFifth();
	void  TestAsyncSixth();
	void  TestAsyncThrid();
	void  TestThisClass();

private:
	int                        m_iNum;
	int                        m_iCount;
	int                        m_iMark;
	std::condition_variable    g_conProduce;
	std::condition_variable    g_conSume;
	std::atomic_int            m_iAtoNum;
    std::mutex                 m_mtx;
};

template<typename T>
void CStudyMulThread::ChangeValue(T& x, T v)
{
	//std::cout << "before the X value is " << x << std::endl;
//std::cout << "before the v value is " << v << std::endl;
	x = v;
	std::cout << std::this_thread::get_id() << "is Executing" << std::endl;
	//std::cout << "after the X value is " << x << std::endl;
	//std::cout << "after the v value is " << v << std::endl;
}
