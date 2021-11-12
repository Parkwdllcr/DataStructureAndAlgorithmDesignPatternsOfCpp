#pragma once
#include<string>

class CPublicClass;

class CStudyString
{
public:
	CStudyString(const char* pConstChar) :m_strInitFirst(pConstChar),m_pPubicClass(nullptr) {}
	~CStudyString();
public:
	void Inital();
protected:
private:
	std::string  m_strInitFirst;
	CPublicClass*  m_pPubicClass;
};
