///////////////////////////////////////////////////////////
//  Mocha.cpp
//  Implementation of the Class Mocha
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/Mocha.h"



Mocha* Mocha::Getinstance(CBeverage* pBeverage)
{
	static Mocha g_Instance(pBeverage);
	return &g_Instance;
}



Mocha::Mocha:m_pBeverage(nullptr) {

}



Mocha::~Mocha() {

}







Mocha::Mocha(Beverage* beverage) {

}


double Mocha::Cost() {

	return 0;
}


string Mocha::GetDescription() {

	return  NULL;
}


double Mocha::GetSize(BeverageSize size) {

	return 0;
}