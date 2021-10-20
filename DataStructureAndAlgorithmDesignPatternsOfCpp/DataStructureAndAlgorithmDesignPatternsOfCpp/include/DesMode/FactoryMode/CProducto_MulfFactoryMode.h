#pragma once
#include "CProductofFactoryMode.h"
class CProducto_MulfFactoryMode :
	public CProductofFactoryMode
{
public:
	CProducto_MulfFactoryMode();
	~CProducto_MulfFactoryMode();
public:
	int operation(int a, int b);
};

