///////////////////////////////////////////////////////////
//  MallardDuck.h
//  Implementation of the Class MallardDuck
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_66DD3364_D2FD_41b6_B898_934C9962DC19__INCLUDED_)
#define EA_66DD3364_D2FD_41b6_B898_934C9962DC19__INCLUDED_

#include "Duck.h"
#include <string>

/**
 * Summary description for MallardDuck.
 */
class MallardDuck : public Duck
{

public:
	virtual ~MallardDuck();

	MallardDuck();
	std::string Fly();
	std::string Quack();

};
#endif // !defined(EA_66DD3364_D2FD_41b6_B898_934C9962DC19__INCLUDED_)
