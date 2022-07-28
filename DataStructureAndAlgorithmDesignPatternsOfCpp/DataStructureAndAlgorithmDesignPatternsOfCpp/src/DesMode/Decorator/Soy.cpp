///////////////////////////////////////////////////////////
//  Soy.cpp
//  Implementation of the Class Soy
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/Soy.h"


Soy* Soy::GetInstance(CBeverage* pBeverage)
{
	static Soy g_instance(pBeverage);
	return &g_instance;
}


Soy::Soy() :m_pBeverage(nullptr)
{

}

Soy::~Soy() {

}


Soy::Soy(CBeverage* pBbeverage) :m_pBeverage(pBbeverage)
{

}


double Soy::Cost() {

	return 0;
}


std::string Soy::GetDescription() {
	std::string strName("ljuy");
	return  strName;
}