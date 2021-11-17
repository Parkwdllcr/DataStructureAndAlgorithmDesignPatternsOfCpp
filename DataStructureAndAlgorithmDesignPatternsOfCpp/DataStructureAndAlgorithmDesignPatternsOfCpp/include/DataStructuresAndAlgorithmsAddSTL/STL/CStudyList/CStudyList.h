#pragma once

#include<list>

class CPublicClass;
class CStudyList
{
public:
	CStudyList();
	~CStudyList();
public:
	void AddElementToList(int iElement);
	void PrintElementList();
	void DeleteList();

private:
	std::list<int> m_iTestList;
	CPublicClass* m_pPublicClass;
};
