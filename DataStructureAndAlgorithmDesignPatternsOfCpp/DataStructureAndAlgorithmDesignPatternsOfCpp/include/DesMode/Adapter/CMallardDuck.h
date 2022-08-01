///////////////////////////////////////////////////////////
//  MallardDuck.h
//  Implementation of the Class MallardDuck
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _MALLARD_DUCK_H_
#define _MALLARD_DUCK_H_

#include "ImpDuck.h"
#include <string>


class CMallardDuck : public ImpDuck
{
public:
	virtual ~CMallardDuck();
	static CMallardDuck* GetInstance();

	CMallardDuck(const CMallardDuck&) = delete;
	CMallardDuck& operator=(const CMallardDuck&) = delete;

	std::string Fly();
	std::string Quack();
private:
	CMallardDuck();

};
#endif // !defined(EA_66DD3364_D2FD_41b6_B898_934C9962DC19__INCLUDED_)
