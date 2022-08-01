///////////////////////////////////////////////////////////
//  TurkeyAdapter.cpp
//  Implementation of the Class TurkeyAdapter
//  Created on:      26-7ÔÂ-2022 10:53:59
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Adapter/CTurkeyAdapter.h"




CTurkeyAdapter* CTurkeyAdapter::GetInstance(ImpTurkey* pTurkey)
{
	static CTurkeyAdapter   g_Instance(pTurkey);
	return &g_Instance;
}

CTurkeyAdapter::CTurkeyAdapter(ImpTurkey* pTurkey):m_pTurkey(pTurkey)
{

}

CTurkeyAdapter::CTurkeyAdapter():m_pTurkey(nullptr)
{

}

CTurkeyAdapter::~CTurkeyAdapter() {

}




std::string CTurkeyAdapter::Fly()
{
	std::string strMyName("CTurkeyAdapter::Quack");
	for (uint32_t i = 0; i != 3; ++i)
	{
		std::string strTemp = m_pTurkey->Fly();
		strMyName.append(strTemp);
	}

	return  strMyName;
}


std::string CTurkeyAdapter::Quack()
{
	std::string strMyName = m_pTurkey->Gobble();
	return  strMyName;
}