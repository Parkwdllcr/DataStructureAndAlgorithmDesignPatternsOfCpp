///////////////////////////////////////////////////////////
//  CPizza.cpp
//  Implementation of the Class CPizza
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "DesMode/AbstractFactory/CPizza.h"

CPizza::CPizza():m_pCheese(nullptr),m_pClam(nullptr),m_pDough(nullptr),m_strName("chongrui")
{

}


CPizza::~CPizza(){

}



bool CPizza::GetName(std::string & strName)
{
	strName = m_strName;
	return true;
}

bool CPizza::SetName(std::string strName)
{
	m_strName = strName;
	return true;
}

std::string CPizza::Bake()
{
	std::string strBake("Bake for 25 minutes at 350 \n");
	return  strBake;
}


std::string CPizza::Cut() {

	std::string strCut("Cutting the pizza into diagonal slices \n");
	return  strCut;
}

std::string CPizza::Box() {

	std::string strBox("Place pizza in official PizzaStore box \n");
	return  strBox;
}


