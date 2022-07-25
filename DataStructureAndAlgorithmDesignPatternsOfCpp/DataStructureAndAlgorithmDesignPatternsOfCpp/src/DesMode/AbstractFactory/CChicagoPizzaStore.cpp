///////////////////////////////////////////////////////////
//  CChicagoPizzaStore.cpp
//  Implementation of the Class CChicagoPizzaStore
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CChicagoPizzaStore.h"
#include "DesMode/AbstractFactory/CCheesePizza.h"
#include "DesMode/AbstractFactory/CClamPizza.h"
#include <iostream>


CChicagoPizzaStore* CChicagoPizzaStore::GetInstance()
{
	static CChicagoPizzaStore g_Instance;
	return &g_Instance;
}

CChicagoPizzaStore::CChicagoPizzaStore() 
{

}

CChicagoPizzaStore::~CChicagoPizzaStore()
{
	
}




CPizza* CChicagoPizzaStore::CreatePizza(enPizzaStype enStype)
{
	std::string strName("");
	ImpPizzalngredientFactory* pChicagoPizzaIngredientFacttory = CChicagoPizzlngredientFactory::GetInstance();
	CPizza* pPizza = nullptr;
	switch (enStype)
	{
	case CheesePizza:
		pPizza = CCheesePizza::GetInstance(pChicagoPizzaIngredientFacttory);
		strName = "CCheesePizza Style Cheese Pizza";
		pPizza->SetName(strName);
		break;
	case ClamPizza:
		pPizza = CClamPizza::GetInstance(pChicagoPizzaIngredientFacttory);
		strName = "CClamPizza Style Cheese Pizza";
		pPizza->SetName(strName);
		break;
	default:
		std::cout << "Input Error Pizza stype" << std::endl;
		break;
	}

	return  pPizza;
}