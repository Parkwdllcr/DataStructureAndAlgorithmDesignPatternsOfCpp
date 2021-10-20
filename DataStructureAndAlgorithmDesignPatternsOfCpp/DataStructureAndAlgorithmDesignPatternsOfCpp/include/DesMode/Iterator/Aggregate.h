#pragma once

typedef int DATA;
class Iterator;
class Aggregate
{
public:
	virtual ~Aggregate() {}
	virtual Iterator* CreateIterator(Aggregate* pAggregate) = 0;
	virtual int GetSize() = 0;
	virtual DATA GetItem(int nIndex) = 0;
};

