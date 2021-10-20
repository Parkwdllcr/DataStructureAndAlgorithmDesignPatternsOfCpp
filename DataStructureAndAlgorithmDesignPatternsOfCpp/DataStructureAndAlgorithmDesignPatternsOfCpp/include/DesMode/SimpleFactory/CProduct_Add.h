#pragma once
#include "CProduct.h"


class CProduct_Add :
	public CProduct
{
public:
	CProduct_Add();
	~CProduct_Add();
public:
	int operation(int a, int b);
};

