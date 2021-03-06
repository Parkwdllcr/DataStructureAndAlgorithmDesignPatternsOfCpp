///////////////////////////////////////////////////////////
//  CNYPizzlngredientFactory.h
//  Implementation of the Class CNYPizzlngredientFactory
//  Created on:      18-7??-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _NY_PIZZA_LNGREDIENT_FACTORY_H_
#define _NY_PIZZA_LNGREDIENT_FACTORY_H_

#include "ImpPizzalngredientFactory.h"
#include "CMozzarellaCheese.h"
#include "CFrozenClams.h"
#include "CThickCrustDough.h"

/**
 * ŦԼ????????
 */
class CNYPizzlngredientFactory :public ImpPizzalngredientFactory
{

public:
	
	virtual ~CNYPizzlngredientFactory();
	static CNYPizzlngredientFactory* GetInstance();
	CNYPizzlngredientFactory(const CNYPizzlngredientFactory&) = delete;
	CNYPizzlngredientFactory& operator=(const CNYPizzlngredientFactory&) = delete;

	virtual ImpCheese* CreatCheese();
	virtual ImpClam* CreateClam();
	virtual ImpDough* CreateDough();

private:
	CNYPizzlngredientFactory();
};

#endif
