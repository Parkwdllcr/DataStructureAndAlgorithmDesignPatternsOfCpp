///////////////////////////////////////////////////////////
//  CNYPizzlngredientFactory.cpp
//  Implementation of the Class CNYPizzlngredientFactory
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CNYPizzlngredientFactory.h"


CNYPizzlngredientFactory::CNYPizzlngredientFactory():m_pImpCheese(nullptr),m_pImpClam(nullptr),m_pImpDough(nullptr)
{

}

CNYPizzlngredientFactory::~CNYPizzlngredientFactory()
{
	if (nullptr != m_pImpCheese)
	{
		delete m_pImpCheese;
		m_pImpCheese = nullptr;
	}

	if (nullptr != m_pImpClam)
	{
		delete m_pImpClam;
		m_pImpClam = nullptr;
	}

	if (nullptr != m_pImpDough)
	{
		delete m_pImpDough;
		m_pImpDough = nullptr;
	}
}


ImpCheese* CNYPizzlngredientFactory::CreatCheese()
{
	try
	{
		if (m_pImpCheese == nullptr)
		{
			m_pImpCheese = new CMozzarellaCheese();
			return  m_pImpCheese;
		}
		return nullptr;
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}


ImpClam* CNYPizzlngredientFactory::CreateClam()
{
	try
	{
		if (m_pImpClam == nullptr)
		{
			m_pImpClam = new CFrozenClams;
			return  m_pImpClam;
		}
		return nullptr;
	}
	catch (const std::exception&)
	{
		return nullptr;
	}

}


ImpDough* CNYPizzlngredientFactory::CreateDough()
{

	try
	{
		if (m_pImpDough == nullptr)
		{
			m_pImpDough = new CThickCrustDough;
			return  m_pImpDough;
		}
		return nullptr;
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}
