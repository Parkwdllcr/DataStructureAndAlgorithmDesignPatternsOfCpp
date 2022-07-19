///////////////////////////////////////////////////////////
//  CPizzaStore.cpp
//  Implementation of the Class CPizzaStore
//  Created on:      18-7ÔÂ-2022 19:09:30
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#include "CPizzaStore.h"
#include <iostream>


CPizzaStore::CPizzaStore()
{

}
CPizzaStore::~CPizzaStore(){

}


CPizza* CPizzaStore::OrderPizza(enPizzaStype enStype)
{
	CPizza* pPizza = CreatePizza(enStype);
	std::string strName = pPizza->Prepare();
	strName.append(pPizza->Bake());
	strName.append(pPizza->Cut());
	strName.append(pPizza->Box());
	std::cout << strName << std::endl;
	return  pPizza;
}