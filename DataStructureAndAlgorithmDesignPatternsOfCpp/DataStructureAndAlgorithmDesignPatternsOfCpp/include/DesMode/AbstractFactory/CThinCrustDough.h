///////////////////////////////////////////////////////////
//  CThinCrustDough.h
//  Implementation of the Class CThinCrustDough
//  Created on:      18-7ÔÂ-2022 19:09:31
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _THIN_CRUST_DOUGH_H_
#define _THIN_CRUST_DOUGH_H_

#include "ImpDough.h"

class CThinCrustDough : public ImpDough
{

public:
	CThinCrustDough();
	virtual ~CThinCrustDough();
	std::string ToString();

};
#endif 
