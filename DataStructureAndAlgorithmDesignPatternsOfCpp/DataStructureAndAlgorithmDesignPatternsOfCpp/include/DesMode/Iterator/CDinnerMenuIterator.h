///////////////////////////////////////////////////////////
//  DinnerMenuIterator.h
//  Implementation of the Class DinnerMenuIterator
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////
#ifndef _DINNER_MENU__ITERATOR_H_
#define _DINNER_MENU__ITERATOR_H_

#include "CMenuItem.h"
#include "ImpIterator.h"

/**
 * Summary description for DinnerMenuIterator.
 */
class CDinnerMenuIterator : public ImpIterator
{

public:
	CDinnerMenuIterator();
	virtual ~CDinnerMenuIterator();

	CDinnerMenuIterator(MenuItem[] items);
	bool HasNext();
	object Next();

private:
	CMenuItem items[];
	int position;

};
#endif // !defined(EA_91787517_0E23_4be1_9B89_D9D60F2341F4__INCLUDED_)
