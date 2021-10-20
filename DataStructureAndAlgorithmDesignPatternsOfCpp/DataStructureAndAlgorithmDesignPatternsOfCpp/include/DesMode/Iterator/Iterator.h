#pragma once
#include "Aggregate.h"

class Iterator
{
public:
	virtual ~Iterator() {}
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual DATA CurrentItem() = 0;
};

