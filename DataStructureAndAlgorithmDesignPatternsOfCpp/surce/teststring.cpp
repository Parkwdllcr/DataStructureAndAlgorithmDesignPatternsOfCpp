// teststring.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "CWeatherData.h"
#include "CCurrentConditionDisplay.h"
#include "CForecastDisplay.h"
#include "CStatisticsDisplay.h"
#include "CThirdPartyDisplay.h"
#include <iostream>

int main()
{
   try{

	    CWeatherData* pWeatherData = new CWeatherData;
		ImpSubject* pSubject = static_cast<ImpSubject*>(pWeatherData);
		ImpObserver* pObserver  = new CCurrentConditionDisplay(pSubject);
		pObserver->DisPlay();
		ImpObserver* pTemObserver = new CForecastDisplay(pSubject);
		pTemObserver->DisPlay();
		ImpObserver* pHumdity = new CStatisticsDisplay(pSubject);
		pHumdity->DisPlay();
		ImpObserver* pPress = new CThirdPartyDisplay(pSubject);
		pPress->DisPlay();

		pWeatherData->SetMeasurements(2, 4, 6);

		pObserver->DisPlay();
		pTemObserver->DisPlay();
		pHumdity->DisPlay();
		pPress->DisPlay();
	


		delete pObserver;
		pObserver = nullptr;

		delete pPress;
		pPress = nullptr;

		delete pTemObserver;
		pTemObserver = nullptr;

		delete pHumdity;
		pHumdity = nullptr;

		delete pSubject;
		pSubject = nullptr;
	
		return 1;

	   }
	
	catch (...) {
		std::cout << "Unknow Error" << std::endl;
		return 0;
	}
}

