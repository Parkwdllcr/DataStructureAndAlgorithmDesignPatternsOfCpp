///////////////////////////////////////////////////////////
//  CCurrentConditionDisplay.h
//  Implementation of the Class CCurrentConditionDisplay
//  Created on:      14-7ÔÂ-2022 9:37:13
//  Original author: Administrator
///////////////////////////////////////////////////////////

#ifndef _CURRENT_CONDITION_DISPLAY_H_
#define _CURRENT_CONDITION_DISPLAY_H_

#include "ImpObserver.h"
#include <memory>

class ImpSubject;

class CCurrentConditionDisplay : public ImpObserver
{

public:
	CCurrentConditionDisplay();
	virtual ~CCurrentConditionDisplay();
	CCurrentConditionDisplay(ImpSubject* pSubject);

public:
	virtual void DisPlay();
	virtual void Updata(strucUpdataValue stuUpdata);

private:
	float            m_fHumidity;
	float            m_fPressure;
	float            m_fTemperature;
	ImpSubject*      m_pImpSubject;

};
#endif // 