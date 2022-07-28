///////////////////////////////////////////////////////////
//  TurkeyAdapter.h
//  Implementation of the Class TurkeyAdapter
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _TURKEY_ADAPTER_H_
#define _TURKEY_ADAPTER_H_

#include "ImpTurkey.h"
#include "ImpDuck.h"


class CTurkeyAdapter : public ImpDuck
{

public:
	
	virtual ~CTurkeyAdapter();
	static  CTurkeyAdapter* GetInstance(ImpTurkey *pTurkey);
	CTurkeyAdapter(const CTurkeyAdapter&) = delete;
	CTurkeyAdapter& operator=(const CTurkeyAdapter&) = delete;

	std::string Fly();
	std::string Quack();

private:
	ImpTurkey*                m_pTurkey;
private:
	CTurkeyAdapter();
	CTurkeyAdapter(ImpTurkey* pTurkey);

};
#endif // !defined(EA_861C5C07_4034_4fc9_9443_F321669AA7E3__INCLUDED_)
