///////////////////////////////////////////////////////////
//  CPizza.h
//  Implementation of the Class CPizza
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////
#ifndef _PIZZA_H_
#define _PIZZA_H_

#include "ImpCheese.h"
#include "ImpClam.h"
#include "ImpDough.h"
#include <string>


class CPizza
{

public:
	CPizza();
	virtual ~CPizza();

public:
	virtual std::string Prepare() = 0;

public:
	bool  GetName(std::string& strName);
	bool SetName(std::string strName);
	std::string Bake();
	std::string Box();
	std::string Cut();

protected:
	ImpCheese* m_pCheese;
	ImpClam* m_pClam;
	ImpDough* m_pDough;
	std::string m_strName;

};

#endif



