#include"MulThreadAndCallBack/CStudyMulThread.h"
#include <thread>
#include <iostream>

CStudyMulThread::CStudyMulThread()
{

}

CStudyMulThread::~CStudyMulThread()
{

}

void CStudyMulThread::ThreadProc()
{
	std::cout << "the thread i = " << std::endl;
	/*for (int i = 0; i<5;i++)
	{
		std::cout << "the thread i = " << i << std::endl;
	}*/
}

//void CStudyMulThread::TestThreadSecond()
//{
//	std::thread th[10];
//	for (int i = 0; i < 10; i++)
//	{
//		//th[i] = std::thread(&CStudyMulThread::CountNumber, i, 10);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		th[i].join();
//	}
//}


//void CStudyMulThread::TestThreadFrist()
//{
//	/*std::thread a([] {
//		std::cout << "Hello, " << std::endl;
//	}), b(&CStudyMulThread::ThreadProc);*/
//
//	/*a.join();
//	b.join();*/
//}

//void CStudyMulThread::TestThreadThrid()
//{
//	std::thread th[100];
//	int iNums[100];
//	for (int i = 0; i < 10; i++)
//	{
//		//here std::ref is very important 
//		th[i] = std::thread(&CStudyMulThread::ChangeValue<int>, std::ref(iNums[i]), i + 1);
//		th[i].join();
//
//	}
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	th[i].join();
//	//	std::cout << "the iNumes value is: "<<iNums[i] << std::endl;
//	//}
//}

void CStudyMulThread::CountNumber(int id, unsigned int n)
{
	for (unsigned int i = 0; i < n; ++i);//just for delay
	std::cout << "Thread " << std::endl;
	std::cout << id << std::endl;
	std::cout << "finish!" << std::endl;
}

void CStudyMulThread::CountNumberSecond()
{
	for (int i = 0; i < 1000; i++)
	{
		++m_iNum;
	}
	//std::cout << iNum << std::endl;
}

//void CStudyMulThread::TestThreadFourth()
//{
//	std::thread  th[1000];
//	for (std::thread& x : th)
//	{
//		//overload not diff
//		x = std::thread(&CStudyMulThread::CountNumberSecond);
//	}
//	for (std::thread& x : th)
//	{
//		x.join();
//	}
//	std::cout << m_iNum << std::endl;
//}

void CStudyMulThread::CountNumberMutex()
{
	for (int i = 0; i < 10000; i++)
	{
		m_mtx.lock();
		++m_iNum;
		m_mtx.unlock();
	}
}

//void CStudyMulThread::TestThreadFifth()
//{
//	std::thread  th[1000];
//	for (std::thread& x : th)
//	{
//		x = std::thread(&CStudyMulThread::CountNumberMutex);
//	}
//	for (std::thread& x : th)
//	{
//		x.join();
//	}
//	std::cout << m_iNum << std::endl;
//}

void CStudyMulThread::CountNumberAtomic()
{
	for (int i = 0; i < 10000; i++)
	{
		++m_iAtoNum;
	}
}

//void CStudyMulThread::TestThreadSixth()
//{
//	std::thread  th[1000];
//	for (std::thread& x : th)
//	{
//		x = std::thread(&CStudyMulThread::CountNumberAtomic);
//	}
//	for (std::thread& x : th)
//	{
//		x.join();
//	}
//	std::cout << m_iAtoNum << std::endl;
//}

void CStudyMulThread::AddToList(int iNewValue)
{
	std::list<int> iTestList;
	std::mutex TestMutex;
	//Protection list
	std::lock_guard<std::mutex> Guard(TestMutex);
	iTestList.push_back(iNewValue);
}

//2.Condition lock
//#include<condition_variable>

//https://www.cnblogs.com/haippy/p/3252041.html
//use std::condition_variable waiting for data

void CStudyMulThread::FuncConsum()
{
	std::unique_lock<std::mutex> uniQueLock(m_mtx);
	if (0 != m_iMark)
	{
		//After the current thread calls wait(),
		//it will be blocked(at this time, 
		//the current thread should have acquired the lock(mutex),
		//so let's set the lock lck) until another thread calls notify_* to wake up the current thread.
		g_conSume.wait(uniQueLock);
	}
	m_iMark = 0;
	std::cout << "Consumer mark : " << m_iMark << std::endl;
	g_conProduce.notify_one();//notify one thread
}

void CStudyMulThread::FuncProducer()
{
	std::unique_lock<std::mutex> uniQueLock(m_mtx);
	if (m_iMark > 0)
	{
		g_conProduce.wait(uniQueLock);
	}
	m_iMark++;
	std::cout << "Producer mark : " << m_iMark << std::endl;
	g_conSume.notify_one();//notify one thread
}

//void CStudyMulThread::TestConditionVariable()
//{
//	std::thread thProducers[10], thConsumer[10];
//
//	for (int i = 0; i != 10; ++i)
//	{
//		thProducers[i] = std::thread(&CStudyMulThread::FuncConsum);
//		thConsumer[i] = std::thread(&CStudyMulThread::FuncProducer);
//	}
//	for (int i = 0; i != 10; i++)
//	{
//		//阻塞主线程等待线程结束
//		thProducers[i].join();
//		thConsumer[i].join();
//	}
//}

//std::async function is more than thread

//重载版本	                                             作用
//template <class Fn, class… Args>                     异步或同步（根据操作系统而定）以args为参数执行fn
//future<typename result_of<Fn(Args…)>::type>          同样地，传递引用参数需要std::ref或std::cref
//async(Fn&& fn, Args&& … args)	   

//template <class Fn, class… Args>                      异步或同步（根据policy参数而定（见下文））
//future<typename result_of<Fn(Args…)>::type>           以args为参数执行fn，引用参数同上
//async(launch policy, Fn&& fn, Args&& … args);	


//std::launch强枚举类(enum class)
//标识符	                                  实际值（以Visual Studio 2019为标准）	              作用
//枚举值：launch::async	                            0x1（1）	                                异步启动
//枚举值：launch::deferred	                        0x2（2）	                            在调用future::get、future::wait时
//                                                                                         同步启动（std::future见后文）
//特殊值：launch::async | launch::defereed	        0x3（3）	                          同步或异步，根据操作系统而定


// reference: http://www.cplusplus.com/reference/future/async/
//this is only a example about std::async
int CStudyMulThread::TestAsyncFrist()
{
	//lamda
	auto IsPrime = [](int x)
	{
		std::cout << "Calculating. Please, wait...\n";
		for (int i = 2; i < x; ++i)
		{
			if (x % i == 0)
				return false;
		}
		return true;
	};

	// call IsPrime(313222313) asynchronously:
	//I prefer to add description synchronization or mechanism description
	std::future<bool> fut = std::async(IsPrime, 313222313);

	std::cout << "Checking whether 313222313 is prime.\n";
	// ...

	bool ret = fut.get(); // waits for IsPrime to return
	if (ret) std::cout << "It is prime!\n";
	else std::cout << "It is not prime.\n";

	return 0;

}

// reference: http://www.cplusplus.com/reference/future/launch/
//这个有点意思，好好再看下

//std::future of c++ 11
//get return value by std::future 
int CStudyMulThread::TestAsyncSecond()
{

	auto PrintTen = [](char c, int ms) {
		for (int i = 0; i < 10; ++i) {
			std::this_thread::sleep_for(std::chrono::milliseconds(ms));
			std::cout << c;
		}
	};

	std::cout << "with launch::async:\n";
	std::future<void> foo = std::async(std::launch::async, PrintTen, '*', 100);
	std::future<void> bar = std::async(std::launch::async, PrintTen, '@', 10);
	// async "get" (wait for foo and bar to be ready):我的理解是他已经结束了运行，但是get的时候，返回值才有
	foo.get(); // 注：注释掉此句，也会输出'*'
	bar.get();
	std::cout << "\n\n";

	std::cout << "with launch::deferred:\n";
	foo = std::async(std::launch::deferred, PrintTen, '*', 10);
	bar = std::async(std::launch::deferred, PrintTen, '@', 100);
	// deferred "get" (perform the actual calls):
	// 注：注释掉此句，则不会输出'**********',必须要返回值，同步，，类似回调的感觉
	//没有调用print_ten这函数，如果注释掉了，get的时候才是去调用printen_ten
	//就是get同时才调用print_ten，调用完了，执行了返回值
	foo.get();
	bar.get();
	std::cout << '\n';

	return 0;
}

//看资料有一个bug，async发生阻塞现象，可以改用thread，
// future对象析构的时候，可能发生阻塞：
// 
// 1. 共享状态是通过std::async创建
// 2. 共享状态还不是ready状态
// 3. 被析构的future对象是共享状态的最后一个引用

// 如果直接使用std::async则，很有可能发生阻塞，因为其产生了临时变量future，
// 析构时发现非ready，则产生阻塞
// 当共享状态是ready时候，解除阻塞，完成析构

// 为了避免上述问题，可以延长async的返回值的生命周期，比如：将future类型对象变为返回值等
// future< int> fun()
// {
// 	auto fut1 = std::async…;
// 	return fun1;
// }

//let's look at the following example

std::future<int> CStudyMulThread::Funasync()
{
	auto aFutFrist = std::async(std::launch::async, []
	{
		std::this_thread::sleep_for(milliseconds_type(5000));
		std::cout << "work done1 !\n";
		return 1;
	});

	std::cout << "work done -implicit join on aFutFrist associated thread just ended!\n\n";

	std::cout << "Test 2 Start!" << std::endl;
	std::async(std::launch::async, [] {
		std::this_thread::sleep_for(milliseconds_type(5000));
		std::cout << "work done 2!" << std::endl;
	});

	std::cout << "this should show befor work done2!?\n " << std::endl;
	return aFutFrist;
}

void CStudyMulThread::CountBigNumber()
{
	//c++14 add ' in number is ok
//just for delay
	for (int i = 0; i < 10'0000'0000; i++);
}


//this result is not what I want to get
//I guess 1 second is too long
//six I change 1 millseconds 
void CStudyMulThread::TestAsyncFifth()
{
	std::future<void> fut = std::async(std::launch::async, &CStudyMulThread::CountBigNumber,this);
	std::cout << "Please Waiting ..." << std::endl;

	//wait for 1 seconds 
	while (fut.wait_for(std::chrono::seconds(1)) != std::future_status::ready)
	{
		std::cout << "-" << std::flush;
	}
	std::cout << std::endl << "Finished!" << std::endl;
}

void CStudyMulThread::TestAsyncSixth()
{

	std::future<void> fut = std::async(std::launch::async, &CStudyMulThread::CountBigNumber,this);
	std::cout << "Please Waiting ..." << std::endl;

	//wait for 1 millseconds 
	while (fut.wait_for(milliseconds_type(1)) != std::future_status::ready)
	{
		std::cout << "-" << std::flush;
	}
	std::cout << std::endl << "Finished!" << std::endl;
}



//2.Time points
//3.Clocks
//https://www.cnblogs.com/jwk000/p/3560086.html

//This example has well illustrated the use of async multithreading. 
//You can test std::launch::async and std::launch::deferred 
//and modify the sleep time of FetchDataFromDB and FetchDataFromFile.
//The result obtained thereby. Explain everything

void CStudyMulThread::TestAsyncThrid()
{
	auto FetchDataFromDB = [](std::string strRecvdData)
	{
		std::cout << "DB_" << strRecvdData << std::endl;
		//make sure that function takes 5 seconds to complete
		std::this_thread::sleep_for(seconds_type(3));
		//Do stuff like creating DB Connection and fetching Data

		return "DB_" + strRecvdData;
	};

	auto FetchDataFromFile = [](std::string strRecvdData)
	{
		std::cout << "File_" << strRecvdData << std::endl;
		//make sure that function takes 5 seconds to complete
		std::this_thread::sleep_for(seconds_type(5));
		//Do stuff like fetching Data File
		return "File_" + strRecvdData;
	};

	std::chrono::system_clock::time_point tStartTime = std::chrono::system_clock::now();
	std::future<std::string> ResultFromDB = std::async(std::launch::async, FetchDataFromDB, "Data");

	auto tEndTimeFrist = std::chrono::system_clock::now();
	auto diff = std::chrono::duration_cast <std::chrono::seconds> (tEndTimeFrist - tStartTime).count();
	std::cout << "Total FristTime Taken = " << diff << " Seconds" << std::endl;

	//Fetch Data from File
	std::string fileData = FetchDataFromFile("Data");

	auto tEndTimeSecond = std::chrono::system_clock::now();
	diff = std::chrono::duration_cast <std::chrono::seconds> (tEndTimeSecond - tEndTimeFrist).count();
	std::cout << "Total SecondTime Taken = " << diff << " Seconds" << std::endl;

	//Fetch Data from DB
	// Will block till data is available in future<std::string> object.
	std::string dbData = ResultFromDB.get();

	auto tEndTimeThrid = std::chrono::system_clock::now();
	diff = std::chrono::duration_cast <std::chrono::seconds> (tEndTimeThrid - tEndTimeSecond).count();
	std::cout << "Total ThridTime Taken = " << diff << " Seconds" << std::endl;

	//Combine The Data
	std::string data = dbData + " :: " + fileData;
	//Printing the combined Data
	std::cout << "Data = " << data << std::endl;
}

void CStudyMulThread::TestThisClass()
{
	//TestThreadFrist();
//TestThreadSecond();
//TestThreadThrid();
//TestThreadFourth();
//TestThreadFifth();
//TestThreadSixth();
//TestAsyncFrist();
//TestAsyncSecond();
//TestAsyncFifth();
//TestAsyncSixth();
	TestAsyncThrid();
}
