///////////////////////////////////////////////////////////
//  CNYPizzaStore.cpp
//  Implementation of the Class CNYPizzaStore
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CNYPizzaStore.h"
#include "DesMode/AbstractFactory/CClamPizza.h"
#include "DesMode/AbstractFactory/CCheesePizza.h"
#include <iostream>

CNYPizzaStore::CNYPizzaStore() :m_pChicagoPizzaIngredientFacttory(nullptr)
{

}

CNYPizzaStore::~CNYPizzaStore()
{
	if (nullptr != m_pChicagoPizzaIngredientFacttory)
	{
		delete m_pChicagoPizzaIngredientFacttory;
		m_pChicagoPizzaIngredientFacttory = nullptr;
	}
}




CPizza* CNYPizzaStore::CreatePizza(enPizzaStype enStype)
{
	std::string strName("");
	CPizza* pPizza = nullptr;
	m_pChicagoPizzaIngredientFacttory = new CNYPizzlngredientFactory();

	switch (enStype)
	{
	case CheesePizza:
		pPizza = new CCheesePizza(m_pChicagoPizzaIngredientFacttory);
		strName = "CNYPizzaStore Style Cheese Pizza";
		pPizza->SetName(strName);
		break;
	case ClamPizza:
		pPizza = new CClamPizza(m_pChicagoPizzaIngredientFacttory);
		strName = "CNYPizzaStore Clam Pizza";
		pPizza->SetName(strName);
		break;
	default:
		std::cout << "Input Error Pizza stype!" << std::endl;
		break;
	}

	return  pPizza;
}