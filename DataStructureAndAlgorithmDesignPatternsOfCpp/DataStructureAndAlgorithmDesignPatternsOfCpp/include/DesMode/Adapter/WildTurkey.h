///////////////////////////////////////////////////////////
//  WildTurkey.h
//  Implementation of the Class WildTurkey
//  Created on:      26-7ÔÂ-2022 10:53:59
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_F54CBF08_0461_47e2_9760_AC49CE0DF1C8__INCLUDED_)
#define EA_F54CBF08_0461_47e2_9760_AC49CE0DF1C8__INCLUDED_

#include "Turkey.h"
#include <string>

/**
 * Summary description for WildTurkey.
 */
class WildTurkey : public Turkey
{

public:
	virtual ~WildTurkey();

	WildTurkey();
	std::string Fly();
	std::string Gobble();

};
#endif // !defined(EA_F54CBF08_0461_47e2_9760_AC49CE0DF1C8__INCLUDED_)
