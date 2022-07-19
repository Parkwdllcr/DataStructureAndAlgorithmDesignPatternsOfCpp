///////////////////////////////////////////////////////////
//  CChicagoPizzaStore.cpp
//  Implementation of the Class CChicagoPizzaStore
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "CChicagoPizzaStore.h"
#include "CChicagoPizzlngredientFactory.h"
#include "CCheesePizza.h"
#include "CClamPizza.h"
#include <iostream>


CChicagoPizzaStore::CChicagoPizzaStore()
{

}

CChicagoPizzaStore::~CChicagoPizzaStore()
{

}


CPizza* CChicagoPizzaStore::CreatePizza(enPizzaStype enStype)
{
	std::string strName("");
	CPizza* pPizza = nullptr;
	ImpPizzalngredientFactory* pChicagoPizzaIngredientFacttory = new CChicagoPizzlngredientFactory();

	switch (enStype)
	{
	case CheesePizza:
		pPizza = new CCheesePizza(pChicagoPizzaIngredientFacttory);
		strName = "CCheesePizza Style Cheese Pizza";
		pPizza->SetName(strName);
		break;
	case ClamPizza:
		pPizza = new CClamPizza(pChicagoPizzaIngredientFacttory);
		strName = "CClamPizza Style Cheese Pizza";
		pPizza->SetName(strName);
		break;
	default:
		std::cout << "Input Error Pizza stype" << std::endl;
		break;
	}

	delete pChicagoPizzaIngredientFacttory;
	pChicagoPizzaIngredientFacttory = nullptr;
	return  pPizza;
}