///////////////////////////////////////////////////////////
//  ImpDough.h
//  Implementation of the Interface ImpDough
//  Created on:      18-7ÔÂ-2022 19:09:31
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _IMPDOUGH_H_
#define _IMPDOUGH_H_
#include<string>

class ImpDough
{

public:
	virtual ~ImpDough() {}
	virtual std::string ToString() =0;

};
#endif 
