#include "DataStructuresAndAlgorithmsAddSTL/STL/CStudyList.h"
#include <iostream>

CStudyList::CStudyList():
	m_iTestList(),m_strMyname("")
{

}
CStudyList::CStudyList(std::string strMyName)
	:m_iTestList(), m_strMyname(strMyName)
{

}
CStudyList::~CStudyList()
{

}

void CStudyList::AddElementToList(int iElement)
{
	m_iTestList.push_back(iElement);
}

void CStudyList::PrintElementList()
{
	std::list<int>::iterator it;
	for (it = m_iTestList.begin();it != m_iTestList.end();++it)
	{
		std::cout << "the list result is: " << *it << std::endl;
	}
}

void CStudyList::DeleteList()
{
	std::list<int>::iterator it;
	for (it = m_iTestList.begin(); it != m_iTestList.end();)
	{
		std::cout << "the current element of the list is: " << *it << std::endl;
		it = m_iTestList.erase(it);
	}
}
