///////////////////////////////////////////////////////////
//  CThirdPartyDisplay.cpp
//  Implementation of the Class CThirdPartyDisplay
//  Created on:      14-7ÔÂ-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CThirdPartyDisplay.h"
#include "ImpSubject.h"
#include <iostream>

CThirdPartyDisplay::CThirdPartyDisplay():m_pSubject(),m_fPress(0)
{

}

CThirdPartyDisplay::CThirdPartyDisplay(ImpSubject* pSubject):m_pSubject(pSubject),m_fPress(0)
{
	pSubject->RegisterObserver(this);
}

CThirdPartyDisplay::~CThirdPartyDisplay(){

}

void CThirdPartyDisplay::DisPlay()
{
	std::cout << "CThirdPartyDisplay m_fPress  =  " << m_fPress << std::endl;
}


void CThirdPartyDisplay::Updata(strucUpdataValue stuUpdata)
{
	m_fPress = stuUpdata.fPressure;
}