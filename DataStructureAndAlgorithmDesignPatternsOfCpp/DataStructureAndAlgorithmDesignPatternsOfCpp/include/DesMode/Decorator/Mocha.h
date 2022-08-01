///////////////////////////////////////////////////////////
//  Mocha.h
//  Implementation of the Class Mocha
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _MOCHA_H_
#define _MOCHA_H_

#include "Beverages.h"
#include "CondimentDecorator.h"


class Mocha : public CCondimentDecorator
{

public:
	virtual ~Mocha();
	static Mocha* Getinstance(CBeverage* pBeverage);
	double Cost() ;
	std::string GetDescription();

private:
	Mocha(CBeverage* pBeverage);
	Mocha();

private:
	CBeverage* m_pBeverage;
	double GetSize(enumBeverageSize size);

};
#endif 