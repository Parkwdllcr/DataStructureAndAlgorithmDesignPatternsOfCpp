#pragma once
#include "IStudySTL.h"
#include<mutex>
#include<map>

class CStudyMap :
    public IStudyStl
{
public:
	static IStudyStl& GetInstance()
	{
		static std::once_flag s_flag;
		std::call_once(s_flag, [&]() {m_pInstance.reset(new CStudyMap); });
		return *m_pInstance;
	}
	~CStudyMap() = default;

public:
	virtual  void AddElement();
	virtual  void DeleteAllElement();
	virtual  void PrintAllElement();

private:
	CStudyMap() = default;
	CStudyMap(const CStudyMap&) = delete;
	CStudyMap& operator= (const CStudyMap&) = delete;

private:
	static std::unique_ptr<CStudyMap> m_pInstance;
	std::mutex                        m_Mutex;
	std::map<int,int>                 m_iMapTest;

};

