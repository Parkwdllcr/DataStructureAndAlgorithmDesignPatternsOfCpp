///////////////////////////////////////////////////////////
//  DinnerMenuIterator.h
//  Implementation of the Class DinnerMenuIterator
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_91787517_0E23_4be1_9B89_D9D60F2341F4__INCLUDED_)
#define EA_91787517_0E23_4be1_9B89_D9D60F2341F4__INCLUDED_

#include "MenuItem.h"
#include "Iterator.h"

/**
 * Summary description for DinnerMenuIterator.
 */
class DinnerMenuIterator : public Iterator
{

public:
	DinnerMenuIterator();
	virtual ~DinnerMenuIterator();

	DinnerMenuIterator(MenuItem[] items);
	bool HasNext();
	object Next();

private:
	MenuItem items[];
	int position;

};
#endif // !defined(EA_91787517_0E23_4be1_9B89_D9D60F2341F4__INCLUDED_)
