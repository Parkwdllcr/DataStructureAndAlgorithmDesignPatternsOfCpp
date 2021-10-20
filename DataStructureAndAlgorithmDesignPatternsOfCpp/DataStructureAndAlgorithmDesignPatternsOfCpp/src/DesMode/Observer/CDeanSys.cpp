//#include "CDeanSys.h"
#include"DesMode/Observer/CDeanSys.h"

void CDeanSys::SelectCourse(CStudent* stu, int classId)
{
	std::unordered_map<int, std::list<CStudent*>>::iterator unmapStudentCourseIter 
		                                              = m_umapCourse.find(classId);
	if (unmapStudentCourseIter == m_umapCourse.end())
	{
		m_umapCourse[classId].push_back(stu);
	}
	else
	{
		unmapStudentCourseIter->second.push_back(stu);
	}

}


void CDeanSys::NoticeStudent(int classId)
{
	std::unordered_map<int, std::list<CStudent*>>::iterator unmapStudentCourseIter
		= m_umapCourse.find(classId);
	if (unmapStudentCourseIter != m_umapCourse.end())
	{
		for (CStudent* stu : unmapStudentCourseIter->second)
		{
			stu->AttendClass(classId);
		}
	}

}
