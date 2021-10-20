#pragma once
#include "CProductofFactoryMode.h"

class CProducto_AddfFactoryMode :
	public CProductofFactoryMode
{
public:
	CProducto_AddfFactoryMode();
	~CProducto_AddfFactoryMode();
public:
	int operation(int a, int b);
};

