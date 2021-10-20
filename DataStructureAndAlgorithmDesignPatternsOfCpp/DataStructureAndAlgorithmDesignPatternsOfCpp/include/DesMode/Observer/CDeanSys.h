#pragma once
#include "CStudent.h"
#include <list>
#include <unordered_map>

class CDeanSys
{
public:
	//ѧ��ѡ��
	void	SelectCourse(CStudent* stu, int classId);

	void	NoticeStudent(int classId);
private:
	//��¼ѧ���Ϳγ���Ϣ
	std::unordered_map<int ,std::list<CStudent*>>	m_umapCourse;
};

