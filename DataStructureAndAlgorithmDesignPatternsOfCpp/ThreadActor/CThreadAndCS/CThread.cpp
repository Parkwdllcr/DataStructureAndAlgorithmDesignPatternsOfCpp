#include "CThread.h"
#include <iostream>

using namespace std;

CThread::CThread()
	: _thread(nullptr),
	_pauseFlag(false),
	_stopFlag(false),
	_state(Stoped)
{

}

CThread::~CThread()
{
	stop();
}

CThread::State CThread::state() const
{
	return _state;
}

void CThread::start()
{
	if (_thread == nullptr)
	{
		_thread = new thread(&CThread::run, this);
		_pauseFlag = false;
		_stopFlag = false;
		_state = Running;
	}
}

void CThread::stop()
{
	if (_thread != nullptr)
	{
		_pauseFlag = false;
		_stopFlag = true;
		_condition.notify_all();  // Notify one waiting thread, if there is one.
		_thread->join(); // wait for thread finished
		delete _thread;
		_thread = nullptr;
		_state = Stoped;
	}
}

void CThread::pause()
{
	if (_thread != nullptr)
	{
		_pauseFlag = true;
		_state = Paused;
	}
}

void CThread::resume()
{
	if (_thread != nullptr)
	{
		_pauseFlag = false;
		_condition.notify_all();
		_state = Running;
	}
}

void CThread::run()
{
	std::cout << "enter thread:" << this_thread::get_id() << std::endl;

	while (!_stopFlag)
	{
		process();
		if (_pauseFlag)
		{
			unique_lock<mutex> locker(_mutex);
			while (_pauseFlag)
			{
				_condition.wait(locker); // Unlock _mutex and wait to be notified
			}
			locker.unlock();
		}
	}
	_pauseFlag = false;
	_stopFlag = false;

	cout << "exit thread:" << this_thread::get_id() << endl;
}
