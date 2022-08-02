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

CSteamedMilk::CSteamedMilk(CBeverage *pBeverage):CCondimentDecorator(pBeverage), m_pBeverage(pBeverage)
{

}

CSteamedMilk::~CSteamedMilk() {

}

double CSteamedMilk::Cost() {
	double dbResult = m_pBeverage->Cost();
	dbResult = dbResult + 1.45;
	return dbResult;
}


std::string CSteamedMilk::GetDescription() {
	std::string strName("CSteamedMilk::GetDescription");
	strName.append(m_pBeverage->GetDescription());
	return  strName;
}