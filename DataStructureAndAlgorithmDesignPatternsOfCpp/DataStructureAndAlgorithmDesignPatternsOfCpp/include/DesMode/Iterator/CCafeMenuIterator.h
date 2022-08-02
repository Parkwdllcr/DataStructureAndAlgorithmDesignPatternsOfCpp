///////////////////////////////////////////////////////////
//  CafeMenuIterator.h
//  Implementation of the Class CafeMenuIterator
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _CAFE_MENU_ITERATOR_H_
#define _CAFE_MENU_ITERATOR_H_

#include "ImpIterator.h"

/**
 * Summary description for CafeMenuIterator.
 */
class CCafeMenuIterator : public ImpIterator
{

public:
	CCafeMenuIterator();
	virtual ~CCafeMenuIterator();

	CCafeMenuIterator(Hashtable menuItems);
	bool HasNext();
	object Next();

private:
	Hashtable menuItems;
	int position;

};
#endif // !defined(EA_DE1E76BD_BDDF_4330_BF1E_A615AA1FC03F__INCLUDED_)
