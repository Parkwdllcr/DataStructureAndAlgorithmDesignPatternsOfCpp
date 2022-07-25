///////////////////////////////////////////////////////////
//  CThinCrustDough.h
//  Implementation of the Class CThinCrustDough
//  Created on:      18-7��-2022 19:09:31
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _THIN_CRUST_DOUGH_H_
#define _THIN_CRUST_DOUGH_H_

#include "ImpDough.h"

class CThinCrustDough : public ImpDough
{

public:
	static CThinCrustDough* GetInstance();
	CThinCrustDough(const CThinCrustDough&) = delete;
	CThinCrustDough& operator=(const CThinCrustDough&) = delete;
	virtual ~CThinCrustDough();

public:
	std::string ToString();
private:
	CThinCrustDough();

};
#endif 
