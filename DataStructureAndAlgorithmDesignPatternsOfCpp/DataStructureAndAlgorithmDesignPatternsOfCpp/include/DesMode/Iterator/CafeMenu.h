///////////////////////////////////////////////////////////
//  CafeMenu.h
//  Implementation of the Class CafeMenu
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_F32052D4_E391_4563_A211_A494E0801E50__INCLUDED_)
#define EA_F32052D4_E391_4563_A211_A494E0801E50__INCLUDED_

#include "Iterator.h"
#include "Menu.h"
#include <string>
using namespace std;

/**
 * Summary description for CafeMenu.
 */
class CafeMenu : public Menu
{

public:
	virtual ~CafeMenu();

	CafeMenu();
	void AddItem(string name, string description, bool isVegetarian, double price, int index);
	Iterator CreateIterator();

private:
	Hashtable menuItems;

};
#endif // !defined(EA_F32052D4_E391_4563_A211_A494E0801E50__INCLUDED_)
