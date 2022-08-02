///////////////////////////////////////////////////////////
//  CondimentDecorator.h
//  Implementation of the Class CondimentDecorator
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _CONDIMENT_DECORATOR_H_
#define _CONDIMENT_DECORATOR_H_

#include "CBeverages.h"


class CCondimentDecorator : public CBeverage
{

public:
	virtual ~CCondimentDecorator();
	CCondimentDecorator(CBeverage* pBerver);
	double   Cost();

private:
	CBeverage* m_pBeverage;

};
#endif 
