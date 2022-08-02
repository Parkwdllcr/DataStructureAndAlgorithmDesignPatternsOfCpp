// StudyDesMode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "CPrimerPlus/CPrimerPlus.h"
#include "Public/CReadAndWrite.h"
#include "DataStructuresAndAlgorithms/DataTypeAlgorithms/CLinkList.h"
#include "DataStructuresAndAlgorithms/DataTypeAlgorithms/CArrayList.h"
#include "DesMode/Observer/CWeatherData.h"
#include "DesMode/Observer/CCurrentConditionDisplay.h"
#include "DesMode/Observer/CForecastDisplay.h"
#include "DesMode/Observer/CStatisticsDisplay.h"
#include "DesMode/Observer/CThirdPartyDisplay.h"
#include "DesMode/AbstractFactory/CNYPizzaStore.h"
#include "DesMode/AbstractFactory/CChicagoPizzaStore.h"
#include "DesMode/Adapter/CDuckAdapter.h"
#include "DesMode/Adapter/CMallardDuck.h"
#include "DesMode/Adapter/CTurkeyAdapter.h"
#include "DesMode/Decorator/CDarkRoast.h"
#include "DesMode/Decorator/CExpresso.h"
#include "DesMode/Decorator/CMocha.h"
#include "DesMode/Decorator/CWhip.h"
#include "DesMode/Decorator/CSoy.h"
#include "DesMode/Decorator/CHouseBlend.h"
#include "DesMode/Decorator/CSoy.h"
#include "DesMode/Decorator/CDecaf.h"
#include <iostream>
#include <exception>

void SimpleFactoryMode()
{
	try
	{
		double dbResult;
		std::shared_ptr<CStudyCPrimerPlus> pStudyPrimerPlus(new CStudyCPrimerPlus);
		COperation* pOperation = pStudyPrimerPlus->CreateOperation(ADDITION);
		if (true != pOperation->GetResult(dbResult))
		{
			std::cout << "COperation Get Result Failed!" << std::endl;
		}
		std::cout << "Get Result Value  = " << dbResult << std::endl;
		pOperation->SetNumberA(2.1);
		pOperation->SetNumberB(4.2);
		pOperation->GetResult(dbResult);
		std::cout << "after Get Result Value  = " << dbResult << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	
}

void AbstractFactoryMode()
{
	CPizzaStore* pPizzaStore = CChicagoPizzaStore::GetInstance();
	CPizza* pPizza = pPizzaStore->OrderPizza(ClamPizza);

	CPizzaStore* pNYPizzaStore = CNYPizzaStore::GetInstance();
	CPizza* pNYPizza = pNYPizzaStore->OrderPizza(CheesePizza);
	
}

void StrategyMode()
{
	try {
		double dbResult(0.3);
		std::shared_ptr<CStudyCPrimerPlus> pStudy(new CStudyCPrimerPlus(MULTIPLICATION));
		if (true != pStudy->GetResult(dbResult))
		{
			std::cout << "CStudyCPrimerPlus Get Result Failed!" << std::endl;
		}
		std::cout << "Get Result Value  = " << dbResult << std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

void ObserverMode()
{
	//尽量使用智能指针，不然容易出现内存泄漏
	try
	{
		CWeatherData* pWeatherData = new CWeatherData;
		ImpSubject* pSubject = static_cast<ImpSubject*>(pWeatherData);

		//每new一个Observer，在构造函数里面都被Subject注册了
		ImpObserver* pObserver = new CCurrentConditionDisplay(pSubject);
		pObserver->DisPlay();
		ImpObserver* pTemObserver = new CForecastDisplay(pSubject);
		pTemObserver->DisPlay();
		ImpObserver* pHumdity = new CStatisticsDisplay(pSubject);
		pHumdity->DisPlay();
		ImpObserver* pPress = new CThirdPartyDisplay(pSubject);
		pPress->DisPlay();

		//Subject告诉Observer们的变化
		pWeatherData->SetMeasurements(2, 4, 6);

		pObserver->DisPlay();
		pTemObserver->DisPlay();
		pHumdity->DisPlay();
		pPress->DisPlay();


		if (nullptr != pObserver)
		{
			delete pObserver;
			pObserver = nullptr;
		}

		if (nullptr != pPress)
		{
			delete pPress;
			pPress = nullptr;
		}

		if (nullptr != pTemObserver)
		{
			delete pTemObserver;
			pTemObserver = nullptr;
		}
	
		if (nullptr != pHumdity)
		{
			delete pHumdity;
			pHumdity = nullptr;
		}
	
		if (nullptr != pSubject)
		{
			delete pSubject;
			pSubject = nullptr;
		}

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;

	}
	

}

void ReadXMl()
{
	CReadAndWrite* pReadxml = CReadAndWrite::GetInstance();
	boost::property_tree::ptree pt;
	pReadxml->ReadXml(pt);
}

void AdapterMode()
{
	//客户需要火鸡（Turkey）接口，Fly和Gobble，但是只有鸭子实例，那么就这样去适配
	ImpDuck* pDuck = CMallardDuck::GetInstance();
	CDuckAdapter* pDuckAdapter = CDuckAdapter::GetInstance(pDuck);
	std::string strTestFlyResult = pDuckAdapter->Fly();
	std::cout << strTestFlyResult << std::endl;
	std::string strTestGobbleResult = pDuckAdapter->Gobble();
	std::cout << strTestGobbleResult << std::endl;

}

//写错了

CBeverage* GetBeverge(uint32_t uiCase)
{
	CBeverage* pBerver = nullptr;
	switch (uiCase)
	{
	case 0:
		pBerver = CExpresso::GetInstance();
	case 1:
		pBerver = CDarkRoast::GetInstance();
	case 2:
		pBerver = CHouseBlend::GetInstance();
	case 3:
		pBerver = CDecaf::GetInstance();
	default:
		break;
	}
	return pBerver;
}
void DecoratorMode()
{

	CBeverage* pBerver = GetBeverge(0);
	std::string strDescription = pBerver->GetDescription();
	double dbResuit = pBerver->Cost();
	std::cout << "CExpresso::GetInstance strDescription = "<<strDescription << std::endl;
	std::cout << "CExpresso::GetInstance dbResuit = " << dbResuit << std::endl;

	CBeverage* pBerverDarkRost = GetBeverge(1);
	pBerverDarkRost = CMocha::GetInstance(pBerverDarkRost);
	pBerverDarkRost = CMocha::GetInstance(pBerverDarkRost);
	pBerverDarkRost = CWhip::GetInstance(pBerverDarkRost);
	strDescription = pBerverDarkRost->GetDescription();
    dbResuit = pBerverDarkRost->Cost();
	std::cout << "CDarkRoast::GetInstance strDescription = " << strDescription << std::endl;
	std::cout << "CDarkRoast::GetInstance dbResuit = " << dbResuit << std::endl;

	CBeverage* pBerverHouseBlend = GetBeverge(2);
	pBerverHouseBlend = CSoy::GetInstance(pBerverHouseBlend);
	//pBerverHouseBlend = CSoy::GetInstance(pBerverHouseBlend);
	pBerverHouseBlend = CMocha::GetInstance(pBerverHouseBlend);
	//pBerverHouseBlend = CWhip::GetInstance(pBerverHouseBlend);

	std::string strDescription2 = pBerverHouseBlend->GetDescription();
	double dbResuit2 = pBerverHouseBlend->Cost();
	std::cout << "CHouseBlend::GetInstance strDescription = " << strDescription2 << std::endl;
	std::cout << "CHouseBlend::GetInstance dbResuit = " << dbResuit2 << std::endl;

}
int main()
{
	try
	{
		//简单工厂模式的客户端
		//SimpleFactoryMode();

		//策略模式的客户端
		//StrategyMode();

		//观察者模式客户端
		//观察者模式的核心思想就是，Observer可以订阅或者不订阅主题（在new观察者的时候就可以在构造函数里面去订阅），主题将状态告诉所有的观察者NotifyObserver。
		//ObserverMode();

		//抽象工厂模式客户端
		//AbstractFactoryMode();

		//适配器模式客户端
		//AdapterMode();

		//装饰模式客户端
		DecoratorMode();

		//读xml文件
		//ReadXMl();



		return 1;
	}
	catch (std::exception& e)
	{
		std::cout << "Leave WriteLoadwareFileInfo with exception: " << e.what() << std::endl;
		return 0;
	}
	catch (...)
	{
		std::cout << "Leave WriteLoadwareFileInfo with exception." << std::endl;
		return 0;
	}

}


