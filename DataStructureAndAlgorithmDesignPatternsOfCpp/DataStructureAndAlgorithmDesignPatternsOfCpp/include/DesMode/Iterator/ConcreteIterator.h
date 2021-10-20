#pragma once
#include "Iterator.h"

class ConcreteIterator :
	public Iterator
{
public:
	ConcreteIterator(Aggregate* pAggregate)
		:m_pConcreteAggregate(pAggregate), m_nIndex(0) {}
	virtual ~ConcreteIterator();
	
	virtual void First();
	
	virtual void Next();
	
	virtual bool IsDone();
	
	virtual DATA CurrentItem();
	
private:
	Aggregate* m_pConcreteAggregate;
	int m_nIndex;

};

