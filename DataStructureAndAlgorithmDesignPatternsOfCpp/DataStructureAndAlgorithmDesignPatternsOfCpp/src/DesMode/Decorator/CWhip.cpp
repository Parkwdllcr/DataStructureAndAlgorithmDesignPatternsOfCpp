///////////////////////////////////////////////////////////
//  Whip.cpp
//  Implementation of the Class Whip
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/CWhip.h"



CWhip* CWhip::GetInstance(CBeverage* pBeverage)
{
	static  CWhip  g_instance(pBeverage);
	return &g_instance;
}

CWhip::CWhip(CBeverage* pBeverage) {

}

CWhip::CWhip() {

}



CWhip::~CWhip() {

}

double CWhip::Cost() {

	return 0;
}


std::string CWhip::GetDescription() {
	std::string   strName("lcr");
	return  strName;
}