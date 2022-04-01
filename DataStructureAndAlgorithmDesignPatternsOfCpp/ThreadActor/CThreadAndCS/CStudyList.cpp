#include "CStudyList.h"
#include <iostream>


void CStudyList::AddElement()
{
	std::cout << "<AddElement>" << std::endl;
	std::lock_guard<std::mutex> lock(m_Mutex);
	if (m_iListTest.size()>10)
	{
		std::cout << " iCount of AddElement is morn than 10!" << std::endl;
		m_iListTest.clear();
		return;
	}
	for (int i = 0; i != 5; i++)
	{
		m_iListTest.push_back(i);
		std::cout << "the value of list  is :" << i<< std::endl;
	}

}

void CStudyList::DeleteAllElement()
{
	std::cout << "<DeleteAllElement>" << std::endl;
	std::lock_guard<std::mutex> lock(m_Mutex);
	m_iListTest.clear();
}

void CStudyList::PrintAllElement()
{
	std::cout << "<PrintAllElemt>" << std::endl;
	std::lock_guard<std::mutex> lock(m_Mutex);
	for (auto it = m_iListTest.begin(); it != m_iListTest.end(); ++it)
	{
		std::cout << "the list result is: " << (*it)  << std::endl;
	}

}
