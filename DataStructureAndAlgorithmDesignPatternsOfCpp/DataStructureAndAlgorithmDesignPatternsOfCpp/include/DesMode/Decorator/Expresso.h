///////////////////////////////////////////////////////////
//  Expresso.h
//  Implementation of the Class Expresso
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_1AC5D13C_B64C_4d44_ADEF_F6A6F2466370__INCLUDED_)
#define EA_1AC5D13C_B64C_4d44_ADEF_F6A6F2466370__INCLUDED_

#include "Beverages.h"

/**
 * Summary description for Expresso.
 */
class Expresso : public Beverage
{

public:
	virtual ~Expresso();

	Expresso();
	double Cost() override;
	string GetDescription() override;

private:
	double GetSize(BeverageSize size);

};
#endif // !defined(EA_1AC5D13C_B64C_4d44_ADEF_F6A6F2466370__INCLUDED_)
