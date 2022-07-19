///////////////////////////////////////////////////////////
//  ImpPizzalngredientFactory.h
//  Implementation of the Interface ImpPizzalngredientFactory
//  Created on:      18-7月-2022 19:09:31
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _IMP_PIZZA_LNGREDIENT_FACTORY_H_
#define _IMP_PIZZA_LNGREDIENT_FACTORY_H_
/**
 * 披萨的原料工厂
 * 
 * 原料也是抽象,根据不同场景店家，生产不同的原料
 * 
 * 原料包括：
 * 1. 面团Dough
 * 2. 奶酪Cheese
 * 3. 蛤Clam
 */

#include "ImpCheese.h"
#include "ImpClam.h"
#include "ImpDough.h"

class ImpPizzalngredientFactory
{
public:
	virtual ImpCheese* CreatCheese() =0;
	virtual ImpClam* CreateClam() =0;
	virtual ImpDough* CreateDough() =0;
	virtual ~ImpPizzalngredientFactory() {}
};
#endif
