///////////////////////////////////////////////////////////
//  Decaf.cpp
//  Implementation of the Class Decaf
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/Decaf.h"


CDecaf* CDecaf::GetInstance()
{
	static CDecaf g_instance;
	return &g_instance;
}

CDecaf::~CDecaf() {

}




CDecaf::CDecaf() {

}


double CDecaf::Cost() {

	return 0;
}


std::string CDecaf::GetDescription() {
	std::string strName("lt");
	return  strName;
}