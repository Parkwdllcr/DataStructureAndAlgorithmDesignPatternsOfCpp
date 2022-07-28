///////////////////////////////////////////////////////////
//  DarkRoast.h
//  Implementation of the Class DarkRoast
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////
#ifndef _DARK_ROAST_H_
#define _DARK_ROAST_H_


#include "Beverages.h"


class DarkRoast : public CBeverage
{

public:
	virtual ~DarkRoast();

	DarkRoast();
	double Cost() override;
	std::string GetDescription() override;

};
#endif 