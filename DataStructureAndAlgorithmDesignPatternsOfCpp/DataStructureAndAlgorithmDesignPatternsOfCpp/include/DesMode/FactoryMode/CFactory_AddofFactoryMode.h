#pragma once
#include "CFactoryofFactoryMode.h"
#include "CProductofFactoryMode.h"

class CFactory_AddofFactoryMode :
	public CFactoryofFactoryMode
{
public:
	CProductofFactoryMode* Create();

	void Destory();

};

