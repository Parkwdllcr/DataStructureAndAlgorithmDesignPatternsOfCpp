///////////////////////////////////////////////////////////
//  DarkRoast.h
//  Implementation of the Class DarkRoast
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_85004634_8AAE_4101_BFE4_7B02C1E994AC__INCLUDED_)
#define EA_85004634_8AAE_4101_BFE4_7B02C1E994AC__INCLUDED_

#include "Beverages.h"

/**
 * Summary description for DarkRoast.
 */
class DarkRoast : public Beverage
{

public:
	virtual ~DarkRoast();

	DarkRoast();
	double Cost() override;
	string GetDescription() override;

};
#endif // !defined(EA_85004634_8AAE_4101_BFE4_7B02C1E994AC__INCLUDED_)
