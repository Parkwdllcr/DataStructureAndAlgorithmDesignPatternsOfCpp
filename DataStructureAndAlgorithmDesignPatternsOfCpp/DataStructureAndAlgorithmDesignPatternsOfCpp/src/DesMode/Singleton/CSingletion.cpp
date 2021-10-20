#include "DesMode/Singleton/CSingletion.h"

CSingletion::~CSingletion()
{
	std::cout << "destructor called" << std::endl;
}

CSingletion* CSingletion::get_instance()
{
	static CSingletion instance;
	return &instance;
}

CSingletion::CSingletion()
{
	std::cout << "constructor called!" << std::endl;
}

void CSingletion::SetSomeValue(int iNest)
{
	for (int i = 0; i != iNest; i++)
	{
		m_iTestList.push_back(i);
	}
}

int CSingletion::GetSomeValue(int iNest)
{
	int itemp = 0;
	for (auto item : m_iTestList)
	{
		std::cout << item << std::endl;
		if (itemp == iNest)
		{
			return item;
		}
		itemp++;
	}

	return m_iTestList.size();
}
