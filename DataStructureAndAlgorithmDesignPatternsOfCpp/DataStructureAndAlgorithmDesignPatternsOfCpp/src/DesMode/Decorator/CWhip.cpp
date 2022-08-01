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

CWhip::CWhip(CBeverage* pBeverage):m_pBeverage(pBeverage) {

}

CWhip::CWhip():m_pBeverage(nullptr) 
{

}

CWhip::~CWhip() {

}

double CWhip::Cost() {
	double dbResult = m_pBeverage->Cost();
	return (dbResult+2.45);
}


std::string CWhip::GetDescription() {
	std::string   strName("CWhip::GetDescription");
	strName.append(m_pBeverage->GetDescription());
	return  strName;
}