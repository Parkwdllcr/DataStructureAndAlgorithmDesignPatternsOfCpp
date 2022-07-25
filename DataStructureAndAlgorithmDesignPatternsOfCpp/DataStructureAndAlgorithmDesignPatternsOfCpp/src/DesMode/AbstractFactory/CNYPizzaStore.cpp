///////////////////////////////////////////////////////////
//  CNYPizzaStore.cpp
//  Implementation of the Class CNYPizzaStore
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CNYPizzaStore.h"
#include <iostream>


CNYPizzaStore* CNYPizzaStore::GetInstance()
{
	static CNYPizzaStore g_Instance;
	return &g_Instance;
}

CNYPizzaStore::CNYPizzaStore() 
{

}

CNYPizzaStore::~CNYPizzaStore()
{
	
}


CPizza* CNYPizzaStore::CreatePizza(enPizzaStype enStype)
{
	std::string strName("");
	ImpPizzalngredientFactory* pChicagoPizzaIngredientFacttory = CNYPizzlngredientFactory::GetInstance();
	CPizza* pPizza = nullptr;
	switch (enStype)
	{
	case CheesePizza:
		pPizza = CCheesePizza::GetInstance(pChicagoPizzaIngredientFacttory);
		strName = "CNYPizzaStore Style Cheese Pizza";
		pPizza->SetName(strName);
		break;
	case ClamPizza:
		pPizza = CClamPizza::GetInstance(pChicagoPizzaIngredientFacttory);
		strName = "CNYPizzaStore Clam Pizza";
		pPizza->SetName(strName);
		break;
	default:
		std::cout << "Input Error Pizza stype!" << std::endl;
		break;
	}

	return  pPizza;
}