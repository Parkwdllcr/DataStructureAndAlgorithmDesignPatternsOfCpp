///////////////////////////////////////////////////////////
//  CWeatherData.cpp
//  Implementation of the Class CWeatherData
//  Created on:      14-7ÔÂ-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CWeatherData.h"
#include <exception>
#include <iostream>


CWeatherData::CWeatherData()
	: m_struUpdataValue(),m_vecpObserver()
{

}



CWeatherData::~CWeatherData()
{
	std::cout << "CWeatherData" << std::endl;
}


void CWeatherData::GetHumidity(float& fHumidity)
{
	fHumidity = m_struUpdataValue.fHumidity;
}


void CWeatherData::GetPressure(float& fPressure)
{
	fPressure = m_struUpdataValue.fPressure;
}


void CWeatherData::GetTemprature(float& fTemprature)
{
	fTemprature = m_struUpdataValue.fTemperature;
}


void CWeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void CWeatherData::SetMeasurements(const float fTemp, const float fHum, const float fPress)
{
	m_struUpdataValue.fTemperature = fTemp;
	m_struUpdataValue.fHumidity = fHum;
	m_struUpdataValue.fPressure = fPress;
	MeasurementsChanged();
}


void CWeatherData::NotifyObservers()
{
	for (auto iter = m_vecpObserver.begin();iter != m_vecpObserver.end();++iter)
	{
		(*iter)->Updata(m_struUpdataValue);
	}
}


void CWeatherData::RegisterObserver(ImpObserver* pObserver)
{
	try
	{
		m_vecpObserver.push_back(pObserver);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}


void CWeatherData::RemoveObserver(ImpObserver* pObserver)
{
	try
	{
		if (!m_vecpObserver.empty())
		{
			for (auto iter = m_vecpObserver.begin(); iter != m_vecpObserver.end(); ++iter)
			{
				if ((*iter) ==  pObserver)
				{
					m_vecpObserver.erase(iter);
					return;
				}
			}
			
		}
		std::cout << "m_listpObserver empty" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
