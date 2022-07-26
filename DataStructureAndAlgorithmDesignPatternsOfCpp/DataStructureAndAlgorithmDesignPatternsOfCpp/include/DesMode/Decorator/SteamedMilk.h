///////////////////////////////////////////////////////////
//  SteamedMilk.h
//  Implementation of the Class SteamedMilk
//  Created on:      26-7��-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_8E421417_2F31_4598_B4DE_0D60F59AF0D9__INCLUDED_)
#define EA_8E421417_2F31_4598_B4DE_0D60F59AF0D9__INCLUDED_

#include "Beverages.h"
#include "CondimentDecorator.h"

/**
 * Summary description for SteamedMilk.
 */
class SteamedMilk : public CondimentDecorator
{

public:
	SteamedMilk();
	virtual ~SteamedMilk();

	SteamedMilk(Beverage beverage);
	double Cost() override;
	string GetDescription() override;

private:
	Beverage beverage;

};
#endif // !defined(EA_8E421417_2F31_4598_B4DE_0D60F59AF0D9__INCLUDED_)
