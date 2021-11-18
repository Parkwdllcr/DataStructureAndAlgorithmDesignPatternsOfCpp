#include "DataStructuresAndAlgorithmsAddSTL/STL/CStudyList/CStudyList.h"
#include "CPrimerPlus/PublicClass/CPublicClass.h"
#include <iostream>

CStudyList::CStudyList() :m_iTestList({})
{
	m_pPublicClass = new CPublicClass;
}

CStudyList::~CStudyList()
{
	if (nullptr != m_pPublicClass)
	{
		delete m_pPublicClass;
		m_pPublicClass = nullptr;

	}
}

void CStudyList::AddElementToList(int iElement)
{
	m_pPublicClass->PrintfTestFunctionFlag("void CStudyList::AddElementToList(int iElement)");
	m_iTestList.push_back(iElement);
}

void CStudyList::PrintElementList()
{
	m_pPublicClass->PrintfTestFunctionFlag("void CStudyList::PrintElementList()");

	std::list<int>::iterator it;
	for (it = m_iTestList.begin();it != m_iTestList.end();++it)
	{
		std::cout << "the list result is: " << *it << std::endl;
	}
}

void CStudyList::DeleteList()
{
	m_pPublicClass->PrintfTestFunctionFlag("void CStudyList::DeleteList()");
	std::list<int>::iterator it;
	for (it = m_iTestList.begin(); it != m_iTestList.end();)
	{
		std::cout << "the current element of the list is: " << *it << std::endl;
		it = m_iTestList.erase(it);
	}
}
