///////////////////////////////////////////////////////////
//  Expresso.cpp
//  Implementation of the Class Expresso
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/CExpresso.h"



CExpresso* CExpresso::GetInstance()
{
	static CExpresso g_instance;
	return &g_instance;
}

CExpresso::~CExpresso() {

}


CExpresso::CExpresso() {

}


double CExpresso::Cost() {
	double dbResult = 3.9;
	SetSize(dbResult);
	GetSize(dbResult);
	return dbResult;
}


std::string CExpresso::GetDescription() 
{
	std::string strDescription("CExpresso::GetDescription");
	return  strDescription;
}




