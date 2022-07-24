///////////////////////////////////////////////////////////
//  CFreshClams.cpp
//  Implementation of the Class CFreshClams
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CFreshClams.h"




CFreshClams* CFreshClams::GetInstance()
{
	static CFreshClams g_Instance;
	return &g_Instance;
}

CFreshClams::CFreshClams() {

}


CFreshClams::~CFreshClams(){

}

std::string CFreshClams::ToString()
{
	std::string strName("This is CFreshClams");
	return  strName;
}