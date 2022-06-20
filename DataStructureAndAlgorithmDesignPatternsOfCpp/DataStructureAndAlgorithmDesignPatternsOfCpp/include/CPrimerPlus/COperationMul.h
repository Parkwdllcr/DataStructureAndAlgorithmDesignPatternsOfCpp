#pragma once
#include "COperation.h"

class COperationMul :public COperation
{
public:
	virtual bool GetResult(double& dbResult )const;
};
