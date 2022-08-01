///////////////////////////////////////////////////////////
//  Decaf.h
//  Implementation of the Class Decaf
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _DECAF_H_
#define _DECAF_H_

#include "CBeverages.h"


class CDecaf : public CBeverage
{

public:
	virtual ~CDecaf();
	static CDecaf* GetInstance();
	double Cost();
	std::string GetDescription();

private:
	CDecaf();
	

};
#endif 
