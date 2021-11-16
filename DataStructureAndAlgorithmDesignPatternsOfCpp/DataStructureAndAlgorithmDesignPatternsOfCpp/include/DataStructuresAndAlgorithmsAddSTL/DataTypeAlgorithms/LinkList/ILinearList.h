
#pragma once

#include "Node.h"

class ILinearList
{
public:
	virtual      ~ILinearList() {};
	virtual bool empty() const = 0;
	virtual int  size() const = 0;
	virtual int  indexof(const int theElement) const = 0;
	virtual void erase(int itheIndex) = 0;
	virtual void insert(int itheIndex, const int theElement) = 0;
	virtual void output()const = 0;
	virtual void clear() = 0;
	virtual void push_back(const int theElement) = 0;
};











