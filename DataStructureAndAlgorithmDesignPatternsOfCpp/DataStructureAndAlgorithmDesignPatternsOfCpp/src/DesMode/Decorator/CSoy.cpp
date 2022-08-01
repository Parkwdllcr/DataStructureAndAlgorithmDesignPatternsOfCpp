///////////////////////////////////////////////////////////
//  Soy.cpp
//  Implementation of the Class Soy
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/CSoy.h"


CSoy* CSoy::GetInstance(CBeverage* pBeverage)
{
	static CSoy g_instance(pBeverage);
	return &g_instance;
}


CSoy::CSoy() :m_pBeverage(nullptr)
{

}

CSoy::~CSoy() {

}


CSoy::CSoy(CBeverage* pBbeverage) :m_pBeverage(pBbeverage)
{

}


double CSoy::Cost() {
	double dbResult = m_pBeverage->Cost();
	return (dbResult+ 0.98);
}


std::string CSoy::GetDescription() {
	std::string strName("CSoy::GetDescription()");
	strName.append(m_pBeverage->GetDescription());
	return  strName;
}