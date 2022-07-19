///////////////////////////////////////////////////////////
//  CCheesePizza.h
//  Implementation of the Class CCheesePizza
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _CHEESE_PIZZA_H_
#define _CHEESE_PIZZA_H_

#include "CPizza.h"
#include "ImpPizzalngredientFactory.h"


class CCheesePizza : public CPizza
{

public:
	CCheesePizza(ImpPizzalngredientFactory* pIngredientFactory);
	virtual ~CCheesePizza();
	std::string Prepare();

private:
	ImpPizzalngredientFactory * m_pIngredientFactory;
	CCheesePizza();

};
#endif