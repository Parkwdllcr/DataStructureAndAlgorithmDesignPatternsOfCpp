///////////////////////////////////////////////////////////
//  DinnerMenu.h
//  Implementation of the Class DinnerMenu
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_DAB455F8_23F7_46dd_BA45_C8B5CDD61ECC__INCLUDED_)
#define EA_DAB455F8_23F7_46dd_BA45_C8B5CDD61ECC__INCLUDED_

#include "MenuItem.h"
#include "Iterator.h"
#include "Menu.h"

/**
 * Summary description for DinnerMenu.
 */
class DinnerMenu : public Menu
{

public:
	virtual ~DinnerMenu();

	DinnerMenu();
	void AddItem(string name, string description, bool isVegetarian, double price);
	Iterator CreateIterator();

private:
	static int MAX_ITEMS;
	MenuItem menuItems[];
	int numberOfItems;

};
#endif // !defined(EA_DAB455F8_23F7_46dd_BA45_C8B5CDD61ECC__INCLUDED_)
