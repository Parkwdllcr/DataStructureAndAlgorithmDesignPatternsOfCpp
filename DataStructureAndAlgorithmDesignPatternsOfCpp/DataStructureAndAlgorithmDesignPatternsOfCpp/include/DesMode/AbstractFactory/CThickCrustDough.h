///////////////////////////////////////////////////////////
//  CThickCrustDough.h
//  Implementation of the Class CThickCrustDough
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _THICK_CRUST_DOUGH_H_
#define _THICK_CRUST_DOUGH_H_

#include "ImpDough.h"

class CThickCrustDough : public ImpDough
{

public:
	CThickCrustDough();
	virtual ~CThickCrustDough();
	std::string ToString();

};
#endif 
