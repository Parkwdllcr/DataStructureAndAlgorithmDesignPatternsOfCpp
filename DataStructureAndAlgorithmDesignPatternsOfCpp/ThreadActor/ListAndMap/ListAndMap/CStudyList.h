#pragma once
#include "../MulThread/thread_mutex.h"
#include"IStudyStl.h"
#include<list>

class MyMutex
{
	public:
	MyMutex() = default;
	MyMutex(CMutex& mutex):m_MutexList(mutex)
	{
		m_MutexList.Lock();
	}
	~MyMutex()
	{
		m_MutexList.UnLock();
	}
private:
	CMutex    m_MutexList;
};

class CStudyList:public IStudyStl
{
public:
	CStudyList();
	~CStudyList();

public:
   virtual  void AddElement() ;
   virtual  void DeleteAllElement() ;
   virtual  void PrintAllElement() ;
   
private:
	std::list<int>      m_iTestList;
	CMutex    m_MutexList;

	//不开放出来
// private:
//    CStudyList(std::list<int> Templist);
//    CStudyList(const CStudyList & otherlist);
//    CStudyList& operator=(const CStudyList& other);

};

