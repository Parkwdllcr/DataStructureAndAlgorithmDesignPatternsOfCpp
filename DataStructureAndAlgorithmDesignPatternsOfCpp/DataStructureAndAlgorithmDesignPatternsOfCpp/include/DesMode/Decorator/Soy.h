///////////////////////////////////////////////////////////
//  Soy.h
//  Implementation of the Class Soy
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_0B964495_5B93_4cfa_9982_DE9B5BDE4FBF__INCLUDED_)
#define EA_0B964495_5B93_4cfa_9982_DE9B5BDE4FBF__INCLUDED_

#include "Beverages.h"
#include "CondimentDecorator.h"

/**
 * Summary description for Soy.
 */
class Soy : public CondimentDecorator
{

public:
	Soy();
	virtual ~Soy();

	Soy(Beverage beverage);
	double Cost() override;
	string GetDescription() override;

private:
	Beverage beverage;

};
#endif // !defined(EA_0B964495_5B93_4cfa_9982_DE9B5BDE4FBF__INCLUDED_)
