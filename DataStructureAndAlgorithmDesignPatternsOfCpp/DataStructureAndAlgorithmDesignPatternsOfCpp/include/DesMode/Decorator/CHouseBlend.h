///////////////////////////////////////////////////////////
//  HouseBlend.h
//  Implementation of the Class HouseBlend
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _HOUSEBLEND_H_
#define _HOUSEBLEND_H_

#include "CBeverages.h"


class CHouseBlend : public CBeverage
{

public:
	virtual ~CHouseBlend();
	static CHouseBlend* GetInstance();

	virtual double Cost() ;
	virtual std::string GetDescription() ;

private:
	CHouseBlend();
};
#endif 