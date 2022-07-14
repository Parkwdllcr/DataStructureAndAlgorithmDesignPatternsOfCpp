///////////////////////////////////////////////////////////
//  CStatisticsDisplay.cpp
//  Implementation of the Class CStatisticsDisplay
//  Created on:      14-7ÔÂ-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CStatisticsDisplay.h"
#include "ImpSubject.h"
#include <iostream>

CStatisticsDisplay::CStatisticsDisplay():m_pSubject(),m_fHumdity(0)
{

}

CStatisticsDisplay::CStatisticsDisplay(ImpSubject* pSubject):m_pSubject(pSubject),m_fHumdity(0)
{
	pSubject->RegisterObserver(this);
}

CStatisticsDisplay::~CStatisticsDisplay()
{

}

void CStatisticsDisplay::DisPlay()
{
	std::cout << "CStatisticsDisplay m_fHumdity = " << m_fHumdity << std::endl;
}


void CStatisticsDisplay::Updata(strucUpdataValue stuUpdata)
{
	m_fHumdity = stuUpdata.fHumidity;
}