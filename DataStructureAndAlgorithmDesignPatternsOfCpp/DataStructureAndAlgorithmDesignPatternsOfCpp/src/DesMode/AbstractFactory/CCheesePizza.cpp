///////////////////////////////////////////////////////////
//  CCheesePizza.cpp
//  Implementation of the Class CCheesePizza
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "CCheesePizza.h"




CCheesePizza::CCheesePizza() :m_pIngredientFactory(nullptr)
{

}



CCheesePizza::CCheesePizza(ImpPizzalngredientFactory* pIngredientFactory):m_pIngredientFactory(pIngredientFactory)
{

}

CCheesePizza::~CCheesePizza(){

}



std::string CCheesePizza::Prepare()
{
	std::string strName("CCheesePizza::Prepare");
    m_pCheese = m_pIngredientFactory->CreatCheese();
	m_pClam = m_pIngredientFactory->CreateClam();
    m_pDough = m_pIngredientFactory->CreateDough();
	
	strName = strName + m_strName+"\n";
	strName = strName + m_pCheese->ToString() + "\n";
	strName = strName + m_pClam->ToString() + "\n";
	strName = strName + m_pDough->ToString() + "\n";

	return  strName;
}