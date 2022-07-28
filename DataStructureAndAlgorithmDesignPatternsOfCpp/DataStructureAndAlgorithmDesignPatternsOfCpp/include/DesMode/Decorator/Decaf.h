///////////////////////////////////////////////////////////
//  Decaf.h
//  Implementation of the Class Decaf
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _DECAF_H_
#define _DECAF_H_

#include "Beverages.h"


class Decaf : public CBeverage
{

public:
	virtual ~Decaf();

	Decaf();
	double Cost() override;
	std::string GetDescription() override;

};
#endif // !defined(EA_1BCE9ADD_CDE3_4556_ABAC_093336E88F16__INCLUDED_)
