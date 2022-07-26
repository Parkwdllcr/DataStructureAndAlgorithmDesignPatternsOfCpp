///////////////////////////////////////////////////////////
//  MenuItem.h
//  Implementation of the Class MenuItem
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_6FC5B8C7_3FA1_4856_A30A_7A5E7270F874__INCLUDED_)
#define EA_6FC5B8C7_3FA1_4856_A30A_7A5E7270F874__INCLUDED_

/**
 * Summary description for Class1.
 */
#include <string>
using namespace std;


class MenuItem
{

public:
	MenuItem();
	virtual ~MenuItem();

	MenuItem(string name, string description, bool isVegetarian, double price);
	string Description();
	bool IsVegetarian();
	string Name();
	double Price();

private:
	string description;
	bool isVegetarian;
	string name;
	double price;

};
#endif // !defined(EA_6FC5B8C7_3FA1_4856_A30A_7A5E7270F874__INCLUDED_)
