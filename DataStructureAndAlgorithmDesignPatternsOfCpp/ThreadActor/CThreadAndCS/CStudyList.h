#pragma once
#include "IStudySTL.h"
#include<mutex>
#include<list>

class CStudyList :
    public IStudyStl
{
public:
	static IStudyStl& GetInstance()
	{
		static std::once_flag s_flag;
		std::call_once(s_flag, [&]() {m_pInstance.reset(new CStudyList); });
		return *m_pInstance;
	}
	~CStudyList() = default;

public:
	virtual  void AddElement();
	virtual  void DeleteAllElement();
	virtual  void PrintAllElement();

private:
	CStudyList() = default;
	CStudyList(const CStudyList&) = delete;
	CStudyList& operator= (const CStudyList&) = delete;

private:
	static std::unique_ptr<CStudyList> m_pInstance;
	std::mutex                  m_Mutex;
	std::list<int>      m_iListTest;
    
};




