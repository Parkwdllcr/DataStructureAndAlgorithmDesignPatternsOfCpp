///////////////////////////////////////////////////////////
//  WildTurkey.h
//  Implementation of the Class WildTurkey
//  Created on:      26-7ÔÂ-2022 10:53:59
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _WILD_TURKEY_H_
#define _WILD_TURKEY_H_

#include "ImpTurkey.h"
#include <string>

/**
 * Summary description for WildTurkey.
 */
class CWildTurkey : public ImpTurkey
{

public:
	virtual ~CWildTurkey();
	static CWildTurkey* GetInstance();
	CWildTurkey(const CWildTurkey&) = delete;
	CWildTurkey& operator=(const CWildTurkey&) = delete;

	std::string Fly();
	std::string Gobble();

private:
	CWildTurkey();

};
#endif