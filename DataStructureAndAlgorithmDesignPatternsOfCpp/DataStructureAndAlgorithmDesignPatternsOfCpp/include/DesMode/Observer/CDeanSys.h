#pragma once
#include "CStudent.h"
#include <list>
#include <unordered_map>

class CDeanSys
{
public:
	//学生选课
	void	SelectCourse(CStudent* stu, int classId);

	void	NoticeStudent(int classId);
private:
	//记录学生和课程信息
	std::unordered_map<int ,std::list<CStudent*>>	m_umapCourse;
};

