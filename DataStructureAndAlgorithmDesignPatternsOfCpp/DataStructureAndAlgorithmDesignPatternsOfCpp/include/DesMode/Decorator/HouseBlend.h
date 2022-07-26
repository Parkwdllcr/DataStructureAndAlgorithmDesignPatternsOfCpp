///////////////////////////////////////////////////////////
//  HouseBlend.h
//  Implementation of the Class HouseBlend
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_E999824E_E0C8_42af_9CA4_0B70E30FE1A3__INCLUDED_)
#define EA_E999824E_E0C8_42af_9CA4_0B70E30FE1A3__INCLUDED_

#include "Beverages.h"

/**
 * Summary description for HouseBlend.
 */
class HouseBlend : public Beverage
{

public:
	virtual ~HouseBlend();

	HouseBlend();
	double Cost() override;
	string GetDescription() override;

};
#endif // !defined(EA_E999824E_E0C8_42af_9CA4_0B70E30FE1A3__INCLUDED_)
