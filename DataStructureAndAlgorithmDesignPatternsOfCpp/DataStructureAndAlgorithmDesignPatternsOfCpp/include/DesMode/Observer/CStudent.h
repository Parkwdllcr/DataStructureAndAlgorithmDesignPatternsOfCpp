#pragma once
#include <string>
#include <iostream>

class CStudent
{
public:
	CStudent(std::string strname) :m_strName(strname) {}

	~CStudent();

public:

	virtual	void AttendClass(int classId) = 0;

	//because it needs to be inherited,it cannot private
protected:
	std::string	m_strName;
};


