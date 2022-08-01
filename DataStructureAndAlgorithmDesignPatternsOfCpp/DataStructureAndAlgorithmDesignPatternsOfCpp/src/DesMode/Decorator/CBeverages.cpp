///////////////////////////////////////////////////////////
//  Beverage.cpp
//  Implementation of the Class Beverage
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/CBeverages.h"
#include <iostream>


CBeverage::CBeverage():m_enumSize(TALL){

}


CBeverage::~CBeverage() {

}



double CBeverage::Cost() {

	return 0;
}


std::string CBeverage::GetDescription() {

	std::string   strName("lcr");
	return  strName;
}


bool CBeverage::GetSize(enumBeverageSize enumBerSize)
{
	try
	{
		enumBerSize = m_enumSize;
		return true;
	}
	catch (...)
	{
		std::cout << "CBeverage::GetSize UnKnow Error!" << std::endl;
		return false;
	}

}

bool CBeverage::SetSize(const enumBeverageSize enumBerSize)
{
	try
	{
		 m_enumSize = enumBerSize ;
		return true;
	}
	catch (...)
	{
		std::cout << "CBeverage::SetSize UnKnow Error!" << std::endl;
		return false;
	}
}



