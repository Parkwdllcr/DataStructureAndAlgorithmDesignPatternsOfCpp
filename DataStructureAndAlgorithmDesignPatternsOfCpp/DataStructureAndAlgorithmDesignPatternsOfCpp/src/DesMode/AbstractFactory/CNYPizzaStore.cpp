///////////////////////////////////////////////////////////
//  CNYPizzaStore.cpp
//  Implementation of the Class CNYPizzaStore
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "CNYPizzaStore.h"
#include "CNYPizzlngredientFactory.h"
#include "CClamPizza.h"
#include "CCheesePizza.h"
#include <iostream>

CNYPizzaStore::CNYPizzaStore()
{

}

CNYPizzaStore::~CNYPizzaStore()
{

}




CPizza* CNYPizzaStore::CreatePizza(enPizzaStype enStype)
{
	std::string strName("");
	CPizza* pPizza = nullptr;
	ImpPizzalngredientFactory* pChicagoPizzaIngredientFacttory = new CNYPizzlngredientFactory();

	switch (enStype)
	{
	case CheesePizza:
		pPizza = new CCheesePizza(pChicagoPizzaIngredientFacttory);
		strName = "CNYPizzaStore Style Cheese Pizza";
		pPizza->SetName(strName);
		break;
	case ClamPizza:
		pPizza = new CClamPizza(pChicagoPizzaIngredientFacttory);
		strName = "CNYPizzaStore Clam Pizza";
		pPizza->SetName(strName);
		break;
	default:
		std::cout << "Input Error Pizza stype!" << std::endl;
		break;
	}

	delete pChicagoPizzaIngredientFacttory;
	pChicagoPizzaIngredientFacttory = nullptr;
	return  pPizza;
}