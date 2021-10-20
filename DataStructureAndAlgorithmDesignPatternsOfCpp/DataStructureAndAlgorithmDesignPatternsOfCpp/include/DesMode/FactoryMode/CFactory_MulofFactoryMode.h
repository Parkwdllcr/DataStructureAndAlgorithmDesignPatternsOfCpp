#pragma once
#include "CFactoryofFactoryMode.h"

class CFactory_MulofFactoryMode :
	public CFactoryofFactoryMode
{
public:
	CFactory_MulofFactoryMode();

	~CFactory_MulofFactoryMode();
public:
	CProductofFactoryMode* Create();

	void Destory();
};

