#pragma once
#include "CStudent.h"


class CStudentA :
	public CStudent
{

public:
	CStudentA(std::string strname) :CStudent(strname) {}

	void	AttendClass(int classId);
};

