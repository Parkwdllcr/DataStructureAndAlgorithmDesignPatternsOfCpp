#pragma once
#include "CStudent.h"

class CStudentB :
	public CStudent
{
public:
	CStudentB(std::string	strname) :CStudent(strname) {}
	void	AttendClass(int classId);
};

