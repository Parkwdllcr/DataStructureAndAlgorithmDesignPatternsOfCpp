///////////////////////////////////////////////////////////
//  CChicagoPizzlngredientFactory.cpp
//  Implementation of the Class CChicagoPizzlngredientFactory
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CChicagoPizzlngredientFactory.h"



CChicagoPizzlngredientFactory::CChicagoPizzlngredientFactory() 
{

}
CChicagoPizzlngredientFactory* CChicagoPizzlngredientFactory::GetInstance()
{
	static CChicagoPizzlngredientFactory g_Instance;
	return &g_Instance;
}



CChicagoPizzlngredientFactory::~CChicagoPizzlngredientFactory()
{
	
}


ImpCheese* CChicagoPizzlngredientFactory::CreatCheese()
{
	try
	{
		ImpCheese* pImpCheese = nullptr;
		if (nullptr == pImpCheese)
		{
			pImpCheese = CReggianoCheese::GetInstance();
			return  pImpCheese;
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
		ImpClam* pImpClam = nullptr;
		if (nullptr == pImpClam)
		{
			pImpClam =  CFreshClams::GetInstance();
			return pImpClam;
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
		ImpDough* pImpDough = nullptr;
		if (nullptr == pImpDough)
		{
			pImpDough =  CThinCrustDough::GetInstance();
			return pImpDough;
		}
		return nullptr;
	}
	catch (const std::exception&)
	{
		return  nullptr;
	}
}



