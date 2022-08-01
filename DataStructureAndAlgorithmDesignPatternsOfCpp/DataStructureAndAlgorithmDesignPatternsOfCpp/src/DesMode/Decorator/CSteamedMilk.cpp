///////////////////////////////////////////////////////////
//  SteamedMilk.cpp
//  Implementation of the Class SteamedMilk
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/CSteamedMilk.h"



CSteamedMilk* CSteamedMilk::GetInstance(CBeverage* pBeverage)
{
	static CSteamedMilk g_instance(pBeverage);
	return &g_instance;
}

CSteamedMilk::CSteamedMilk(CBeverage *pBeverage) {

}

CSteamedMilk::CSteamedMilk() {

}



CSteamedMilk::~CSteamedMilk() {

}

double CSteamedMilk::Cost() {

	return 0;
}


std::string CSteamedMilk::GetDescription() {
	std::string strName("lku");
	return  strName;
}