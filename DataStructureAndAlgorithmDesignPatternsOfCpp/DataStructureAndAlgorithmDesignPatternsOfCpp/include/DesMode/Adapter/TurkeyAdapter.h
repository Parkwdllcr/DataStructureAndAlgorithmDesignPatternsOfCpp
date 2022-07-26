///////////////////////////////////////////////////////////
//  TurkeyAdapter.h
//  Implementation of the Class TurkeyAdapter
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_861C5C07_4034_4fc9_9443_F321669AA7E3__INCLUDED_)
#define EA_861C5C07_4034_4fc9_9443_F321669AA7E3__INCLUDED_

#include "Turkey.h"
#include "Duck.h"

/**
 * Summary description for TurkeyAdapter.
 */
class TurkeyAdapter : public Duck
{

public:
	TurkeyAdapter();
	virtual ~TurkeyAdapter();

	TurkeyAdapter(Turkey turkey);
	std::string Fly();
	std::string Quack();

private:
	Turkey turkey;

};
#endif // !defined(EA_861C5C07_4034_4fc9_9443_F321669AA7E3__INCLUDED_)
