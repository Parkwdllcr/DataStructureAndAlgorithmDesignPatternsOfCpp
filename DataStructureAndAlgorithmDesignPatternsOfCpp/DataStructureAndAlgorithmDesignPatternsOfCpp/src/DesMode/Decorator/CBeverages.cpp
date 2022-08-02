///////////////////////////////////////////////////////////
//  Beverage.cpp
//  Implementation of the Class Beverage
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/CBeverages.h"
#include <iostream>


CBeverage::CBeverage():m_dbConstResult(0.0){

}


CBeverage::~CBeverage() {

}

std::string CBeverage::GetDescription() {

	std::string   strName("Unknown Beverage");
	return  strName;
}


bool CBeverage::GetSize(double& dbConstResult)
{
	try
	{
		m_dbConstResult = dbConstResult;
		return true;
	}
	catch (...)
	{
		std::cout << "CBeverage::SetSize UnKnow Error!" << std::endl;
		return false;
	}
}


bool CBeverage::SetSize(const double dbConstResult)
{
	try
	{
		m_dbConstResult = dbConstResult;
		return true;
	}
	catch (...)
	{
		std::cout << "CBeverage::SetSize UnKnow Error!" << std::endl;
		return false;
	}
}


