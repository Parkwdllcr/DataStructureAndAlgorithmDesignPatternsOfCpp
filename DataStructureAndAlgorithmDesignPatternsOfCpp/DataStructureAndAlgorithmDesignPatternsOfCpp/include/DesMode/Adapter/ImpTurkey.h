///////////////////////////////////////////////////////////
//  Turkey.h
//  Implementation of the Interface Turkey
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_849A98BD_E51A_49d7_949E_43D600E30D68__INCLUDED_)
#define EA_849A98BD_E51A_49d7_949E_43D600E30D68__INCLUDED_

/**
 * Summary description for Turkey.
 */

#include <string>

class ImpTurkey
{

public:
	virtual ~Turkey() {

	}

	virtual std::string Fly() = 0;
	virtual std::string Gobble() = 0;

};
#endif // !defined(EA_849A98BD_E51A_49d7_949E_43D600E30D68__INCLUDED_)
