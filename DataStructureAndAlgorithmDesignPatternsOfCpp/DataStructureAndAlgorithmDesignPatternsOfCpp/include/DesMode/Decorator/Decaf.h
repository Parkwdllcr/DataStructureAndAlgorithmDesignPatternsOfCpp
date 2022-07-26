///////////////////////////////////////////////////////////
//  Decaf.h
//  Implementation of the Class Decaf
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_1BCE9ADD_CDE3_4556_ABAC_093336E88F16__INCLUDED_)
#define EA_1BCE9ADD_CDE3_4556_ABAC_093336E88F16__INCLUDED_

#include "Beverages.h"

/**
 * Summary description for Decaf.
 */
class Decaf : public Beverage
{

public:
	virtual ~Decaf();

	Decaf();
	double Cost() override;
	string GetDescription() override;

};
#endif // !defined(EA_1BCE9ADD_CDE3_4556_ABAC_093336E88F16__INCLUDED_)
