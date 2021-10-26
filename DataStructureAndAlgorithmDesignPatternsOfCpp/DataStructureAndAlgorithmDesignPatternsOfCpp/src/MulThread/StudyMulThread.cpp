// StudyMulThread.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//https://blog.csdn.net/sjc_0910/article/details/118861539?spm=1001.2014.3001.5501
//https://blog.csdn.net/fengbingchun/article/details/104133494
//https://www.cnblogs.com/jwk000/p/3560086.html
//https://blog.csdn.net/xy_cpp/article/details/81910513
//https://blog.csdn.net/weixin_44537992/article/details/108438379

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>


//std::thread

//函数	                             作用
//void join()	                     等待线程结束并清理资源（会阻塞）
//bool joinable()	                 返回线程是否可以执行join函数
//void detach()	                     将线程与调用其的线程分离，彼此独立执行（此函数必须在线程创建时立即调用，且调用此函数会使其不能被join）
//std::thread::id get_id()	         获取线程id
//thread& operator=(thread&& rhs)	 见移动构造函数（如果对象是joinable的，那么会调用std::terminate()结果程序）


void  ThreadProc()
{
	std::cout << "the thread i = " << std::endl;
	/*for (int i = 0; i<5;i++)
	{
	    std::cout << "the thread i = " << i << std::endl;
	}*/
}

void TestThreadFrist()
{
	std::thread a([] {
		std::cout << "Hello, " << std::endl;
	}), b(ThreadProc);

	a.join();
	b.join();
}

void  countnumber(int id, unsigned int n)
{
	for (unsigned int i = 0; i < n; ++i);//just for delay
	std::cout << "Thread " << std::endl;
	std::cout << id << std::endl;
	std::cout << "finish!" << std::endl;
}

void TestThreadSecond()
{
	std::thread th[10];
	for (int i = 0;i<10;i++)
	{
		th[i] = std::thread(countnumber, i, 10);
	}
	for (int i = 0; i < 10; i++)
	{
		th[i].join();
	}
}

template<typename T>
void ChangeValue(T &x, T v)
{
	//std::cout << "before the X value is " << x << std::endl;
	//std::cout << "before the v value is " << v << std::endl;
	x = v;
	std::cout << std::this_thread::get_id() << "is Executing" << std::endl;
	//std::cout << "after the X value is " << x << std::endl;
	//std::cout << "after the v value is " << v << std::endl;
}

//I can 
void TestThreadThrid()
{
	std::thread th[100];
	int iNums[100];
	for (int i = 0; i < 10; i++)
	{
		//here std::ref is very important 
		th[i] = std::thread(ChangeValue<int>, std::ref(iNums[i]), i+1);
		th[i].join();
		
	}
	//for (int i = 0; i < 10; i++)
	//{
	//	th[i].join();
	//	std::cout << "the iNumes value is: "<<iNums[i] << std::endl;
	//}
}


//线程是在thread对象被定义的时候开始执行的，而不是在调用join函数时才执行的，
//调用join函数只是阻塞等待线程结束并回收资源。
//分离的线程（执行过detach的线程）会在调用它的线程结束或自己结束时释放资源。
//线程会在函数运行完毕后自动释放，不推荐利用其他方法强制结束线程，可能会因资源未释放而导致内存泄漏。
//没有执行join或detach的线程在程序结束时会引发异常

int g_iNum = 0;
std::mutex  g_mtx;

void CountNumber()
{
	for (int i = 0;i < 1000;i++)
	{
		++g_iNum;
	}
	//std::cout << iNum << std::endl;
}

//This is a very interesting example. 
//1000 threads are created, and then each single thread is added 1000,
//and the output is 1000000,
//but if 100 threads are opened and each thread is added to 10000,
//the output will be different each time. And they are all less than 1,000,000. 
//Explain that when using join, many threads have not yet completed the calculation of 1 to 10000.
//The most important thing is that this output is a global variable, 
//and each thread adds up to operate it. 
//I must study it carefully. 

void TestThreadFourth()
{
	std::thread  th[1000];
	for (std::thread &x : th)
	{
		x = std::thread(CountNumber);
	}
	for (std::thread &x : th)
	{
		x.join();
	}
	std::cout << g_iNum << std::endl;
}


//mutex的常用成员函数
//（这里用mutex代指对象）
//
//函数	                    作用
//void lock()	           将mutex上锁。
//                         如果mutex已经被其它线程上锁，
//                         那么会阻塞，直到解锁；
//                         如果mutex已经被同一个线程锁住，
//                         那么会产生死锁。

//void unlock()	           解锁mutex，释放其所有权。
//                         如果有线程因为调用lock()不能上锁而被阻塞，
//                         则调用此函数会将mutex的主动权随机交给其中一个线程；
//                         如果mutex不是被此线程上锁，那么会引发未定义的异常。

//bool try_lock()	       尝试将mutex上锁。
//                         如果mutex未被上锁，则将其上锁并返回true；
//                         如果mutex已被锁则返回false。


void CountNumberMutex()
{
	for (int i = 0; i < 10000; i++)
	{
		g_mtx.lock();
		++g_iNum;
		g_mtx.unlock();
	}
}

void TestThreadFifth()
{
	std::thread  th[1000];
	for (std::thread& x : th)
	{
		x = std::thread(CountNumberMutex);
	}
	for (std::thread& x : th)
	{
		x.join();
	}
	std::cout << g_iNum << std::endl;
}

//Mutex solves the problem of multi - thread resource contention very well,
//but it also has shortcomings : too...slow......
//If we define 100 threads, each thread needs to loop 10, 000 times,
//and each loop needs to be lockedand unlocked.This will waste a lot of time, 
//so what should we do ?
//Next is the time for atomic to show its power.

std::atomic_int g_iAtoNum = 0;
void CountNumberAtomic()
{
	for (int i = 0;i<10000;i++)
	{
		++g_iAtoNum;
	}
}

void TestThreadSixth()
{
	std::thread  th[1000];
	for (std::thread& x : th)
	{
		x = std::thread(CountNumberAtomic);
	}
	for (std::thread& x : th)
	{
		x.join();
	}
	std::cout << g_iAtoNum << std::endl;
}


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

int TestAsyncFrist()
{
	auto is_prime = [](int x) 
	{
		std::cout << "Calculating. Please, wait...\n";
		for (int i = 2; i < x; ++i)
		{
			if (x % i == 0)
				return false;
		}
		return true;
	};

	// call is_prime(313222313) asynchronously:
	std::future<bool> fut = std::async(is_prime, 313222313);

	std::cout << "Checking whether 313222313 is prime.\n";
	// ...

	bool ret = fut.get(); // waits for is_prime to return
	if (ret) std::cout << "It is prime!\n";
	else std::cout << "It is not prime.\n";

	return 0;

}

///
// reference: http://www.cplusplus.com/reference/future/launch/
//这个有点意思，好好再看下

//std::future of c++ 11
//get return value by std::future 
int TestAsyncSecond()
{

	auto print_ten = [](char c, int ms) {
		for (int i = 0; i < 10; ++i) {
			std::this_thread::sleep_for(std::chrono::milliseconds(ms));
			std::cout << c ;
		}
	};

	std::cout << "with launch::async:\n";
	std::future<void> foo = std::async(std::launch::async, print_ten, '*', 100);
	std::future<void> bar = std::async(std::launch::async, print_ten, '@', 10);
	// async "get" (wait for foo and bar to be ready):我的理解是他已经结束了运行，但是get的时候，返回值才有
	foo.get(); // 注：注释掉此句，也会输出'*'
	bar.get();
	std::cout << "\n\n";

	std::cout << "with launch::deferred:\n";
	foo = std::async(std::launch::deferred, print_ten, '*', 10);
	bar = std::async(std::launch::deferred, print_ten, '@', 100);
	// deferred "get" (perform the actual calls):
	// 注：注释掉此句，则不会输出'**********',必须要返回值，同步，，类似回调的感觉
	//没有调用print_ten这函数，如果注释掉了，get的时候才是去调用printen_ten
	//就是get同时才调用print_ten，调用完了，执行了返回值
	foo.get(); 
	bar.get();
	std::cout << '\n';

	return 0;
}

template<typename T>
int ParallelSum(T beg, T end)
{
	auto len = end - beg;
	if (len<1000)
	{
		return std::accumulate(beg, end, 0);
	}

	T mid = (beg + end) / 2;
	auto handl = std::async(std::launch::async, ParallelSum<T>, mid, end);
	int sum = ParallelSum(beg, mid);
	return sum + handl.get();
}



int main()
{
	//TestThreadFrist();
	//TestThreadSecond();
	//TestThreadThrid();
	//TestThreadFourth();
	//TestThreadFifth();
	//TestThreadSixth();
	//TestAsyncFrist();
	TestAsyncSecond();
	return 0;
}

