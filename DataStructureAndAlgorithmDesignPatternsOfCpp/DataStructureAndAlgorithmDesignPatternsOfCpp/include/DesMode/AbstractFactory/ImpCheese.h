///////////////////////////////////////////////////////////
//  ImpCheese.h
//  Implementation of the Interface ImpCheese
//  Created on:      18-7ÔÂ-2022 19:09:31
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _IMP_CHEESE_H_
#define _IMP_CHEESE_H_

#include <string>


class ImpCheese
{

public:
	virtual ~ImpCheese() {}
	virtual std::string ToString() = 0;
};
#endif 
