///////////////////////////////////////////////////////////
//  CReggianoCheese.h
//  Implementation of the Class CReggianoCheese
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _REGGIANO_CHEESE_H_
#define _REGGIANO_CHEESE_H_

#include "ImpCheese.h"

class CReggianoCheese : public ImpCheese
{

public:
	CReggianoCheese();
	virtual ~CReggianoCheese();
	virtual std::string ToString() ;

};
#endif 
