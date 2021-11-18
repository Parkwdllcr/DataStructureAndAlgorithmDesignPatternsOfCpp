#include "DataStructuresAndAlgorithmsAddSTL/STL/CStudyMap/CStudyMap.h"
#include "CPrimerPlus/PublicClass/CPublicClass.h"

CStudyMap::CStudyMap()
{
	m_pPublicClass = new CPublicClass;
}

CStudyMap::~CStudyMap()
{
	if (nullptr != m_pPublicClass)
	{
		delete m_pPublicClass;
		m_pPublicClass = nullptr;
	}
}

void CStudyMap::PrintTestMap()
{
	m_pPublicClass->PrintfTestFunctionFlag("void CStudyMap::PrintTestMap()");
	std::map<std::string, int>::iterator it;
	for ( it = m_TestMap.begin();it != m_TestMap.end(); it++)
	{
		std::cout << "the map key is: " << it->first
			<< ", the map value is: " << it->second << std::endl;
	}
}

void CStudyMap::AddTestElement()
{
	m_pPublicClass->PrintfTestFunctionFlag("void CStudyMap::AddTestElement(std::string strKey, int iValue)");
	m_TestMap["lcr"] = 1;
	m_TestMap["hjt"] = 2;
	m_TestMap["syq"] = 3;
	m_TestMap["jsl"] = 4;
	m_TestMap["yyx"] = 5;
}

void CStudyMap::DeleteAllElement()
{
	m_pPublicClass->PrintfTestFunctionFlag("void CStudyMap::DeleteElement()");
	std::map<std::string, int>::iterator it;
	for (it = m_TestMap.begin();it != m_TestMap.end();)
	{
		it = m_TestMap.erase(it);
	}
}

std::map<std::string, int>::iterator CStudyMap::SearchMapValue(std::string strKey)
{
	m_pPublicClass->PrintfTestFunctionFlag("std::map<std::string, int>::iterator CStudyMap::SearchMapValue(std::string strKey)");
	return m_TestMap.find(strKey);
}
