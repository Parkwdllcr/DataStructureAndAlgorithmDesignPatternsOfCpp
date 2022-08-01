///////////////////////////////////////////////////////////
//  Beverage.h
//  Implementation of the Class Beverage
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////
#ifndef _BEVERAGES_H_
#define _BEVERAGES_H_


#include "BeverageSize.h"
#include <string>

class CBeverage
{
public:
	virtual ~CBeverage();
	CBeverage();

	virtual double Cost() = 0;
	std::string GetDescription();
	bool GetSize(enumBeverageSize enumBerSize);
	bool SetSize(const enumBeverageSize enumBerSize);

private:
	enumBeverageSize m_enumSize;

};
#endif // !defined(EA_23292275_1931_4a4f_8A2F_CA3ECA6305C5__INCLUDED_)
