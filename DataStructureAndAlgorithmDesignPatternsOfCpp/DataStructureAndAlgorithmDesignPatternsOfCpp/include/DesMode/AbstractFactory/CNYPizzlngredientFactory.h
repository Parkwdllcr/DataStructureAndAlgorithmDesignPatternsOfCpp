///////////////////////////////////////////////////////////
//  CNYPizzlngredientFactory.h
//  Implementation of the Class CNYPizzlngredientFactory
//  Created on:      18-7月-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _NY_PIZZA_LNGREDIENT_FACTORY_H_
#define _NY_PIZZA_LNGREDIENT_FACTORY_H_

#include "ImpPizzalngredientFactory.h"
#include "CMozzarellaCheese.h"
#include "CFrozenClams.h"
#include "CThickCrustDough.h"

/**
 * 纽约披萨工厂
 */
class CNYPizzlngredientFactory :public ImpPizzalngredientFactory
{

public:
	CNYPizzlngredientFactory();
	virtual ~CNYPizzlngredientFactory();

	virtual ImpCheese* CreatCheese();
	virtual ImpClam* CreateClam();
	virtual ImpDough* CreateDough();

public:
	ImpCheese*       m_pImpCheese;
	ImpClam*         m_pImpClam;
	ImpDough*        m_pImpDough;
};

#endif
