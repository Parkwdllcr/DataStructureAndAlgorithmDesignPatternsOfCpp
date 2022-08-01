///////////////////////////////////////////////////////////
//  DuckAdapter.cpp
//  Implementation of the Class DuckAdapter
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Adapter/CDuckAdapter.h"


CDuckAdapter* CDuckAdapter::GetInstance(ImpDuck* pDuck)
{
	static CDuckAdapter   g_Instance(pDuck);
	return &g_Instance;
}

CDuckAdapter::~CDuckAdapter() {

}



CDuckAdapter::CDuckAdapter():m_pDuck(nullptr) 
{

}

CDuckAdapter::CDuckAdapter(ImpDuck *pDuck):m_pDuck(pDuck)
{

}


std::string CDuckAdapter::Fly() 
{
	std::string   strMyNane("CDuckAdapter::Fly");
	std::string strTest = m_pDuck->Fly();
	strMyNane.append(strTest);
	return  strMyNane;
}


std::string CDuckAdapter::Gobble() {

	std::string   strMyNane("CDuckAdapter::Gobble()");
	std::string strTest = m_pDuck->Quack();
	strMyNane.append(strTest);
	return  strMyNane;
}