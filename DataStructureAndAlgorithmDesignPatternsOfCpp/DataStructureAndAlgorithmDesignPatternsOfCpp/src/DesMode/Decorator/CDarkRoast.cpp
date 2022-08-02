///////////////////////////////////////////////////////////
//  DarkRoast.cpp
//  Implementation of the Class DarkRoast
//  Created on:      26-7ÔÂ-2022 21:56:43
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
	double dbResult = 1.9;
	SetSize(dbResult);
	GetSize(dbResult);
	return dbResult;

}
std::string CDarkRoast::GetDescription()
{
	std::string strName("CDarkRoast::GetDescription");
	return  strName;
}