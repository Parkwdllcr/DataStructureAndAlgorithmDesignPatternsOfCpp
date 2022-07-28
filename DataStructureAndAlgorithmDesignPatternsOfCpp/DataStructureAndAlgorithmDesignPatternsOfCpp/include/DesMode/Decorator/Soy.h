///////////////////////////////////////////////////////////
//  Soy.h
//  Implementation of the Class Soy
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_0B964495_5B93_4cfa_9982_DE9B5BDE4FBF__INCLUDED_)
#define EA_0B964495_5B93_4cfa_9982_DE9B5BDE4FBF__INCLUDED_

#include "Beverages.h"
#include "CondimentDecorator.h"

/**
 * Summary description for Soy.
 */
class Soy : public CCondimentDecorator
{

public:
	virtual ~Soy();
	static Soy* GetInstance(CBeverage* pBeverage);

public:
	double Cost() override;
	std::string GetDescription();

private:
	Soy(CBeverage* pBeverage);
	Soy();
private:
	CBeverage*          m_pBeverage;

};
#endif // !defined(EA_0B964495_5B93_4cfa_9982_DE9B5BDE4FBF__INCLUDED_)
