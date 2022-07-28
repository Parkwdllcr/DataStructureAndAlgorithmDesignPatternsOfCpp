///////////////////////////////////////////////////////////
//  DuckAdapter.h
//  Implementation of the Class DuckAdapter
//  Created on:      26-7ÔÂ-2022 10:53:58
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_7CA6CC48_EDCE_4ca1_B356_7E1B3CE3EB5B__INCLUDED_)
#define EA_7CA6CC48_EDCE_4ca1_B356_7E1B3CE3EB5B__INCLUDED_

#include "ImpDuck.h"
#include "ImpTurkey.h"
#include <string>


class CDuckAdapter : public ImpTurkey
{

public:

	static CDuckAdapter* GetInstance();
	virtual ~CDuckAdapter();
	CDuckAdapter(const CDuckAdapter&) = delete;
	CDuckAdapter& operator=(const CDuckAdapter&) = delete;

	std::string Fly();
	std::string Gobble();

private:
	ImpDuck*            m_pDuck;

private:
	CDuckAdapter();
	CDuckAdapter(ImpDuck* pDuck);

};
#endif // !defined(EA_7CA6CC48_EDCE_4ca1_B356_7E1B3CE3EB5B__INCLUDED_)
