// StudyDesMode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DesMode/AbstractFactory/AbstractFactory.h"
#include "DesMode/Adapter/CAdapter.h"
#include "DesMode/Singleton/CSingletion.h"
#include "DesMode/State/CConcreteState.h"
#include "DesMode/Iterator/ConcreteAggregate.h"
#include "DesMode/Observer/CDeanSys.h"
#include "DesMode/Observer/CStudentA.h"
#include "DesMode/Observer/CStudentB.h"
#include "DesMode/SimpleFactory/CFactory.h"
#include "DesMode/FactoryMode/CFactoryofFactoryMode.h"
#include "DesMode/FactoryMode/CFactory_AddofFactoryMode.h"
#include "DesMode/FactoryMode/CFactory_MulofFactoryMode.h"
#include "CPrimerPlus/3thDataProcessing/3thDataProcessing.h"
#include "MulThreadAndCallBack/CCallBackReceiver.h"
#include "DataStructuresAndAlgorithmsAddSTL/DataTypeAlgorithms/LinkList/CLinkList.h"
#include "DataStructuresAndAlgorithmsAddSTL/DataTypeAlgorithms/LinkList/CArrayList.h"
#include "DataStructuresAndAlgorithmsAddSTL/STL/CStudyList/CStudyList.h"
#include "DataStructuresAndAlgorithmsAddSTL/STL/CStudyMap/CStudyMap.h"

int main()
{
	//std::cout << "IAMSingletion" << std::endl;
	//std::cout << "------<<<<<<<<<<<<<-----" << std::endl;
	////单例模式
	////尽管获取了两次，但是只是生成了一个实例
 //   //在实际的使用中直接使用CSingletion::get_instance()
 //   //CSingletion* instance = CSingletion::get_instance();
 //   //CSingletion* instance2 = CSingletion::get_instance();
	////通过测试知道，单例的最后对象销毁是析构函数完成

	//CSingletion::get_instance()->SetSomeValue(10);
	//CSingletion::get_instance()->GetSomeValue(7);

	//	//Simple factory mode
	//std::cout << "\n\n" << std::endl;
	//std::cout << "IAMSimpleFactory" << std::endl;
	//std::cout << "------<<<<<<<<<<<<<-----" << std::endl;
	//CFactory* pFactory = new CFactory();
	//if (pFactory == nullptr)
	//{
	//	std::cout << "pFactory is fall" << std::endl;
	//	return 0;
	//}
	//CProduct* pProduct = pFactory->Creat(PRODUCT_ADD);
	//int	iadd = pProduct->operation(1, 2);
	//pFactory->Destory();


	//pProduct = pFactory->Creat(PRODUCT_MUL);
	//int	imul = pProduct->operation(1, 2);
	//pFactory->Destory();

	//std::cout << "add：" << iadd << std::endl;
	//std::cout << "multiply：" << imul << std::endl;

	//if (pFactory != nullptr)
	//{
	//	delete pFactory;
	//	pFactory = nullptr;
	//}

	//// factory mode
	//std::cout << "\n\n" << std::endl;
	//std::cout << "IAMFactoryMode" << std::endl;
	//std::cout << "------<<<<<<<<<<<<<-----" << std::endl;
	//CFactory_AddofFactoryMode* pFactory_add = new CFactory_AddofFactoryMode();
	//if (pFactory_add == nullptr)
	//{
	//	std::cout << "new pFactory_add is faill!" << std::endl;
	//	return 0;
	//}
	//CProductofFactoryMode* pProductOfFacMode = pFactory_add->Create();
	//int iaddoffacmode = pProductOfFacMode->operation(3, 4);
	//std::cout << "iaddoffacmode：" << iaddoffacmode << std::endl;
	//pFactory_add->Destory();
	//if (pFactory_add != nullptr)
	//{
	//	delete pFactory_add;
	//	pFactory_add = nullptr;
	//}

	//CFactory_MulofFactoryMode* pFactory_Mul = new CFactory_MulofFactoryMode();
	//if (pFactory_Mul == nullptr)
	//{
	//	std::cout << "new pFactory_Mul is faill!" << std::endl;
	//	return 0;
	//}
	//pProductOfFacMode = pFactory_Mul->Create();
	//int imuloffacmode = pProductOfFacMode->operation(3, 4);
	//std::cout << "imuloffacmode：" << imuloffacmode << std::endl;
	//pFactory_Mul->Destory();
	//if (pFactory_Mul != nullptr)
	//{
	//	delete pFactory_Mul;
	//	pFactory_Mul = nullptr;
	//}


	//std::cout << "\n\n" << std::endl;
	//std::cout << "IAMAbstractFactory" << std::endl;
	//std::cout << "------<<<<<<<<<<<<<-----" << std::endl;

	////抽象工厂模式
 //   //生产产品A的第一种实现
	//AbstractFactory* cf1 = new ConcreteFactory1();
	//cf1->CreateProductA();
	////生产产品B的第二种实现
	//AbstractFactory* cf2 = new ConcreteFactory2();
	//cf2->CreateProductB();
	//delete cf1;
	//delete cf2;

	//std::cout << "\n\n" << std::endl;
	//std::cout << "IAMAdapter" << std::endl;
	//std::cout << "------<<<<<<<<<<<<<-----" << std::endl;
	////适配器模式
	//Target* pTarget = new CAdapter();
	//pTarget->Request();
	////对象模式CAdapter1
	////Adaptee* pade = new Adaptee();
	////Target& pTarget1 = new CAdapter1(pade);
	////pTarget1->Request();
	//delete pTarget;


 //   //state模式
	//std::cout << "\n\n" << std::endl;
	//std::cout << "IAMState" << std::endl;
	//std::cout << "------<<<<<<<<<<<<<-----" << std::endl;
	//CState* pState = new CConcreteStateA();
	//CContext* pContext = new CContext(pState);
	//pContext->Request();
	////为什么不将pState删掉呢？
	////delete pState;
	//delete pContext;
	//

	////迭代器模式
	//std::cout << "\n\n" << std::endl;
	//std::cout << "IAMIterator" << std::endl;
	//std::cout << "------<<<<<<<<<<<<<-----" << std::endl;
	//Aggregate* pAggregate = new ConcreteAggregate(4);
	//Iterator* pIterator = new ConcreteIterator(pAggregate);

	//for (; false == pIterator->IsDone(); pIterator->Next())
	//	std::cout << pIterator->CurrentItem() << std::endl;

	////为什么这里又可以删除呢？
	////delete pAggregate;
	//delete pIterator;

	////Observer mode
	//std::cout << "\n\n" << std::endl;
	//std::cout << "IAMObserver mode" << std::endl;
	//std::cout << "------<<<<<<<<<<<<<-----" << std::endl;
	//CStudent* stuA = new CStudentA("zhangsan");
	//CStudent* stuB = new CStudentB("lisi");
	//CDeanSys	Dean;

	////zhangsan select 1,2,3
	//Dean.SelectCourse(stuA, 1);
	//Dean.SelectCourse(stuA, 2);
	//Dean.SelectCourse(stuA, 3);

	////lisi select 2,3
	//Dean.SelectCourse(stuB, 2);
	//Dean.SelectCourse(stuB, 3);

	//int iclassId;
	//while (true)
	//{
	//	std::cout << "please input course Id:>>";
	//	std::cin >> iclassId;
	//	if (iclassId < 0)
	//	{
	//		break;
	//	}
	//	Dean.NoticeStudent(iclassId);
	//}
	//delete stuA;
	//delete stuB;
	//std::cout << "------<<<<<<<<<<<<<-----" << std::endl;


	////CProcessingData proessData(1000);
	//CProcessingData proessData;
	//proessData.TestThisClass();
	//
 //   std::cout<<"I will start !"<<std::endl;
	//CCallBackReceiver CallBacker;
	//CallBacker.WorkFunction();
 //   std::cout<<"<<<<<<<<<<<<<<<I will end !>>>>>>>>>>>>>>>"<<std::endl;


	//test list 

//    CLinkList* pLinkList = new CLinkList(5, CLinkList::TAIL_INSERTION);
// 	for (int i = 5;i !=10; i++)
// 	{
// 		pLinkList->push_back(i);
// 	}
// 	pLinkList->insert(0, 20);
// 	pLinkList->output();
// 	int index = pLinkList->indexof(4);
// 	std::cout << "the restlt is :" <<index<< std::endl;
// 	pLinkList->erase(5);
// 	pLinkList->output();
// 	int iResult = pLinkList->get(0);
// 	std::cout << "the restlt is :" << iResult << std::endl;
// 
// 	if (nullptr != pLinkList)
// 	{
// 		delete pLinkList;
// 		pLinkList = nullptr;
// 	}

// 	//test CStudyList 
//  	CStudyList* pStudyList = new CStudyList;
//  	pStudyList->PrintElementList();
//  	for (int i = 0;i != 10;i++)
//  	{
//  		pStudyList->AddElementToList(i);
//  	}
//  	pStudyList->PrintElementList();
//  	pStudyList->DeleteList();
//  	pStudyList->PrintElementList();
//  
//  	if (nullptr != pStudyList)
//  	{
//  		delete pStudyList;
//  		pStudyList = nullptr;
//  	}
// 
//     //test CStudyMap
//     CStudyMap* pStudyMap = new CStudyMap;
// 	pStudyMap->PrintTestMap();
// 	pStudyMap->AddTestElement();
// 	pStudyMap->PrintTestMap();
// 	pStudyMap->DeleteAllElement();
// 	pStudyMap->PrintTestMap();
// 
// 	if (nullptr != pStudyMap)
// 	{
// 		delete pStudyMap;
// 		pStudyMap = nullptr;
// 	}



    std::cout << "Hello World!\n";
}


