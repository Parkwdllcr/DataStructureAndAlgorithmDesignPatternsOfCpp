#include "ListAndMap/CStudyMap.h"
#include "UtilsBox/utilsbox_utils.h"
#include<iostream>

void CStudyMap::PrintTestMap()
{
	std::map<std::string, int>::iterator it;
	for ( it = m_TestMap.begin();it != m_TestMap.end(); it++)
	{
		std::cout << "the map key is: " << it->first
			<< ", the map value is: " << it->second << std::endl;
	}
}

void CStudyMap::AddTestElement()
{
	m_TestMap["lcr"] = 1;
	m_TestMap["hjt"] = 2;
	m_TestMap["syq"] = 3;
	m_TestMap["jsl"] = 4;
	m_TestMap["yyx"] = 5;
}

void CStudyMap::DeleteAllElement()
{
	std::map<std::string, int>::iterator it;
	for (it = m_TestMap.begin();it != m_TestMap.end();)
	{
		it = m_TestMap.erase(it);
	}
}

std::map<std::string, int>::iterator CStudyMap::SearchMapValue(std::string strKey)
{
	return m_TestMap.find(strKey);
}
