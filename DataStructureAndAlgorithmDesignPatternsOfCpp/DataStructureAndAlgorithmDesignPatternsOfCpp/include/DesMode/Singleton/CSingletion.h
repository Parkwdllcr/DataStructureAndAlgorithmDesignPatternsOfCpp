#pragma once
#include <iostream>
#include<list>

class CSingletion
{
public:

	~CSingletion();

	CSingletion(const CSingletion&) = delete;

	CSingletion& operator=(const CSingletion&) = delete;

	//不要去销毁 instance
	static CSingletion* get_instance();

private:
	//构造函数在私有里面
	CSingletion();
	//以下是常规的类操作
public:
	void	SetSomeValue(int iNest);
	int     GetSomeValue(int iNest);
private:
	std::list<int> m_iTestList;
};

