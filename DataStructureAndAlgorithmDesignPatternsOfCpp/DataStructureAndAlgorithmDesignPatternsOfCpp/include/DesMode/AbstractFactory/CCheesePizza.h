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
	
	virtual ~CCheesePizza();
	CCheesePizza(const CCheesePizza&) = delete;
	CCheesePizza& operator=(const CCheesePizza&) = delete;
	std::string Prepare();
	static CCheesePizza* GetInstance(ImpPizzalngredientFactory* pIngredientFactory);

private:
	ImpPizzalngredientFactory * m_pIngredientFactory;
	CCheesePizza();
	CCheesePizza(ImpPizzalngredientFactory* pIngredientFactory);

};
#endif