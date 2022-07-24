///////////////////////////////////////////////////////////
//  CFreshClams.h
//  Implementation of the Class CFreshClams
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _FRESH_CLAMS_H_
#define _FRESH_CLAMS_H_

#include "ImpClam.h"
#include <string>

class CFreshClams : public ImpClam
{

public:
	static CFreshClams* GetInstance();
	virtual ~CFreshClams();
	CFreshClams(const CFreshClams&) = delete;
	CFreshClams& operator= (const CFreshClams&) = delete;
	std::string ToString();
private:
	CFreshClams();

};
#endif 