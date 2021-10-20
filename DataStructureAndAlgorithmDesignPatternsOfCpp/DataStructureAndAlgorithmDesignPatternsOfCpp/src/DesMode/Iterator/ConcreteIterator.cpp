
#include"DesMode/Iterator/ConcreteIterator.h"

ConcreteIterator::~ConcreteIterator()
{
	m_nIndex = 0;
}

void ConcreteIterator::First()
{
	m_nIndex = 0;
}

void ConcreteIterator::Next()
{
	if (m_nIndex < m_pConcreteAggregate->GetSize())
		++m_nIndex;
}

bool ConcreteIterator::IsDone()
{
	return m_nIndex == m_pConcreteAggregate->GetSize();
}

DATA ConcreteIterator::CurrentItem()
{
	return m_pConcreteAggregate->GetItem(m_nIndex);
}
