#pragma once
#include "DesMode/SimpleFactory/COperation.h"

class COperationAdd:public COperation
{
public:
	virtual bool GetResult(double& dbResult) const;

};
