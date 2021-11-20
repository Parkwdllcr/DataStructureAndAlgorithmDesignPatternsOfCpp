#pragma once
#include <map>
#include <string>


//理解一下四大基本函数，写上例子与文档
class CStudyMap
{
public:
   CStudyMap();
   ~CStudyMap();

public:
	void PrintTestMap();
	void AddTestElement();
	void DeleteAllElement();
	std::map<std::string,int>::iterator SearchMapValue(std::string strKey);
private:
	std::map<std::string, int> m_TestMap;
};
