///////////////////////////////////////////////////////////
//  PancakeHouseMenu.h
//  Implementation of the Class PancakeHouseMenu
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_D1E83FDF_E6EB_45d8_A7EF_06014E7330A9__INCLUDED_)
#define EA_D1E83FDF_E6EB_45d8_A7EF_06014E7330A9__INCLUDED_

#include "Iterator.h"
#include "Menu.h"
#include <string>
using namespace std;

/**
 * Summary description for PancakeHouseMenu.
 */
class PancakeHouseMenu : public Menu
{

public:
	virtual ~PancakeHouseMenu();

	PancakeHouseMenu();
	void AddItem(string name, string description, bool isVegetarian, double price);
	Iterator CreateIterator();

private:
	ArrayList menuItems;

};
#endif // !defined(EA_D1E83FDF_E6EB_45d8_A7EF_06014E7330A9__INCLUDED_)
