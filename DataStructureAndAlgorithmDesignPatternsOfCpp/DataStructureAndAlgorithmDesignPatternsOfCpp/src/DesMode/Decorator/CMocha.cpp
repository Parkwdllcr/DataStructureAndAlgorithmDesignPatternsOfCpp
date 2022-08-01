///////////////////////////////////////////////////////////
//  Mocha.cpp
//  Implementation of the Class Mocha
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/CMocha.h"



CMocha* CMocha::Getinstance(CBeverage* pBeverage)
{
	static CMocha g_Instance(pBeverage);
	return &g_Instance;
}



CMocha::CMocha():m_pBeverage(nullptr) {

}



CMocha::~CMocha() {

}



CMocha::CMocha(CBeverage* pBeverage):m_pBeverage(pBeverage) {

}


double CMocha::Cost() {

	return 0;
}


std::string CMocha::GetDescription()
{
	std::string strMyName("CMocha::GetDescription");
	return strMyName;
}

double CMocha::GetSize(enumBeverageSize size)
{
	return 0;
}
