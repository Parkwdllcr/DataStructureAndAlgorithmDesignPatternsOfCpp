///////////////////////////////////////////////////////////
//  DuckAdapter.cpp
//  Implementation of the Class DuckAdapter
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Adapter/CDuckAdapter.h"






CDuckAdapter* CDuckAdapter::GetInstance()
{
	static CDuckAdapter   g_Instance;
	return &g_Instance;
}

CDuckAdapter::~CDuckAdapter() {

}



CDuckAdapter::CDuckAdapter() {

}

CDuckAdapter::CDuckAdapter(ImpDuck *pDuck)
{

}


std::string CDuckAdapter::Fly() 
{
	std::string   strMyNane("chongrui.lu");
	return  strMyNane;
}


std::string CDuckAdapter::Gobble() {

	std::string   strMyNane("chongrui.lu");
	return  strMyNane;
}