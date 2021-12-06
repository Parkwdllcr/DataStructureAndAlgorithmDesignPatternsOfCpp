#pragma once

#include"CStudyStlManager.h"
#include<list>

class CStudyList:public CStudyStlManager
{
public:
	CStudyList();
	CStudyList(std::string strMyName);
	~CStudyList();
public:
	void AddElementToList(int iElement);
	void PrintElementList();
	void DeleteList();
private:
	std::list<int> m_iTestList;
	std::string    m_strMyname;
};
