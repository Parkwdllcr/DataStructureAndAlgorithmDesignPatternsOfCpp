///////////////////////////////////////////////////////////
//  WildTurkey.cpp
//  Implementation of the Class WildTurkey
//  Created on:      26-7ÔÂ-2022 10:53:59
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Adapter/CWildTurkey.h"




CWildTurkey* CWildTurkey::GetInstance()
{
	static CWildTurkey  g_Instance;
	return &g_Instance;
}

CWildTurkey::~CWildTurkey() {

}




CWildTurkey::CWildTurkey() {

}


std::string CWildTurkey::Fly() {

	std::string strMyName("chongrui.lu Fly");
	return  strMyName;
}


std::string CWildTurkey::Gobble() {

	std::string strMyName("chongrui.lu Fly");
	return  strMyName;
}