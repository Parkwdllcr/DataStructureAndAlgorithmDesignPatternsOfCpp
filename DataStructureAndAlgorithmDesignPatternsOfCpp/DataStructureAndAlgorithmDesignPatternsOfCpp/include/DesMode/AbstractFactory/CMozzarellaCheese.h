///////////////////////////////////////////////////////////
//  CMozzarellaCheese.h
//  Implementation of the Class CMozzarellaCheese
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _MOZZARELLA_CHEESE_H_
#define _MOZZARELLA_CHEESE_H_

#include "ImpCheese.h"

class CMozzarellaCheese : public ImpCheese
{

public:
	CMozzarellaCheese();
	virtual ~CMozzarellaCheese();

	virtual std::string ToString();

};
#endif
