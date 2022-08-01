///////////////////////////////////////////////////////////
//  MallardDuck.cpp
//  Implementation of the Class MallardDuck
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Adapter/CMallardDuck.h"


CMallardDuck* CMallardDuck::GetInstance()
{
	static CMallardDuck   g_Instance;
	return &g_Instance;
}

CMallardDuck::CMallardDuck() {

}

CMallardDuck::~CMallardDuck() {

}



std::string CMallardDuck::Fly()
{
	std::string strMyName("CMallardDuck:: Fly");
	return  strMyName;
}


std::string CMallardDuck::Quack() {

	std::string strMyName(" CMallardDuck::Quack");
	return  strMyName;
}