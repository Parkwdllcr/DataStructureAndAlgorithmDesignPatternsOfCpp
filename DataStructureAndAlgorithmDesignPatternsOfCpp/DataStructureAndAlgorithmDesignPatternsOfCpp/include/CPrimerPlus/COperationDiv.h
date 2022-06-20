#pragma once
#include "COperation.h"

class COperationDiv :public COperation
{
public:
	virtual bool GetResult(double& dbResult) const;
};