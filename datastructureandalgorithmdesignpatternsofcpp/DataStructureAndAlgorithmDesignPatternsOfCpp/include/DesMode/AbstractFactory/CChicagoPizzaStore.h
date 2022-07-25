///////////////////////////////////////////////////////////
//  CChicagoPizzaStore.h
//  Implementation of the Class CChicagoPizzaStore
//  Created on:      18-7��-2022 19:09:29
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
	static CChicagoPizzaStore* GetInstance();
	CChicagoPizzaStore(const CChicagoPizzaStore&) = delete;
	CChicagoPizzaStore& operator=(const CChicagoPizzaStore&) = delete;
	CPizza* CreatePizza(enPizzaStype enStype);
private:
	CChicagoPizzaStore();                ;
};
#endif 