///////////////////////////////////////////////////////////
//  ImpClam.h
//  Implementation of the Interface ImpClam
//  Created on:      18-7ÔÂ-2022 19:09:31
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////


#ifndef _IMPCLAM_H_
#define _IMPCLAM_H_
#include <string>

class ImpClam
{

public:
	virtual ~ImpClam() {}
	virtual std::string ToString() =0;

};
#endif 