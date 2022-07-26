///////////////////////////////////////////////////////////
//  Duck.h
//  Implementation of the Interface Duck
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_72950F43_A3B8_45c7_A74D_2AF1DE158018__INCLUDED_)
#define EA_72950F43_A3B8_45c7_A74D_2AF1DE158018__INCLUDED_

/**
 * Summary description for Duck.
 */

#include <string>

class Duck
{

public:
	Duck() {

	}

	virtual ~Duck() {

	}

	virtual std::string Fly() = 0;
	virtual std::string Quack() = 0;

};
#endif 
