#pragma once
#include "COperation.h"

class COperationAdd:public COperation
{
public:
	virtual bool GetResult(double& dbResult) const;

};
