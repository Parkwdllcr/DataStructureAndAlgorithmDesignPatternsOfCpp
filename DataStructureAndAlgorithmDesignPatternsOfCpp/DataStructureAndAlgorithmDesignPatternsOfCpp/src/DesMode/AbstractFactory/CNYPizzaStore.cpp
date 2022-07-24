///////////////////////////////////////////////////////////
//  CNYPizzaStore.cpp
//  Implementation of the Class CNYPizzaStore
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CNYPizzaStore.h"
#include <iostream>

CNYPizzaStore::CNYPizzaStore() :m_pChicagoPizzaIngredientFacttory(nullptr),m_pPizza(nullptr)
{

}

CNYPizzaStore::~CNYPizzaStore()
{
	if (nullptr != m_pChicagoPizzaIngredientFacttory)
	{
		delete m_pChicagoPizzaIngredientFacttory;
		m_pChicagoPizzaIngredientFacttory = nullptr;
	}
	if (nullptr != m_pPizza)
	{
		delete m_pPizza;
		m_pPizza = nullptr;
	}
}




CPizza* CNYPizzaStore::CreatePizza(enPizzaStype enStype)
{
	std::string strName("");
	m_pChicagoPizzaIngredientFacttory = new CNYPizzlngredientFactory();

	switch (enStype)
	{
	case CheesePizza:
		m_pPizza = new CCheesePizza(m_pChicagoPizzaIngredientFacttory);
		strName = "CNYPizzaStore Style Cheese Pizza";
		m_pPizza->SetName(strName);
		break;
	case ClamPizza:
		m_pPizza = new CClamPizza(m_pChicagoPizzaIngredientFacttory);
		strName = "CNYPizzaStore Clam Pizza";
		m_pPizza->SetName(strName);
		break;
	default:
		std::cout << "Input Error Pizza stype!" << std::endl;
		break;
	}

	return  m_pPizza;
}