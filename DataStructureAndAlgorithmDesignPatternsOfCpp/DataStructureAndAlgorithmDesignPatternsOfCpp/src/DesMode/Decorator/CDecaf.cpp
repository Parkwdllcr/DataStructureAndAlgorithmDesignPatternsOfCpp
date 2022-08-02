///////////////////////////////////////////////////////////
//  Decaf.cpp
//  Implementation of the Class Decaf
//  Created on:      26-7��-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/CDecaf.h"


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
	double dbResult = 2.9;
	SetSize(dbResult);
	GetSize(dbResult);
	return dbResult;
}


std::string CDecaf::GetDescription() {
	std::string strName("CDecaf::GetDescription");
	return  strName;
}