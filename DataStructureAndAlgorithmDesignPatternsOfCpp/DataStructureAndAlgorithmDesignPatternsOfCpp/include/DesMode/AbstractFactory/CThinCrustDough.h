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
	CThinCrustDough(const CThinCrustDough&) = delete;
	CThinCrustDough& operator=(const CThinCrustDough&) = delete;
	virtual ~CThinCrustDough();

	static CThinCrustDough* GetInstance();
public:
	std::string ToString();
private:
	CThinCrustDough();

};
#endif 
