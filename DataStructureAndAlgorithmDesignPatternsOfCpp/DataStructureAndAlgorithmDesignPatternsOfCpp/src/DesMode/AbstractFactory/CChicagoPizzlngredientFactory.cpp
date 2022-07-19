///////////////////////////////////////////////////////////
//  CChicagoPizzlngredientFactory.cpp
//  Implementation of the Class CChicagoPizzlngredientFactory
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "CChicagoPizzlngredientFactory.h"


CChicagoPizzlngredientFactory::CChicagoPizzlngredientFactory():m_pImpCheese(nullptr), m_pImpClam(nullptr), m_pImpDough(nullptr)
{

}

CChicagoPizzlngredientFactory::~CChicagoPizzlngredientFactory()
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
		delete  m_pImpDough;
		m_pImpDough = nullptr;
	}
}




ImpCheese* CChicagoPizzlngredientFactory::CreatCheese()
{
	try
	{
		if (nullptr == m_pImpCheese)
		{
			m_pImpCheese = new CReggianoCheese;
			return  m_pImpCheese;
		}
		return nullptr;
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}


ImpClam* CChicagoPizzlngredientFactory::CreateClam()
{
	try
	{
		if (nullptr == m_pImpClam)
		{
			m_pImpClam = new CFreshClams;
			return m_pImpClam;
		}
		return nullptr;
	}
	catch (const std::exception&)
	{
		return  nullptr;
	}
	
}


ImpDough* CChicagoPizzlngredientFactory::CreateDough()
{

	try
	{
		if (nullptr == m_pImpDough)
		{
			m_pImpDough = new CThinCrustDough;
			return m_pImpDough;
		}
		return nullptr;
	}
	catch (const std::exception&)
	{
		return  nullptr;
	}
}



