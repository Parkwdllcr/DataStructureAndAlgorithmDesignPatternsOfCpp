///////////////////////////////////////////////////////////
//  CCurrentConditionDisplay.cpp
//  Implementation of the Class CCurrentConditionDisplay
//  Created on:      14-7ÔÂ-2022 9:37:13
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CCurrentConditionDisplay.h"
#include "ImpSubject.h"
#include <iostream>

CCurrentConditionDisplay::CCurrentConditionDisplay()
	: m_pImpSubject(), m_fHumidity(0.0), m_fPressure(0.0), m_fTemperature(0.0) {

}



CCurrentConditionDisplay::~CCurrentConditionDisplay()
{
	std::cout << "CCurrentConditionDisplay::~CCurrentConditionDisplay "<< std::endl;
}


CCurrentConditionDisplay::CCurrentConditionDisplay(ImpSubject* pSubject)
	: m_pImpSubject(pSubject),m_fHumidity(0), m_fPressure(0), m_fTemperature(0)
{
	pSubject->RegisterObserver(this);
}


void CCurrentConditionDisplay::DisPlay()
{
	std::cout << " m_fTemperature  = " << m_fTemperature << " m_fHumidity =  " << m_fHumidity << " m_fPressure" << m_fPressure << std::endl;
}


void CCurrentConditionDisplay::Updata(strucUpdataValue stuUpdata)
{
	m_fTemperature = stuUpdata.fTemperature;
	m_fHumidity = stuUpdata.fHumidity;
	m_fPressure = stuUpdata.fPressure;
}


