///////////////////////////////////////////////////////////
//  CForecastDisplay.cpp
//  Implementation of the Class CForecastDisplay
//  Created on:      14-7ÔÂ-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "DesMode/Observer/CForecastDisplay.h"
#include "DesMode/Observer/ImpSubject.h"
#include <iostream>

CForecastDisplay::CForecastDisplay():m_pForecastDisplay(),m_fTemperature(0){

}


CForecastDisplay::CForecastDisplay(ImpSubject* pImpSuject):m_pForecastDisplay(pImpSuject),m_fTemperature(0)
{
	pImpSuject->RegisterObserver(this);
}

CForecastDisplay::~CForecastDisplay(){

}

void CForecastDisplay::DisPlay()
{
	std::cout << "CForecastDisplay m_fTemperature  =  " << m_fTemperature<< std::endl;
}


void CForecastDisplay::Updata(strucUpdataValue stuUpdata)
{
	m_fTemperature = stuUpdata.fTemperature;
}