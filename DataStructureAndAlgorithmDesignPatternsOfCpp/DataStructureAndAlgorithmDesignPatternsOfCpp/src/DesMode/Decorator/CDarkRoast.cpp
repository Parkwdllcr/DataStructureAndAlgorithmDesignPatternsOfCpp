///////////////////////////////////////////////////////////
//  DarkRoast.cpp
//  Implementation of the Class DarkRoast
//  Created on:      26-7��-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/CDarkRoast.h"


CDarkRoast* CDarkRoast::GetInstance()
{
	static CDarkRoast g_instance;
	return &g_instance;
}

CDarkRoast::~CDarkRoast() {

}


CDarkRoast::CDarkRoast() {

}


double CDarkRoast::Cost() {

	return 1.9;
}


std::string CDarkRoast::GetDescription()
{
	std::string strName("CDarkRoast::GetDescription");
	return  strName;
}