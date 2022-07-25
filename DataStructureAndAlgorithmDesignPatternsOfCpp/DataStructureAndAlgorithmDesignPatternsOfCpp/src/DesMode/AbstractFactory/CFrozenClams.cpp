///////////////////////////////////////////////////////////
//  CFrozenClams.cpp
//  Implementation of the Class CFrozenClams
//  Created on:      18-7ÔÂ-2022 19:09:29
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CFrozenClams.h"



CFrozenClams* CFrozenClams::GetInstance()
{
	static CFrozenClams    g_Instance;
	return &g_Instance;

}

CFrozenClams::CFrozenClams(){

}



CFrozenClams::~CFrozenClams(){

}


std::string CFrozenClams::ToString()
{
	std::string strName("This is CFrozenClams");
	return  strName;
}