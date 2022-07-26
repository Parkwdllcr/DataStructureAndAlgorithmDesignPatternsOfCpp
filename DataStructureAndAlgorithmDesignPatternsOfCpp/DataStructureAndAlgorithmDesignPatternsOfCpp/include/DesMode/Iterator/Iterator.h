///////////////////////////////////////////////////////////
//  Iterator.h
//  Implementation of the Interface Iterator
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_67560076_83CC_4ec5_B117_E5866BE5AD28__INCLUDED_)
#define EA_67560076_83CC_4ec5_B117_E5866BE5AD28__INCLUDED_

/**
 * Summary description for Iterator.
 */
class Iterator
{

public:
	Iterator() {

	}

	virtual ~Iterator() {

	}

	virtual bool HasNext() =0;
	virtual object Next() =0;

};
#endif // !defined(EA_67560076_83CC_4ec5_B117_E5866BE5AD28__INCLUDED_)
