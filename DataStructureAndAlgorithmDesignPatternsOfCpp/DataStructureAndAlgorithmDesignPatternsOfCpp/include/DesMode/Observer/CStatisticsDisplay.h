///////////////////////////////////////////////////////////
//  CStatisticsDisplay.h
//  Implementation of the Class CStatisticsDisplay
//  Created on:      14-7ÔÂ-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////

#ifndef _THIRD_STATISTICS_DISPLAY_H_
#define _THIRD_STATISTICS_DISPLAY_H_

#include "ImpObserver.h"
#include <memory>

class ImpSubject;
class CStatisticsDisplay : public ImpObserver
{

public:
	CStatisticsDisplay();
	CStatisticsDisplay(ImpSubject* pSubject);
	virtual ~CStatisticsDisplay();

	virtual void DisPlay();
	virtual void Updata(strucUpdataValue stuUpdata);
private:
	ImpSubject*                     m_pSubject;
	float                           m_fHumdity;

};
#endif // !defined(EA_3DFFDF7A_765D_4260_8A7C_C25E1C8EFAE6__INCLUDED_)
