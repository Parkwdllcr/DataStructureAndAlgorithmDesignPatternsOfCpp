#include "ListAndMap/CStudyMap.h"
#include "UtilsBox/utilsbox_utils.h"
#include<iostream>


CStudyMap:: CStudyMap():m_MapTest()
{

}
CStudyMap::~CStudyMap()
{

}


void CStudyMap::PrintAllElement()
{
	m_MutexMap.Lock();
	std::map<std::string, int>::iterator it;
	for ( it = m_MapTest.begin();it != m_MapTest.end(); it++)
	{
		std::cout << "the map key is: " << it->first
			<< ", the map value is: " << it->second << std::endl;
	}
	m_MutexMap.UnLock();
}

void CStudyMap::AddElement()
{
	m_MutexMap.Lock();
	static int iCount = 0;
	if (iCount>10)
	{
		std::cout<<" iCount of AddElement is morn than 10!"<<std::endl;
		return ;
	}
	m_MapTest["lcr"] = 1;
	m_MapTest["hjt"] = 2;
	m_MapTest["syq"] = 3;
	m_MapTest["jsl"] = 4;
	m_MapTest["yyx"] = 5;
	std::cout<<"the value of map iCout is :"<<iCount<<std::endl;
	++iCount;
	m_MutexMap.UnLock();
}

void CStudyMap::DeleteAllElement()
{
	//I like this way！
	m_MutexMap.Lock();
	m_MapTest.erase(m_MapTest.begin(),m_MapTest.end());
	// std::map<std::string, int>::iterator it;
	// for (it = m_TestMap.begin();it != m_TestMap.end();)
	// {
	// 	it = m_TestMap.erase(it);
	// }
	m_MutexMap.UnLock();
}

