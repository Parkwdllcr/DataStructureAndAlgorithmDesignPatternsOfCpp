///////////////////////////////////////////////////////////
//  CReggianoCheese.cpp
//  Implementation of the Class CReggianoCheese
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CReggianoCheese.h"



CReggianoCheese* CReggianoCheese::GetInstance()
{
	static CReggianoCheese g_Instance;
	return &g_Instance;
}

CReggianoCheese::CReggianoCheese() {

}
CReggianoCheese::~CReggianoCheese()
{

}


std::string CReggianoCheese::ToString()
{
	std::string strName("This is CReggianoCheese");
	return strName;
}
