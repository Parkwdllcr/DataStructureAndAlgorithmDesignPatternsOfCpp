///////////////////////////////////////////////////////////
//  CClamPizza.cpp
//  Implementation of the Class CClamPizza
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "CClamPizza.h"


CClamPizza::CClamPizza():m_pIngredientFactory(nullptr)
{

}


CClamPizza::CClamPizza(ImpPizzalngredientFactory* pPizzalngredientFactory) :
	m_pIngredientFactory(pPizzalngredientFactory)
{

}


CClamPizza::~CClamPizza(){

}


std::string CClamPizza::Prepare()
{
	std::string strName("CClamPizza::Prepare");
	m_pCheese = m_pIngredientFactory->CreatCheese();
	m_pClam = m_pIngredientFactory->CreateClam();
	m_pDough = m_pIngredientFactory->CreateDough();

	strName = strName + m_strName + "\n";
	strName = strName + m_pCheese->ToString() + "\n";
	strName = strName + m_pClam->ToString() + "\n";
	strName = strName + m_pDough->ToString() + "\n";

	return strName;
}