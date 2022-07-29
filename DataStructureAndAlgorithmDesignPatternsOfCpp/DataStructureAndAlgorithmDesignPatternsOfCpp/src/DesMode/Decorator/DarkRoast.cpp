///////////////////////////////////////////////////////////
//  DarkRoast.cpp
//  Implementation of the Class DarkRoast
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/DarkRoast.h"





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

	return 0;
}


std::string CDarkRoast::GetDescription()
{
	std::string strName("lcr");
	return  strName;
}