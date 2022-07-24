///////////////////////////////////////////////////////////
//  CThickCrustDough.cpp
//  Implementation of the Class CThickCrustDough
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CThickCrustDough.h"



CThickCrustDough* CThickCrustDough::GetInstance()
{
	static CThickCrustDough g_Instance;
	return &g_Instance;
}

CThickCrustDough::CThickCrustDough()
{

}

CThickCrustDough::~CThickCrustDough(){

}

std::string CThickCrustDough::ToString()
{
	std::string  strName("This is  CThickCrustDough");
	return  strName;
}