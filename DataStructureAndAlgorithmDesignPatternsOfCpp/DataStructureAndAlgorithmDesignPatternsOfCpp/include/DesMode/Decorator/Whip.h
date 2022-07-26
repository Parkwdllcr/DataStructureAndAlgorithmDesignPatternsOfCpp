///////////////////////////////////////////////////////////
//  Whip.h
//  Implementation of the Class Whip
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_3749E8C0_5CC8_47a2_8BB0_91954454CF82__INCLUDED_)
#define EA_3749E8C0_5CC8_47a2_8BB0_91954454CF82__INCLUDED_

#include "Beverages.h"
#include "CondimentDecorator.h"

/**
 * Summary description for Whip.
 */
class Whip : public CondimentDecorator
{

public:
	Whip();
	virtual ~Whip();

	Whip(Beverage beverage);
	double Cost() override;
	string GetDescription() override;

private:
	Beverage beverage;

};
#endif // !defined(EA_3749E8C0_5CC8_47a2_8BB0_91954454CF82__INCLUDED_)
