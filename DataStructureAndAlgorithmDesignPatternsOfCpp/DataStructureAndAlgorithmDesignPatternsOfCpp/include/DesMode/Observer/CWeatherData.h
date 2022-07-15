///////////////////////////////////////////////////////////
//  CWeatherData.h
//  Implementation of the Class CWeatherData
//  Created on:      14-7ÔÂ-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////

#ifndef _WEATHER_DATA_H_
#define _WEATHER_DATA_H_

#include "ImpSubject.h"
#include <vector>
#include <memory>


class CWeatherData : public ImpSubject
{

public:
	CWeatherData();
	virtual ~CWeatherData();

	virtual void NotifyObservers();
	virtual void RegisterObserver(ImpObserver* pObserver);
	virtual void RemoveObserver(ImpObserver* pObserver);

	void GetHumidity(float& fHumidity);
	void GetPressure(float& fPressure);
	void GetTemprature(float& fTemprature);
	void MeasurementsChanged();
	void SetMeasurements(const float fTemp, const float fHum, const float fPress);

private:
	strucUpdataValue                                 m_struUpdataValue;
	std::vector<ImpObserver*>                        m_vecpObserver;

};
#endif 