///////////////////////////////////////////////////////////
//  PancakeHouseIterator.h
//  Implementation of the Class PancakeHouseIterator
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_FE45E12A_85E0_453e_A607_CFAA203759E2__INCLUDED_)
#define EA_FE45E12A_85E0_453e_A607_CFAA203759E2__INCLUDED_

#include "Iterator.h"

/**
 * Summary description for PancakeHouseIterator.
 */
class PancakeHouseIterator : public Iterator
{

public:
	PancakeHouseIterator();
	virtual ~PancakeHouseIterator();

	PancakeHouseIterator(ArrayList menuItems);
	bool HasNext();
	object Next();

private:
	ArrayList menuItems;
	int position;

};
#endif // !defined(EA_FE45E12A_85E0_453e_A607_CFAA203759E2__INCLUDED_)
