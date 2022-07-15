#pragma once
#include "DesMode/SimpleFactory/COperation.h"

class COperationMul :public COperation
{
public:
	virtual bool GetResult(double& dbResult )const;
};
