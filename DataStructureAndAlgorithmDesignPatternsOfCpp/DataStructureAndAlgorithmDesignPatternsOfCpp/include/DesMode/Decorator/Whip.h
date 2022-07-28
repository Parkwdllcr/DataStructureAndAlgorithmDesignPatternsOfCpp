///////////////////////////////////////////////////////////
//  Whip.h
//  Implementation of the Class Whip
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _WHIP_H_
#define _WHIP_H_

#include "Beverages.h"
#include "CondimentDecorator.h"


class Whip : public CCondimentDecorator
{

public:
	virtual ~Whip();
	static Whip* GetInstance(CBeverage* pBeverage);

public:
	double Cost() override;
	std::string GetDescription() override;

private:
	Whip(CBeverage* pBeverage);
	Whip();
private:
	CBeverage*  m_pBeverage;

};
#endif // !defined(EA_3749E8C0_5CC8_47a2_8BB0_91954454CF82__INCLUDED_)
