#pragma once
#include <iostream>
#include "CProduct_Add.h"
#include "CProduct_Mul.h"

class CFactory
{
public:
   CFactory(){}
   ~CFactory(){}
public:
	CProduct* Creat(int iProductType);
	void Destory();
protected:
	CProduct* m_pCproduct ;
	
};

