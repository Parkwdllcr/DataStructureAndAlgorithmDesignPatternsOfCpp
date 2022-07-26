///////////////////////////////////////////////////////////
//  DuckAdapter.h
//  Implementation of the Class DuckAdapter
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_7CA6CC48_EDCE_4ca1_B356_7E1B3CE3EB5B__INCLUDED_)
#define EA_7CA6CC48_EDCE_4ca1_B356_7E1B3CE3EB5B__INCLUDED_

#include "Duck.h"
#include "Turkey.h"
#include <string>

/**
 * Summary description for TurkeyAdapter.
 */
class DuckAdapter : public Turkey
{

public:
	DuckAdapter();
	virtual ~DuckAdapter();

	DuckAdapter(Duck duck);
	std::string Fly();
	std::string Gobble();

private:
	Duck duck;

};
#endif // !defined(EA_7CA6CC48_EDCE_4ca1_B356_7E1B3CE3EB5B__INCLUDED_)
