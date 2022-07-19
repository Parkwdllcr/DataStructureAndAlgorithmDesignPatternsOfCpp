///////////////////////////////////////////////////////////
//  CClamPizza.h
//  Implementation of the Class CClamPizza
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _CLAM_PIZZA_H_
#define _CLAM_PIZZA_H_

#include "CPizza.h"
#include "ImpPizzalngredientFactory.h"


class CClamPizza : public CPizza
{

public:
	CClamPizza(ImpPizzalngredientFactory* pPizzalngredientFactory);
	virtual ~CClamPizza();
	std::string Prepare();
private:
	ImpPizzalngredientFactory * m_pIngredientFactory;
	CClamPizza();

};
#endif 