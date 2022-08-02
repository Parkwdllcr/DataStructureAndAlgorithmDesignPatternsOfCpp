///////////////////////////////////////////////////////////
//  CafeMenu.h
//  Implementation of the Class CafeMenu
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _CAFE_MENU_H_
#define  _CAFE_MENU_H_

#include "ImpIterator.h"
#include "ImpMenu.h"
#include <string>
using namespace std;

/**
 * Summary description for CafeMenu.
 */
class CCafeMenu : public ImpMenu
{

public:
	virtual ~CCafeMenu();

	CCafeMenu();
	void AddItem(string name, string description, bool isVegetarian, double price, int index);
	ImpIterator CreateIterator();

private:
	Hashtable menuItems;

};
#endif // !defined(EA_F32052D4_E391_4563_A211_A494E0801E50__INCLUDED_)
