///////////////////////////////////////////////////////////
//  SteamedMilk.h
//  Implementation of the Class SteamedMilk
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _STEAMED_MILK_H_
#define _STEAMED_MILK_H_

#include "CBeverages.h"
#include "CondimentDecorator.h"

/**
 * Summary description for SteamedMilk.
 */
class CSteamedMilk : public CCondimentDecorator
{

public:
	virtual ~CSteamedMilk();
	static  CSteamedMilk* GetInstance(CBeverage* pBeverage);
	virtual double Cost() override;
	virtual std::string GetDescription();

private:
	CSteamedMilk();
	CSteamedMilk(CBeverage* pBeverage);

private:
	CBeverage *        m_pBeverage;

};
#endif // !defined(EA_8E421417_2F31_4598_B4DE_0D60F59AF0D9__INCLUDED_)
