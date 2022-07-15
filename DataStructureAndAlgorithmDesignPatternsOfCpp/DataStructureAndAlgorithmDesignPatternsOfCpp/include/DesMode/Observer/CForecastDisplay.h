///////////////////////////////////////////////////////////
//  CForecastDisplay.h
//  Implementation of the Class CForecastDisplay
//  Created on:      14-7ÔÂ-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////

#ifndef _FORECAST_DISPLAY_H_
#define _FORECAST_DISPLAY_H_

#include "ImpObserver.h"

class ImpSubject;
class CForecastDisplay : public ImpObserver
{

public:
	CForecastDisplay();
	CForecastDisplay(ImpSubject* pImpSuject);
	virtual ~CForecastDisplay();

	virtual void DisPlay();
	virtual void Updata(strucUpdataValue stuUpdata);


private:
	float                          m_fTemperature;
	ImpSubject*                    m_pForecastDisplay;

};
#endif // !defined(EA_86D88041_1CEA_44b0_BB02_0449DD0751CF__INCLUDED_)
