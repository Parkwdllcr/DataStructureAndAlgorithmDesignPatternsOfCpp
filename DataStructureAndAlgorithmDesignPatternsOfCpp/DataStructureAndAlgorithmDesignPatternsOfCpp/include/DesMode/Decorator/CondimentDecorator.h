///////////////////////////////////////////////////////////
//  CondimentDecorator.h
//  Implementation of the Class CondimentDecorator
//  Created on:      26-7��-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _CONDIMENT_DECORATOR_H_
#define _CONDIMENT_DECORATOR_H_

#include "Beverages.h"


class CCondimentDecorator : public CBeverage
{

public:
	virtual ~CCondimentDecorator();

	CCondimentDecorator();

};
#endif 