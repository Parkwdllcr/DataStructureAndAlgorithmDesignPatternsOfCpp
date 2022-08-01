///////////////////////////////////////////////////////////
//  Duck.h
//  Implementation of the Interface Duck
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _THIN_IMP_DUCK_H_
#define _THIN_IMP_DUCK_H_

#include <string>

class ImpDuck
{

public:
	virtual ~ImpDuck() {}

	virtual std::string Fly() = 0;
	virtual std::string Quack() = 0;

};
#endif 
