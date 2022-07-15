#pragma once
#include "DesMode/SimpleFactory/COperation.h"

class COperationSub:public COperation
{
public:
	virtual bool GetResult(double& dbResult)const;

};

