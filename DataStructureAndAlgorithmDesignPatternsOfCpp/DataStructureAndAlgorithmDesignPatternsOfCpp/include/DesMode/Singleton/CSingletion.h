#pragma once
#include <iostream>
#include<list>

class CSingletion
{
public:

	~CSingletion();

	CSingletion(const CSingletion&) = delete;

	CSingletion& operator=(const CSingletion&) = delete;

	//��Ҫȥ���� instance
	static CSingletion* get_instance();

private:
	//���캯����˽������
	CSingletion();
	//�����ǳ���������
public:
	void	SetSomeValue(int iNest);
	int     GetSomeValue(int iNest);
private:
	std::list<int> m_iTestList;
};

