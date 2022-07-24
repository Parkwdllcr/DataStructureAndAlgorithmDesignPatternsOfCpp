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
	static CMozzarellaCheese* GetInstance();
	CMozzarellaCheese(const CMozzarellaCheese&) = delete;
	CMozzarellaCheese& operator=(const CMozzarellaCheese&) = delete;
	virtual ~CMozzarellaCheese();
	virtual std::string ToString();
private:
	CMozzarellaCheese();

};
#endif
