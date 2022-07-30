///////////////////////////////////////////////////////////
//  SteamedMilk.h
//  Implementation of the Class SteamedMilk
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _STEAMED_MILK_H_
#define _STEAMED_MILK_H_

#include "Beverages.h"
#include "CondimentDecorator.h"

/**
 * Summary description for SteamedMilk.
 */
class SteamedMilk : public CCondimentDecorator
{

public:
	virtual ~SteamedMilk();
	static  SteamedMilk* GetInstance(CBeverage* pBeverage);
	double Cost() override;
	std::string GetDescription();

private:
	SteamedMilk();
	SteamedMilk(CBeverage* pBeverage);

private:
	CBeverage *        m_pBeverage;

};
#endif // !defined(EA_8E421417_2F31_4598_B4DE_0D60F59AF0D9__INCLUDED_)
