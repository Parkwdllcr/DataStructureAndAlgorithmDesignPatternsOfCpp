///////////////////////////////////////////////////////////
//  HouseBlend.h
//  Implementation of the Class HouseBlend
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _HOUSEBLEND_H_
#define _HOUSEBLEND_H_

#include "Beverages.h"

/**
 * Summary description for HouseBlend.
 */
class CHouseBlend : public CBeverage
{

public:
	virtual ~CHouseBlend();
	static CHouseBlend* GetInstance();

	double Cost() ;
	std::string GetDescription() ;

private:
	CHouseBlend();
};
#endif // !defined(EA_E999824E_E0C8_42af_9CA4_0B70E30FE1A3__INCLUDED_)
