///////////////////////////////////////////////////////////
//  CNYPizzaStore.h
//  Implementation of the Class CNYPizzaStore
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _NYPIZZA_STORE_H_
#define _NYPIZZA_STORE_H_

#include "CPizzaStore.h"
#include "CNYPizzlngredientFactory.h"
#include "DesMode/AbstractFactory/CClamPizza.h"
#include "DesMode/AbstractFactory/CCheesePizza.h"

class CNYPizzaStore : public CPizzaStore
{

public:
	virtual ~CNYPizzaStore();
	static CNYPizzaStore* GetInstance();
	CNYPizzaStore(const CNYPizzaStore&) = delete;
	CNYPizzaStore& operator=(const CNYPizzaStore&) = delete;
	CPizza* CreatePizza(enPizzaStype enStype);
private:
	CNYPizzaStore();

};
#endif 