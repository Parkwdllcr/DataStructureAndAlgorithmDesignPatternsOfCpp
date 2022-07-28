///////////////////////////////////////////////////////////
//  SteamedMilk.cpp
//  Implementation of the Class SteamedMilk
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/SteamedMilk.h"



SteamedMilk* SteamedMilk::GetInstance(CBeverage* pBeverage)
{
	static SteamedMilk g_instance(pBeverage);
	return &g_instance;
}

SteamedMilk::SteamedMilk(CBeverage *pBeverage) {

}

SteamedMilk::SteamedMilk() {

}



SteamedMilk::~SteamedMilk() {

}

double SteamedMilk::Cost() {

	return 0;
}


std::string SteamedMilk::GetDescription() {
	std::string strName("lku");
	return  strName;
}