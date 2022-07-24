///////////////////////////////////////////////////////////
//  CChicagoPizzaStore.h
//  Implementation of the Class CChicagoPizzaStore
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _CHICAGO_PIZZA_H_
#define _CHICAGO_PIZZA_H_

#include "CPizzaStore.h"
#include "CChicagoPizzlngredientFactory.h"

class CChicagoPizzaStore : public CPizzaStore
{

public:
	virtual ~CChicagoPizzaStore();
	CChicagoPizzaStore();
	CPizza* CreatePizza(enPizzaStype enStype);
private:
	ImpPizzalngredientFactory* m_pChicagoPizzaIngredientFacttory;
	CPizza*                    m_pPizza                  ;
};
#endif 