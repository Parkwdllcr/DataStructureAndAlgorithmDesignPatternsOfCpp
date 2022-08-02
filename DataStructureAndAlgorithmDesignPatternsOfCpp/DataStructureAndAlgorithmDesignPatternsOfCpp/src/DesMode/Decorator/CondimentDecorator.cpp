///////////////////////////////////////////////////////////
//  CondimentDecorator.cpp
//  Implementation of the Class CondimentDecorator
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/CondimentDecorator.h"



CCondimentDecorator::CCondimentDecorator(CBeverage* pBerver):m_pBeverage(pBerver)
{

}


CCondimentDecorator::~CCondimentDecorator()
{

}

double CCondimentDecorator::Cost()
{
	return this->m_pBeverage->Cost();
}
