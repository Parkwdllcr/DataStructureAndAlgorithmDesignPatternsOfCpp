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
	virtual ~CChicagoPizzlngredientFactory();

	CChicagoPizzlngredientFactory();
	ImpCheese* CreatCheese();
	ImpClam* CreateClam();
	ImpDough* CreateDough();
private:
	ImpCheese*        m_pImpCheese;
	ImpClam*          m_pImpClam;
	ImpDough*         m_pImpDough;
};
#endif 
