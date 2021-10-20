#pragma once
#include "Aggregate.h"
#include "ConcreteIterator.h"


class ConcreteAggregate :
	public Aggregate
{
public:
	ConcreteAggregate(int nSize) :m_nSize(nSize), m_pData(nullptr) 
	{
		m_pData = new DATA[m_nSize];
		for (int i = 0; i < nSize; ++i)
			m_pData[i] = i;
	}
	virtual ~ConcreteAggregate();
	virtual Iterator* CreateIterator(Aggregate* pAggregate);
	virtual int GetSize();
	virtual DATA GetItem(int nIndex);
private:
	int m_nSize;
	DATA* m_pData;
};

