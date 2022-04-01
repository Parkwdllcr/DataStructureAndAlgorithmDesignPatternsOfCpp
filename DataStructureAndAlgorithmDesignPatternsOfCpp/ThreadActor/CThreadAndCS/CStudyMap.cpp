#include "CStudyMap.h"
#include <iostream>
void CStudyMap::AddElement()
{
	std::cout << "<AddElement>" << std::endl;
	std::lock_guard<std::mutex> lock(m_Mutex);
	if (m_iMapTest.size() > 10)
	{
		std::cout << " iCount of AddElement is morn than 10!" << std::endl;
		m_iMapTest.clear();
		return;
	}
	for (int i = 0; i != 5; i++)
	{
		m_iMapTest.insert(std::pair<int, int>(i, i));
		std::cout << "the value of map  is :" << i << std::endl;
	}
}

void CStudyMap::DeleteAllElement()
{
	std::cout << "<DeleteAllElement>" << std::endl;
	std::lock_guard<std::mutex> lock(m_Mutex);
	m_iMapTest.clear();
}

void CStudyMap::PrintAllElement()
{
	std::cout << "<PrintAllElemt>" << std::endl;
	std::lock_guard<std::mutex> lock(m_Mutex);
	for (auto it = m_iMapTest.begin(); it != m_iMapTest.end(); ++it)
	{
		std::cout << "the list result is: " << (it)->second << std::endl;
	}
}
