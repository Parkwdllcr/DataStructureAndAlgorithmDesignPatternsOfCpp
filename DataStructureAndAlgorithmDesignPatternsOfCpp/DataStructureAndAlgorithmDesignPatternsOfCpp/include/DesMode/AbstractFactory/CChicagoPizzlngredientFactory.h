///////////////////////////////////////////////////////////
//  CChicagoPizzlngredientFactory.h
//  Implementation of the Class CChicagoPizzlngredientFactory
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////
#ifndef _CHICAGO_PIZZA_LNGREDIENT_FACTORY_H_
#define _CHICAGO_PIZZA_LNGREDIENT_FACTORY_H_

#include "ImpPizzalngredientFactory.h"
#include "CReggianoCheese.h"
#include "CThinCrustDough.h"
#include "CFreshClams.h"

class CChicagoPizzlngredientFactory : public ImpPizzalngredientFactory
{

public:
	static CChicagoPizzlngredientFactory* GetInstance();
	CChicagoPizzlngredientFactory& operator=(const CChicagoPizzlngredientFactory&) = delete;
	CChicagoPizzlngredientFactory(const CChicagoPizzlngredientFactory&) = delete;
	virtual ~CChicagoPizzlngredientFactory();
public:
	ImpCheese* CreatCheese();
	ImpClam* CreateClam();
	ImpDough* CreateDough();
private:
	CChicagoPizzlngredientFactory();
};
#endif 
