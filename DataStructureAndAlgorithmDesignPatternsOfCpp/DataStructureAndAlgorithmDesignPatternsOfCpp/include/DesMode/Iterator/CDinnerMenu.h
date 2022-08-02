///////////////////////////////////////////////////////////
//  DinnerMenu.h
//  Implementation of the Class DinnerMenu
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _DINNER_MENU_H_
#define _DINNER_MENU_H_

#include "CMenuItem.h"
#include "ImpIterator.h"
#include "ImpMenu.h"

/**
 * Summary description for DinnerMenu.
 */
class CDinnerMenu : public ImpMenu
{

public:
	virtual ~CDinnerMenu();

	CDinnerMenu();
	void AddItem(string name, string description, bool isVegetarian, double price);
	ImpIterator CreateIterator();

private:
	static int MAX_ITEMS;
	CMenuItem menuItems[];
	int numberOfItems;

};
#endif // !defined(EA_DAB455F8_23F7_46dd_BA45_C8B5CDD61ECC__INCLUDED_)
