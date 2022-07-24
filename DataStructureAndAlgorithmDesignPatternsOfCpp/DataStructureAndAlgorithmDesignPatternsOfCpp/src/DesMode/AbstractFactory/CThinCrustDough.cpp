///////////////////////////////////////////////////////////
//  CThinCrustDough.cpp
//  Implementation of the Class CThinCrustDough
//  Created on:      18-7��-2022 19:09:31
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CThinCrustDough.h"


CThinCrustDough::CThinCrustDough()
{

}

CThinCrustDough::~CThinCrustDough()
{

}

CThinCrustDough* CThinCrustDough::GetInstance()
{
	static CThinCrustDough g_instance;
	return &g_instance;
}



std::string CThinCrustDough::ToString()
{
	std::string strName("This is CThinCrustDough");
	return  strName;
}