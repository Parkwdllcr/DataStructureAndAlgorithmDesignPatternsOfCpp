#include "CStudyList.h"
#include "../MulThread/cutil_box.h"
#include <iostream>


CStudyList::CStudyList():m_iTestList()
{

}

CStudyList::~CStudyList()
{

}

void CStudyList::AddElement() 
{
	
	std::cout<<"<AddElement>"<<std::endl;
	static int iCount = 0;
	if (iCount>10)
	{
		std::cout<<" iCount of AddElement is morn than 10!"<<std::endl;
		return ;
	}
	else
	{
		m_MutexList.Lock();
		for (int i =0;i !=5;i++)
		{
			m_iTestList.push_back(i);
		}
		
	}
	std::cout<<"the value of list iCout is :"<<iCount<<std::endl;
	++iCount;
	m_MutexList.UnLock();
}

void  CStudyList::DeleteAllElement() 
{
	m_MutexList.Lock();
	std::cout<<"<DeleteAllElement>"<<std::endl;
	std::list<int>::iterator it ;
	//MyMutex(m_MutexList);
	for (it = m_iTestList.begin();it != m_iTestList.end();)
	{
		std::cout << "the current element of the list is: " << *it << std::endl;
		it = m_iTestList.erase(it);
	}
	m_MutexList.UnLock();
}
 
void CStudyList::PrintAllElement()
{
	m_MutexList.Lock();
	std::cout<<"<PrintAllElemt>"<<std::endl;
	std::list<int>::iterator it;
	for (it = m_iTestList.begin();it != m_iTestList.end();++it)
	{
		std::cout << "the list result is: " << *it << std::endl;
	}
	m_MutexList.UnLock();
}



