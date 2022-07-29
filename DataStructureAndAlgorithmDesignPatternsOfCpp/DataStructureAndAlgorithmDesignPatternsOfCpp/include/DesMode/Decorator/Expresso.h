///////////////////////////////////////////////////////////
//  Expresso.h
//  Implementation of the Class Expresso
//  Created on:      26-7ÔÂ-2022 21:56:43
//  Original author: LEGION
///////////////////////////////////////////////////////////

#ifndef _EXPRESSO_H_
#define _EXPRESSO_H_

#include "Beverages.h"


class CExpresso : public CBeverage
{

public:
	virtual ~CExpresso();
	static CExpresso* GetInstance();
	double Cost() override;
	std::string GetDescription() override;

private:
	CExpresso();
	double GetSize(enumBeverageSize size);

};
#endif // !defined(EA_1AC5D13C_B64C_4d44_ADEF_F6A6F2466370__INCLUDED_)
