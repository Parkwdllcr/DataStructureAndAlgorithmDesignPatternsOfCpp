Waiting for an event or other condition
背景
	经常遇到的一种需要线程同步的场景是一个线程A需要等待另一个线程B完成一些操作之后才能往下运行处理。
解决方案
 1.设置一个多个线程都能访问到的变量V，在B线程完成自己的操作之后将变量V设置为某个值X（需要互斥锁），而线程A不断的去检测变量V的值，一直到满足条件才继续往下执行，否则就一直循环的去检查这个变量V的值
 
 2. 方法1的改进，A线程Sleep一段时间再去检查变量V的值

bool flag;
std::mutex m;
void wait_for_flag()
{
	std::unique_lock<std::mutex> lk(m);
	while (!flag)
	{
		lk.unlock();
		std::this_thread::sleep_for(std::chrono::microseconds(100));
		lk.lock();

	}
}

缺点
 1. A不断的执行检查变量值很浪费CPU处理时间
 2. 线程A，B访问全局变量V的时候都需要加锁
 3. 通过Sleep方法进行，Sleep时间并不好判断，而且这种方法对于实时性或是要求快速响应的程序并不合适


互斥量 - mutex
boost提供了如下四种语义的互斥量(mutex)：
1. boost::mutex：独占的互斥量，不能递归使用
2. boost::timed_mutex：带超时的独占互斥量，不能递归使用
3.  boost::recursive_mutex：递归互斥量
4. boost::recursive_timed_mutex：带超时的递归互斥量
	这些互斥量的基本接口很相似，一般用法是通过lock()方法来阻塞线程，直到获得互斥量的所有权为止。在线程获取互斥量并完成任务之后，必须使用unlock()方法来释放互斥量，lock()和unlock()必须成对出现。
	try_lock()尝试锁定互斥量，如果成功返回true，如果失败返回false，它是非阻塞的。

基本用法
std::mutex g_lock;
void wait_for_flag()
{
	g_lock.lock();
	std::cout << "Enter thread !" << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::microseconds(1000));
	std::cout << "leaving thread !" << std::this_thread::get_id() << std::endl;
	g_lock.unlock();
}


互斥量 – lock_guard
 1. 使用lock_guard可以简化lock/unlock的写法，同时也更安全，因为lock_guard在构造时会自动锁定互斥量，而在退出时会进行析构触发自动解锁，从而保证互斥量正常释放，避免忘记unlock()的调用。
 2. lock_guard用到了RAII技术，在构造函数中分配资源，在析构函数中释放资源，保证资源在离开作用域后就释放。上面的例子使用lock_guard代码也会更加简洁

std::mutex g_lock;
void wait_for_flag()
{
	std::lock_guard<std::mutex> lock(g_lock);
	std::cout << "Enter thread !" << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::microseconds(1000));
	std::cout << "leaving thread !" << std::this_thread::get_id() << std::endl;
}

递归的独占互斥量 – recursive_mutex
	递归锁允许同一线程多次获得该互斥锁，可以用来解决同一线程需要多次获取互斥量时死锁的问题。
死锁
	mutex lock;				
	void foo {				 void bar() { 	
		lock.lock();				lock.lock();
		// do work				foo();
		lock.unlock();				lock.unlock();
	}					}

foo函数和bar函数都获取了同一个锁，而bar函数又会调用foo函数。这段代码会导致程序死锁。


struct Complex 
{
	std::recursive_mutex mutex;
	int  i;

	void mul(int x)
	{
		std::lock_guard<std::recursive_mutex> lock(mutex);
		i *= x;
	}
	void div(int x)
	{
		std::lock_guard<std::recursive_mutex> lock(mutex);
		i /= x;
	}
	void both(int x, int y)
	{
		std::lock_guard<std::recursive_mutex> lock(mutex);
		mul(x);
		div(y);
	}

};

因为同一个线程可以多次获取同一互斥量，不会发生死锁
递归的独占互斥量 – recursive_mutex
缺点
 1. 需要用到递归锁的多线程互斥处理本身就是可以简化的，使用递归互斥锁很容易导致代码逻辑变的复杂
 2. 递归锁比非递归锁效率要低
 3. 递归锁虽然允许同一线程多次获得同一互斥量，可重复获得的最大次数并未具体说明，一旦超过某一数值，再进行lock()操作会抛出std::system异常




带超时的互斥量 – timed_mutex
 1. timed_mutex和recursive_timed_mutex是带超时的互斥量，主要用在获取锁时的等待功能，因为有时候并不能提前预知获取锁需要多久，为不至于一直等待获取互斥量，就设置一个等待超时时间

 2. 相比于前面的几个互斥量，timed_mutex多了两个超时获取锁的接口try_lock_for和try_lock_until，这两个接口用来设置获取互斥量的时间

std::timed_mutex timemutex;
void work()
{
	std::chrono::milliseconds timeout(100);

	while (true)
	{
		if (timemutex.try_lock_for(timeout))
		{
			std::cout<<std::this_thread::get_id()<<":do work with the metux"<<std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
			timemutex.unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
		}
		else
		{
			std::cout << std::this_thread::get_id() << ":do work without the metux" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}

在这个例子中，通过一个while循环不断的尝试获取锁，如果已经超时还没获取到锁
就休眠100ms

相比timed_mutex, recursive_timed_mutex多了递归锁的用法，允许同一线程多次获得
互斥量



条件变量 – condition_variable
条件变量是另外一种用于等待的同步机制，它能阻塞一个或多个线程，直到收到另外一个线程发出的通知或者超时，才会唤醒当前被阻塞的线程，条件变量需要和互斥量配合使用，boost提供了两种条件变量：
 1. condition_variable：配合boost::unique_lock<boost::mutex>进行wait操作，此处必须使用unique_lock而不能使用lock_guard，因为condition_variable内部实现中需要多次调用lock和unlock
 2. condition_variable_any：可以配合带有lock，unlock语义的mutex使用，比较灵活，但效率相比condition_variable要低

条件变量 – condition_variable

使用方法
 1. 拥有条件变量的线程获取互斥量
 2. 循环检查某个条件，如果条件不满足，则阻塞直到条件满足；如果条件满足则向下执行
 3. 某个线程满足条件执行完之后调用notify_one或notify_all唤醒一个或者所有的等待线程

std::mutex m_mutex;//互斥锁
int s = 0;//共享资源
std::condition_variable m_notempty;//条件变量
void producer()//生产者
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::microseconds(1000));
		m_mutex.lock();
		s++;
		std::cout << "increase one,s = " << s << std::endl;
		m_mutex.unlock();
		m_notempty.notify_one();
	}
}

void consumer()//消费者
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::microseconds(1000));
		std::unique_lock<std::mutex> locker(m_mutex);
		while (s == 0)
		{
			m_notempty.wait(locker);
			s--;
			std::cout << "decrease one,s = " << s << std::endl;
		}
	}
}

int main()
{
	std::thread thread1(producer);
	std::thread thread2(consumer);
	thread1.join();
	thread2.join();
}

上面的例子中，while (s == 0) m_notempty.wait(locker)，这两行代码表面当s为0的时候阻塞当前线程，直到条件满足时被唤醒。上面的两行代码可以用下面一行代码替换：
m_notempty.wait(locker, [] { return s > 0; });
将判断条件作为lambda表达式传入wait的第二个参数，直到s大于0时被唤醒，否则一直处于阻塞状态



原子变量 – atomic<T>
boost提供了一个原子类型boost::atomic<T>，可以使用任意类型作为模板参数，使用原子变量就不需要使用互斥量来保护该变量了，因为对该变量的操作保证是原子的，是不可中断的

T的要求
	1. 标量类型，（算数，枚举，指针）
	2. 只有平凡拷贝/转移构造、赋值和析构函数的类，并且可以使用memcmp执行比操作，通常这样的类都是pod
注：int memcmp(const void *buf1, const void *buf2, unsigned int count);
比较内存区域buf1和buf2的前count个字节。


写一个计数器，使用mutex版本

struct Counter
{
public:
	std::mutex mutex;
	int  value;

	void increment()
	{
		std::lock_guard<std::mutex> lock(mutex);
		value++;
	}
	void decrement()
	{
		std::lock_guard<std::mutex> lock(mutex);
		value--;
	}
	int get()
	{
		return value;
	}

};

Counter内部使用int类型来保存计数，同时
为了满足多线程的要求，需要对计数器的修改
加锁，而加锁是需要耗时的，会对程序的性能
有影响

使用原子变量atomic版本

struct Counter
{
public:
	std::atomic<int>  value;

	void increment()
	{
		value++;
	}
	void decrement()
	{
		value--;
	}
	int get()
	{
		return value;
	}
};

Counter内部使用atomic类型来保存计数，
由于对atomic类型的操作都是原子的，
所以不需要再使用互斥量，代码更加简洁，
减少出错机会




call_once
某些场景下，我们需要代码被执行一次，比如单例类的初始化，考虑到多线程安全，需要使用锁进行保护。boost提供的call_once可以很好的满足 这种需求

Template <class Fn, class… Args>
void call_once(once_flag& flag, Fn&& fn, Args&& … args);

第一个参数是boost::once_flag对象，第二个参数是可调用方法，即要求只执行一次的代码，后面的可变参数列表为函数参数

1. call_once保证函数fn只被执行一次，如果有多个线程同时执行函数fn的调用，则只有一个活动线程（active call）会执行fn函数，其他的线程在这个线程执行返回之前会处于被动执行状态（passive execution），直到活动线程对fn的调用返回之前才返回
2. 对于所有调用函数fn的并发线程，数据可见性都是一致的
3. 如果活动线程在执行fn时抛出异常，则会从被动执行状态的线程中挑一个线程作为活动线程继续执行fn，以此类推
4. 一旦活动线程返回，所有被动执行状态的线程也返回，不会成为活动线程，once_flag相当于一个锁，使用它的线程都会在上面等待，只有一个线程允许执行。

示例
static boost::once_flag once_flag;
singleton* singleton::instance;
singleton* singleton::get_instance() {
	boost::call_once(once_flag, 
	[&] () { instance = new singleton(); }
	);
	return instance;
}

需要注意的一点是once_flag的生命
周期，它必须要比使用它的线程的
生命周期要长，所以建议定义成
全局变量


unique_lock与lock_guard差异
1. unique_lock和lock_guard两种数据结构是对lock和unlock的简单封装，用以实现退出作用域自动unlock功能
2. unique_lock和lock_guard都能实现自动加锁和解锁功能，但unique_lock要比lock_guard更灵活，灵活的代价是占用的空间更大一些耗时相对更多

示例 – 线程安全的队列

template <typename T>		     
class Queue				       
{						          
public:						      
	void insert(T val);			 
	void pop(T& val);		     
	bool is_empty() const;

private:			
	mutable mutex mutx;	
	std::queue<T> queue;		
	condition_variable cond;		
};


template <typename T>
void Queue::insert(T val)
 {
   lock_guard<mutex> lk(mutx);
   queue.push_back(val);
    cond.notify_one();
}

template <typename T>		
void Queue::pop(T& val)
{
	unique_lock<mutex> lk(mutx);
	cond.wait(lk, [this] {return !queue.empty();});
	val = queue.front();
	queue.pop();
}


template <typename T>		
void Queue::is_empty() const
{
	lock_guard<mutex> lk(mutx);
	return queue.empty();
}


unique_lock与lock_guard差异
 1. 如果只是为了保证数据同步，那么lock_guard完全够用
 2. 如果出了同步，还需要使用condition_variable进行阻塞时，那么就需要使用unique_lock，unique_lock相对lock_guard更灵活的地方在于在等待中的线程如果在等待期间需要释放锁，并在之后重新上锁，lock_guard并不具备这样的功能





Waiting for one-off events with futures
背景
	one-off就是只需要等一次的事件，boost针对这种场景提供了future模型。如果一个线程需要等待一个只会发生一次的事件，它就可以获取一个包含这个event的future，其它线程可以把future设置为ready状态，这样等待future的线程就可以知晓并接着进行处理。future一旦ready就不能重新设置了（不会再变成unready状态）
	    boost提供了两种future：unique_future，shared_future

背景
	最常见的一种one-off event的场景就是开启一个线程进行后台的计算，而主线程去做别的事情，之后再等这个计算结果出来。然而boost::thread并没有什么方法能获取线程函数的返回值。针对这种场景的解决方案：boost::async
future三种状态
ready
timeout
deferred


从后台线程获取返回值
	boost::async和线程拥有同样的功能，但是它会返回一个future，这个future就带有线程函数的返回值，可以通过future.get()来获取这个值，get()函数在线程函数结束之前一直阻塞
#include <future>

int find_the_answer_to_ltuae();
void do_other_stuff();
int main()
{
	std::future<int> the_answer = std::async(find_the_answer_to_ltuae);
	do_other_stuff();
	std::cout << "the answer is = " << the_answer.get() << std::endl;
}

async和thread一样，可以在构造的时候给线程函数传参


struct X
{
	void foo(int, std::string const&);
	std::string bar(std::string const&);
};
X x;
auto f1 = std::async(&X::foo, &x, 42, "Hello");
auto f2 = std::async(&X::bar, x, "goodbay");
struct Y
{
	double operator()(double);
};

Y y;
auto f3 = std::async(Y(), 3.14);
auto f4 = std::async(std::ref(y), 2.718);
X baz(X&);
std::async(baz,std::ref(x));

class move_only
{
public:
	move_only();
	move_only(move_only&&);
	move_only(move_only const&) = delete;
	move_only& operator=(move_only&&);
	move_only& operator=(move_only const&) = delete;
	void operator()();
};
auto f5 = std::async(move_only());

何时启动线程函数
	async是在构造函数完成后启动线程函数还是在future.get()被调用的时候才启用线程函数，这是取决于编译器供应商的实现，c++标准并没有规定，但是你可以通过指定参数：boost::launch::async（立即启动新线程）或者boost::launch::deferred（等到wait或get函数被调用时才启动线程函数）
auto f6 = std::async(std::launch::async,Y(),1,2); 
auto f7 = std::async(std::launch::deferred,baz,std::ref (x));
auto f8 = std::async(
	std::launch::deferred | std::launch::async, baz, std::ref(x));
auto f9 = std::async(baz, std::ref(x));
f7.wait();




Associating a task with a future
背景
	将future与并行任务关联的方法除了使用boost::async之外，还可以使用boost::packaged_task，或者boost::promise，其中packaged_task是promise的高层次抽象
	packaged_task可以把任务（task，函数或者函数对象等可以调用的对象）与future关联起来，当packaged_task被调用的时候，它就会调用自己所包装的任务，并在可调用对象返回时把值设置到future中

背景
	将packaged_task的模板参数与boost::function的类似，是可调用对象的类型签名（void()，int(std::string&, double*)）之类的，但参数部分是用来进行并行任务的进程函数的参数列表，返回值则是从future.get中得到
template<>
class packaged_task<std::string(std::vector<char>*, int)>
{
public:
	template<typename Callable>
	explicit packaged_task(Callable&& f);
	std::future<std::string> get_future();
	void operator()(std::vector<char>*,int);
};


任务包装
	packaged_task是个可调用的对象，因此它也可以被封装在boost::function中，或者使用在boost::thread中表示一个线程的执行函数，或者是在别的函数中调用，调用完之后它会把返回值作为异步的结果放在所关联的future中。所以使用的时候，我们可以把一个需要执行的任务包装在packaged_task中，然后获取它的future之后，把这个包装好的任务传递给其他线程，等我们需要这个任务的返回值的时候，我们就可以等待future变成ready状态

std::mutex x;
std::deque<std::packaged_task<void()>> tasks;
bool gui_shutdown_message_received();
bool get_and_process_gui_message();
void gui_thread()
{
	while (!gui_shutdown_message_received())
	{
		get_and_process_gui_message();
		std::packaged_task<void()> task;
		if (tasks.empty())
		{
			continue;
		}
		task = std::move(tasks.front());
		tasks.pop_front();
		task();
	}	
}

std::thread gui_bg_thread(gui_thread);
template<typename Func>
std::future<void> post_task_for_gui_thread(Func f)
{
	std::packaged_task<void()> task(f);
	std::future<void> res = task.get_future();
	std::lock_guard<std::mutex> lk(m);
	tasks.push_back(std::move(task));
	return res;
}



Making promise
背景
	有的时候我们在异步获取值的时候，并不能总是“获取一个可调用对象的返回值”这么简单，在这些场景下，我们不一定能包装成一个可调用对象，或者我们需要在一个函数获取多种不同类型的返回，这时packaged_task就不好用了，这种情况下我们可以使用boost::promise。总的来说，promise/future与packaged_task/future的关系是类似的，我们也可以从一个promise关联获取一个future

void process_connect(connect_set& connections)
{
	while (!done(connections))
	{
		for (connection_iterator connection = connections.begin(),end = connections.end();connection !=end;++connection)
		{
			if (connection->has_incoming_data())
			{
				data_packet data = connection->incoming();
				std::promise<payload_type>& p = connection->get_promise(data.id);
				p.set_value(data.payload);
			}
			if (connection->has_outgoing_data())
			{
				outgoing_packet data = connection->top_of_outgoing_queue();
				connection->send(data.payload);
				data.promise.set_value(true);
			}
		}

	}
}

当调用promoise的set_value成员
函数的时候，它所关联的future的
值就会被设定为ready状态



Saving an exception for the future
背景
	在上面的例子中，我们都没有提到异常的情况。虽然future与async/packaged_task/promise的场景大部分是多线程，但标准仍然提供了一个像“单线程环境”中的异常那样比较符合我们想象的处理方法：当async/packaged_task/promise发生异常时，可以把一场保存在future中，等另一个线程调用future和get/wait函数时，再把这个异常重新抛出。async/packaged_task的情况下，我们不需要额外的处理，如果抛出异常我们需要调用set_exception而不是set_value

extern std::promise<double> some_promise;

try
{
	some_promise.set_value(calculate_value());
}
catch (...)
{
	some_promise.set_exception(std::current_exception());
}

如果promise的set_value函数没有被调用，或者packaged_task没有被调用就
被析构了的话，库会把异常（future_error）存在future中，并把future状态
设置为ready




Waiting from multiple threads
背景
	future的资源占有方式是unique的，只能在一个线程中获取（moveable）。如果有多个线程需要获取future的话，必须使用shared_future（copyable）


Waiting for a time limit

背景
	大体上分，boost有两种设置超时的方法
1.	设置超时的持续时间（duration-based），也就是从调用起持续的时间（一般都是xxx_for后缀的函数）
2.	设置超时的绝对时间点（absolution timeout，一般是xxx_util后缀）



Duration
时间段用chrono::duration来表示，这个类有两个模板参数，第一个表示时间的
类型（int，long，double），第二个参数是一个“分数”，表示一个单位的
duration对象是多少秒，比如：
chrono::duration<short, ratio<60, 1>> => 60s
chrono::duration<short, ratio<1, 1000>> => 1/1000s

boost定义了一些duration的typedef：nanoseconds，miscroseconds，
milliseconds，seconds，minutes，hours




Time point
chrono::time_point表示一个时间点，接受两个模板参数，第一个模板参数表示
使用的“时钟”，第二个模板参数表示“计量的单位”，例如：
chrono::time_point<chrono::system_clock, chrono::minutes>就是使用系统
时钟进行，并以分钟为单位测定的时间点。
time_point是可以与duration进行运算而得到新的time_point
auto start = std::chrono::high_resolution_clock::now();
do_something();
auto stop = std::chrono::high_resolution_clock::now();
std::cout << "do_something() took" << std::chrono::duration<double, std::chrono::seconds>(stop - start).count() << "  seconds" << std::endl;