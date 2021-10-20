
#include"DesMode/Iterator/ConcreteAggregate.h"


ConcreteAggregate::~ConcreteAggregate()
{
	delete[] m_pData;
	m_pData = nullptr;
}

Iterator* ConcreteAggregate::CreateIterator(Aggregate* pAggregate)
{
	return new ConcreteIterator(this);
}

int ConcreteAggregate::GetSize()
{
	return m_nSize;
}

DATA ConcreteAggregate::GetItem(int nIndex)
{
	if (nIndex < m_nSize)
		return m_pData[nIndex];
	else
		return -1;
}
