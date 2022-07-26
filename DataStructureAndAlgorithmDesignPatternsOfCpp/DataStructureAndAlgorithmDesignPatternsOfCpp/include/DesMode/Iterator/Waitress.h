///////////////////////////////////////////////////////////
//  Waitress.h
//  Implementation of the Class Waitress
//  Created on:      26-7ÔÂ-2022 23:38:20
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_FC54ADE5_8DA5_47a2_932A_68D6AAF3A632__INCLUDED_)
#define EA_FC54ADE5_8DA5_47a2_932A_68D6AAF3A632__INCLUDED_

#include "Menu.h"
#include "Iterator.h"
#include <string>
using namespace std;

/**
 * Summary description for Waitress.
 */
class Waitress
{

public:
	Waitress();
	virtual ~Waitress();

	Waitress(Menu* pancakeHouseMenu, Menu* dinnerMenu, Menu* cafeMenu);
	string PrintMenu();
	string PrintMenu(Iterator iterator);

private:
	Menu *cafeMenu;
	Menu *dinnerMenu;
	Menu *pancakeHouseMenu;

};
#endif // !defined(EA_FC54ADE5_8DA5_47a2_932A_68D6AAF3A632__INCLUDED_)
