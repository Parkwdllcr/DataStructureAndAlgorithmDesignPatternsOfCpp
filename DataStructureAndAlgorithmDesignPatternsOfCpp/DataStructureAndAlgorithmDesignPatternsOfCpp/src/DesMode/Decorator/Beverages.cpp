///////////////////////////////////////////////////////////
//  Beverage.cpp
//  Implementation of the Class Beverage
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Decorator/Beverages.h"



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


enumBeverageSize CBeverage::Size() {

	return  TALL;
}


