#pragma once
#include "CProduct.h"

class CProduct_Mul :
	public CProduct
{
public:
	CProduct_Mul();
	~CProduct_Mul();
public:
	int operation(int a, int b);
};

