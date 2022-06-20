#pragma once
#include "COperation.h"

class COperationSub:public COperation
{
public:
	virtual bool GetResult(double& dbResult)const;

};

