// StudyThread2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  Example1
#ifdef Example1
#include <iostream>
#include <time.h>
#ifdef WIN32
#include "Win/CMutex.h"
#include "Win/CSemaphore.h"
#include "Win/CThread.h"
#else
#include "Posix/CMutex.h"
#include "Posix/CSemaphore.h"
#include "Posix/CThread.h"

#endif // WIN32


using namespace std;

int ii = 0;

/* the mutex that all threads will use */
CMutex ii_lock;

/* the semaphore that the Run() function waits on */
CSemaphore sem_done;

const static int rep = 1000;

/* Our class that has Thread<int>
as a base class - int is the parameter type. */
class ThreadTester : private Thread<int>
{
public:
	void Run()
	{
		/* create rep #threads with parameter i. */
		/* if this class was private Thread<void>, there would not be a */
		/* parameter. */
		/* real code should check for errors from Create(). */
		for (int i = 0; i < rep; ++i)
			Create(i, 0, true, 2048);

		/* when sem_done.Post() is called below, this wait completes */
		/* and also decrements the value of sem_done back to zero. */

		sem_done.Wait();

		/* another way to do this might be to keep a list of all */
		/* the thread handles and call Join() for each one, */
		/* but I chose this way since the
		number of threads is pre-determined. */
	}

private:
	/* the thread entry function, which is part of this object. */
	/* for Thread<void>, there would be no parameter. */
	/* i is a reference because it is copied in the _real_ thread */
	/* initialization, and so this just points to it. handy for */
	/* structs and things other than integral data types. */
	void ThreadMain(int& i)
	{
		/* get mutually exclusive access to ii */
		ii_lock.Lock();

		++ii;

		/* if this is the last created thread, increment the value */
		/* of sem_done to 1, which causes Run() to complete. */
		if (ii >= rep) sem_done.Post();

		/* let someone else pass ii_lock */
		ii_lock.UnLock();

	}
};

int main()
{
	clock_t c1, c2;
	ThreadTester Test;

	/* just to test efficiency. */
	c1 = clock();
	Test.Run();
	c2 = clock();

	/* you will notice a MAJOR speed increase from win32 to solaris. */
	/* I havent run this example on anything else, but I assume that */
	/* win32 threads are either less efficient or the creation process */
	/* is more "processor-friendly" since win32's aim isn't to create */
	/* fast but to run fast (if that's really possible for win32 :P ) */
	/* I get about ~200 for my winXP 850MHz Pentium III-M - */
	/* clocked about !!!12000!!! for SunOS 5.8 on (I believe) 4 processors. */
	/* single processor solaris - can't remeber results at the moment. */
	cout << (double)rep / ((double)(c2 - c1) / (double)CLOCKS_PER_SEC) <<
		" Threads per second!" << endl;

#ifdef WIN32
	system("pause");
#endif
	return 0;
}
#endif // Example1

/*
Example2.cpp

In this example, I will show you how to use the static thread functions
instead of writing your own class, along with how to explicitly wait
for a single thread to complete.

Win32:
Make sure to set "C/C++" -> "Code Generation" -> "Runtime Library" to
- Multi-Threaded Debug, or
- Multi-Threaded

Solaris, Linux, Unix, [Posix Compliant]:

compile as g++ Example1.cpp /usr/lib/libthread.so

sometimes it's libpthread.so... try

find /usr/lib -n "lib*thread*.so"
*/

#ifdef Example2
#include <iostream>
using namespace std;

#include "Thread.h"

/* non-class thread function */
void MyThreadProc(int& I)
{
	for (int i = 0; i < I; ++i);
}

/* Our parameter type is int */
typedef Thread<int> Thread_Int;

int main()
{
	Thread_Int::Handle H;

	/* I had to specify the explicit type of the function in order */
	/* to force the calling of the static overload. */
	if (Thread_Int::Create((Thread_Int::Handler)MyThreadProc, 100000000, &H))
	{
		cout << "Creating of thread failed!\n";
	}
	else
	{
		cout << "Waiting...\n";
		/* this returns when the thread completes */
		Thread_Int::Join(H);
		cout << "Thread is done.\n";
	}

#ifdef WIN32
	system("pause");
#endif
	return 0;
}
#endif // Example2