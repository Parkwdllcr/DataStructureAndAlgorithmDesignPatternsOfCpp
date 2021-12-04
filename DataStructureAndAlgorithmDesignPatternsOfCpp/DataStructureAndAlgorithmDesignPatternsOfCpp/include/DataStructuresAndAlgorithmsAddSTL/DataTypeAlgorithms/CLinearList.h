#pragma once
#include"ILinearList.h"
#include<iostream>
#include <string>

class CLinearList :public ILinearList
{
public:
	virtual int  indexof(const int theElement) const = 0;
	virtual void erase(int itheIndex) = 0;
	virtual void insert(int itheIndex, const int theElement) = 0;
	virtual void output()const = 0;
	virtual void clear() = 0;
	virtual void push_back(const int theElement) = 0; 

	virtual bool empty() const { return m_iListSize == 0; }
	virtual int  size() const { return m_iListSize; }
	int         CheckIndex(int iTheIndex);
protected:
	int          m_iListSize;
};



