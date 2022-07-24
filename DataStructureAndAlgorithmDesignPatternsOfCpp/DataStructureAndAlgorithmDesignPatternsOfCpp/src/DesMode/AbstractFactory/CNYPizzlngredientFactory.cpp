///////////////////////////////////////////////////////////
//  CNYPizzlngredientFactory.cpp
//  Implementation of the Class CNYPizzlngredientFactory
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CNYPizzlngredientFactory.h"


CNYPizzlngredientFactory::CNYPizzlngredientFactory()
{

}

CNYPizzlngredientFactory::~CNYPizzlngredientFactory()
{
	
}


CNYPizzlngredientFactory* CNYPizzlngredientFactory::GetInstance()
{
	static CNYPizzlngredientFactory  g_Instance;
	return &g_Instance;
}

ImpCheese* CNYPizzlngredientFactory::CreatCheese()
{
	try
	{
		ImpCheese* pImpCheese = nullptr;
		if (pImpCheese == nullptr)
		{
			ImpCheese* pImpCheese = CMozzarellaCheese::GetInstance();
			return  pImpCheese;
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
		ImpClam* pImpCham = nullptr;
		if (pImpCham == nullptr)
		{
			ImpClam* pImpCham = CFrozenClams::GetInstance();
			return pImpCham;
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
		ImpDough* pImpDough = nullptr;
		if (pImpDough == nullptr)
		{
			pImpDough = CThickCrustDough::GetInstance();
			return  pImpDough;
		}
		return nullptr;
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}
