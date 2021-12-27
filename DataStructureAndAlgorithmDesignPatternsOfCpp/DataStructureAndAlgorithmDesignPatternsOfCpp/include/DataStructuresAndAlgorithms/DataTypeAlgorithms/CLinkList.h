#pragma once
#include"CLinearList.h"
#include "CPrimerPlus/CPrimerPlus.h"

class CLinkList :public CLinearList
{
public:
	//CLinkList(const CLinkList& theList);
	enum enCREAT_WAY {
		HEAD_INSERTION,
		TAIL_INSERTION
	};
	CLinkList(int iInitialSize = 10, enCREAT_WAY enCreatWay = TAIL_INSERTION);
	~CLinkList();
public:
	virtual int  indexof(const int theElement) const;
	virtual void erase(int itheIndex);
	virtual void insert(int itheIndex, const int theElement);
	virtual void output()const;
	virtual void clear();
	virtual void push_back(const int theElement);

	int   get(int itheIndex) ;

private:
	LinkListNode m_firstNode;
	CStudyCPrimerPlus*   m_pPublicClass;
};



