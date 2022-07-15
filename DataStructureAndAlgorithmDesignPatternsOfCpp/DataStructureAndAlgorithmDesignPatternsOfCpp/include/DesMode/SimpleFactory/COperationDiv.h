#pragma once
#include "DesMode/SimpleFactory/COperation.h"

class COperationDiv :public COperation
{
public:
	virtual bool GetResult(double& dbResult) const;
};