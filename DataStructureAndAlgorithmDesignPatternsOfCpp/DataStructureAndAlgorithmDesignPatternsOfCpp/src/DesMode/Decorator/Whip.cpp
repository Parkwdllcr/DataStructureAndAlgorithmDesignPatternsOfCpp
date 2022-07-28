///////////////////////////////////////////////////////////
//  Whip.cpp
//  Implementation of the Class Whip
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/Whip.h"



Whip* Whip::GetInstance(CBeverage* pBeverage)
{
	static  Whip  g_instance(pBeverage);
	return &g_instance;
}

Whip::Whip(CBeverage* pBeverage) {

}

Whip::Whip() {

}



Whip::~Whip() {

}

double Whip::Cost() {

	return 0;
}


std::string Whip::GetDescription() {
	std::string   strName("lcr");
	return  strName;
}