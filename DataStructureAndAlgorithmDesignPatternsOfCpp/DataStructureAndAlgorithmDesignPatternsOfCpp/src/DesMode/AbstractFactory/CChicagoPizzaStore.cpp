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


CChicagoPizzaStore::CChicagoPizzaStore() :m_pChicagoPizzaIngredientFacttory(nullptr),m_pPizza(nullptr)
{

}

CChicagoPizzaStore::~CChicagoPizzaStore()
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


CPizza* CChicagoPizzaStore::CreatePizza(enPizzaStype enStype)
{
	std::string strName("");
	m_pChicagoPizzaIngredientFacttory = new CChicagoPizzlngredientFactory();

	switch (enStype)
	{
	case CheesePizza:
		m_pPizza = new CCheesePizza(m_pChicagoPizzaIngredientFacttory);
		strName = "CCheesePizza Style Cheese Pizza";
		m_pPizza->SetName(strName);
		break;
	case ClamPizza:
		m_pPizza = new CClamPizza(m_pChicagoPizzaIngredientFacttory);
		strName = "CClamPizza Style Cheese Pizza";
		m_pPizza->SetName(strName);
		break;
	default:
		std::cout << "Input Error Pizza stype" << std::endl;
		break;
	}

	return  m_pPizza;
}