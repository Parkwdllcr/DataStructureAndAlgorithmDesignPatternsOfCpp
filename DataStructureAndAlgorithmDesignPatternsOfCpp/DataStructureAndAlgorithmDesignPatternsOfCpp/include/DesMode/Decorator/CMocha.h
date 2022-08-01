///////////////////////////////////////////////////////////
//  Mocha.h
//  Implementation of the Class Mocha
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _MOCHA_H_
#define _MOCHA_H_

#include "CBeverages.h"
#include "CondimentDecorator.h"


class CMocha : public CCondimentDecorator
{
public:
	virtual ~CMocha();
	static CMocha* Getinstance(CBeverage* pBeverage);
	double Cost() ;
	std::string GetDescription();

private:
	CMocha(CBeverage* pBeverage);
	CMocha();

private:
	CBeverage* m_pBeverage;

};
#endif 