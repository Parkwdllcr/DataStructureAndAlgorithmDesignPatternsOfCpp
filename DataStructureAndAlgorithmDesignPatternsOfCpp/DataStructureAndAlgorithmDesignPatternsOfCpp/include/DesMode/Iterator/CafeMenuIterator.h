///////////////////////////////////////////////////////////
//  CafeMenuIterator.h
//  Implementation of the Class CafeMenuIterator
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_DE1E76BD_BDDF_4330_BF1E_A615AA1FC03F__INCLUDED_)
#define EA_DE1E76BD_BDDF_4330_BF1E_A615AA1FC03F__INCLUDED_

#include "Iterator.h"

/**
 * Summary description for CafeMenuIterator.
 */
class CafeMenuIterator : public Iterator
{

public:
	CafeMenuIterator();
	virtual ~CafeMenuIterator();

	CafeMenuIterator(Hashtable menuItems);
	bool HasNext();
	object Next();

private:
	Hashtable menuItems;
	int position;

};
#endif // !defined(EA_DE1E76BD_BDDF_4330_BF1E_A615AA1FC03F__INCLUDED_)
