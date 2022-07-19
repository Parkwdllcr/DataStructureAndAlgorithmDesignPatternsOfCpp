///////////////////////////////////////////////////////////
//  CPizzaStore.h
//  Implementation of the Class CPizzaStore
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _PIZZA_STORE_H_
#define _PIZZA_STORE_H_

#include <string>
#include "CPizza.h"

typedef enum  
{
	CheesePizza = 0 ,
	ClamPizza,
} enPizzaStype;

class CPizzaStore
{

public:
	virtual ~CPizzaStore();
	CPizzaStore();
	virtual CPizza* CreatePizza(enPizzaStype enStype) = 0;
	CPizza* OrderPizza(enPizzaStype enStype);

};
#endif 
