///////////////////////////////////////////////////////////
//  DarkRoast.h
//  Implementation of the Class DarkRoast
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _DARK_ROAST_H_
#define _DARK_ROAST_H_


#include "CBeverages.h"


class CDarkRoast : public CBeverage
{
public:
	virtual ~CDarkRoast();
	static CDarkRoast* GetInstance();
	double Cost();
	std::string GetDescription() ;
private:
	CDarkRoast();

};
#endif
