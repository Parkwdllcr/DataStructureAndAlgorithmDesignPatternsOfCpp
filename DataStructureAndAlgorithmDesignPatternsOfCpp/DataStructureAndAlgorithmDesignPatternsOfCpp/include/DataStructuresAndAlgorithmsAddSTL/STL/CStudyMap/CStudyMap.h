#pragma once
#include <map>
#include <string>

class CPublicClass;
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
	CPublicClass* m_pPublicClass;


};
