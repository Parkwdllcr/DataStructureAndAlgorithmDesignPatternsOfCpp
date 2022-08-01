///////////////////////////////////////////////////////////
//  Whip.h
//  Implementation of the Class Whip
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _WHIP_H_
#define _WHIP_H_

#include "CBeverages.h"
#include "CondimentDecorator.h"


class CWhip : public CCondimentDecorator
{

public:
	virtual ~CWhip();
	static CWhip* GetInstance(CBeverage* pBeverage);

public:
	double Cost() override;
	std::string GetDescription();

private:
	CWhip(CBeverage* pBeverage);
	CWhip();
private:
	CBeverage*  m_pBeverage;

};
#endif 