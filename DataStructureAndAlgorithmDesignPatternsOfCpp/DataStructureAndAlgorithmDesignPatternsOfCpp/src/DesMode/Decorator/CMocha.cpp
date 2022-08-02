///////////////////////////////////////////////////////////
//  Mocha.cpp
//  Implementation of the Class Mocha
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/CMocha.h"



CMocha* CMocha::GetInstance(CBeverage* pBeverage)
{
	static CMocha g_Instance(pBeverage);
	return &g_Instance;
}



CMocha::~CMocha() {

}



CMocha::CMocha(CBeverage* pBeverage):CCondimentDecorator(pBeverage), m_pBeverage(pBeverage)
{

}


double CMocha::Cost() {
	double dbResult = m_pBeverage->Cost();
	dbResult = dbResult + 1.7;
	return dbResult;
}


std::string CMocha::GetDescription()
{
	std::string strMyName("CMocha::GetDescription");
	strMyName.append(m_pBeverage->GetDescription());
	return strMyName;
}

