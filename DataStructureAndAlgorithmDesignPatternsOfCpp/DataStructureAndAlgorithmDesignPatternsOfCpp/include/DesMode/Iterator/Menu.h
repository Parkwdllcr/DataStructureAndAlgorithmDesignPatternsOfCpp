///////////////////////////////////////////////////////////
//  Menu.h
//  Implementation of the Interface Menu
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_E9B1D187_AD56_4ce1_81E8_D2BE059E3314__INCLUDED_)
#define EA_E9B1D187_AD56_4ce1_81E8_D2BE059E3314__INCLUDED_

#include "Iterator.h"

/**
 * Summary description for Menu.
 */
class Menu
{

public:
	Menu() {

	}

	virtual ~Menu() {

	}

	virtual Iterator CreateIterator() =0;

};
#endif // !defined(EA_E9B1D187_AD56_4ce1_81E8_D2BE059E3314__INCLUDED_)
