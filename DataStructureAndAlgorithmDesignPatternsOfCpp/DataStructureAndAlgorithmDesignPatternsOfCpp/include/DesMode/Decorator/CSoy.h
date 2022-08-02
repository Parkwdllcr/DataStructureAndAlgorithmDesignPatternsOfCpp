///////////////////////////////////////////////////////////
//  Soy.h
//  Implementation of the Class Soy
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _SOY_H_
#define _SOY_H_

#include "CBeverages.h"
#include "CondimentDecorator.h"

/**
 * Summary description for Soy.
 */
class CSoy : public CCondimentDecorator
{

public:
	virtual ~CSoy();
	static CSoy* GetInstance(CBeverage* pBeverage);

public:
	virtual double Cost() override;
	virtual std::string GetDescription();

private:
	CSoy(CBeverage* pBeverage);

private:
	CBeverage*          m_pBeverage;

};
#endif // !defined(EA_0B964495_5B93_4cfa_9982_DE9B5BDE4FBF__INCLUDED_)
