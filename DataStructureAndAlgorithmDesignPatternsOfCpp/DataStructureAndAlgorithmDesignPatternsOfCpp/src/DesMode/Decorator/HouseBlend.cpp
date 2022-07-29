///////////////////////////////////////////////////////////
//  HouseBlend.cpp
//  Implementation of the Class HouseBlend
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/HouseBlend.h"


CHouseBlend* CHouseBlend::GetInstance()
{
	static  CHouseBlend g_instance;
	return &g_instance;
}

CHouseBlend::~CHouseBlend() {

}

CHouseBlend::CHouseBlend() {

}


double CHouseBlend::Cost() {

	return 0;
}


std::string CHouseBlend::GetDescription() {
	std::string  strName("lct");
	return  strName;
}