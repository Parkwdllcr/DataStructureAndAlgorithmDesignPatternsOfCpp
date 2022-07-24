///////////////////////////////////////////////////////////
//  CFrozenClams.h
//  Implementation of the Class CFrozenClams
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _FROZEN_CLAMS_H_
#define _FROZEN_CLAMS_H_

#include "ImpClam.h"
#include <string>

class CFrozenClams : public ImpClam
{

public:
	
	virtual ~CFrozenClams();
	static CFrozenClams* GetInstance();
	std::string ToString();
private:
	CFrozenClams();

};
#endif 
