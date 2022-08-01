///////////////////////////////////////////////////////////
//  Turkey.h
//  Implementation of the Interface Turkey
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _THIN_IMP_TURKEY_H_
#define _THIN_IMP_TURKEY_H_

#include <string>

class ImpTurkey
{

public:
	virtual ~ImpTurkey() {}

	virtual std::string Fly() = 0;
	virtual std::string Gobble() = 0;

};
#endif 
