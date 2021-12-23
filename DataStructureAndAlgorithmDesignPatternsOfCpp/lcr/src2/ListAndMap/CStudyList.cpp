#include "ListAndMap/CStudyList.h"
#include "UtilsBox/utilsbox_utils.h"
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
	{
		MyMutex(m_MutexList);
		for (size_t i = 0; i < 10; i++)
		{
			m_iTestList.push_back(i);
		}
	}
	std::cout<<"the value of list iCout is :"<<iCount<<std::endl;
	++iCount;
}

void  CStudyList::DeleteAllElement() 
{
	std::cout<<"<DeleteAllElement>"<<std::endl;
	std::list<int>::iterator it;
	MyMutex(m_MutexList);
	for (it = m_iTestList.begin(); it != m_iTestList.end();)
	{
		std::cout << "the current element of the list is: " << *it << std::endl;
		it = m_iTestList.erase(it);
	}
}
 
void CStudyList::PrintAllElement()
{
	std::cout<<"<PrintAllElemt>"<<std::endl;
	std::list<int>::iterator it;
	MyMutex(m_MutexList);
	for (it = m_iTestList.begin();it != m_iTestList.end();++it)
	{
		std::cout << "the list result is: " << *it << std::endl;
	}
}



