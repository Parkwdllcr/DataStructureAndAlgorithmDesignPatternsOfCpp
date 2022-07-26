///////////////////////////////////////////////////////////
//  Beverage.h
//  Implementation of the Class Beverage
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_23292275_1931_4a4f_8A2F_CA3ECA6305C5__INCLUDED_)
#define EA_23292275_1931_4a4f_8A2F_CA3ECA6305C5__INCLUDED_

#include "BeverageSize.h"

/**
 * Summary description for Beverage.
 */
class Beverage
{

public:
	Beverage();
	virtual ~Beverage();

	virtual double Cost();
	string GetDescription();
	BeverageSize Size();

private:
	BeverageSize size;

};
#endif // !defined(EA_23292275_1931_4a4f_8A2F_CA3ECA6305C5__INCLUDED_)
