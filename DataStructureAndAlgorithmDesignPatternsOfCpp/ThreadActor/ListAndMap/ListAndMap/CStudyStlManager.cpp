#include"CStudyStlManager.h"
#include"CDeleteActor.h"
#include"CAddActor.h"
#include"CShowActor.h"

#include<iostream>

CStudyStlManager::CStudyStlManager():m_ListActorTest()
{
     m_pStudyList =  new CStudyList();
     //m_pStudyMap  =  new CStudyMap();
}


CStudyStlManager::~CStudyStlManager()
{
    try
    {
        
         if (nullptr != m_pStudyList)
        {
			Shutdown();
			delete m_pStudyList;
			m_pStudyList = nullptr;
        }
        
    }
    catch(...)
    {
        std::cout << "Unkown Err! " <<std::endl;
    }
    
}

int CStudyStlManager:: Initialize()
{
    if (1 != StartProcessThread())
    {
       std::cout<<" StartProcessThread is failed !"<<std::endl;
       return -1;
    }
    return 1;
}

void  CStudyStlManager::Shutdown()
{
    std::list<ITestActor*>::iterator it;
    for (it = m_ListActorTest.begin();it != m_ListActorTest.end();)
    {
        if (nullptr != (*it))
        {
            (*it)->TerminateThread();
           delete (*it);
           (*it) = nullptr;
		   it = m_ListActorTest.erase(it);
        }
		else
		{
			it++;
		}
    }
    
}
int  CStudyStlManager::StartProcessThread()
{
    ITestActor * pAddActor = new CAddActor(this);
    pAddActor->Start();
    m_ListActorTest.push_back( pAddActor);

//不可能会显示什么结果出来的，因为是不同对象
    ITestActor * pShowActor = new CShowActor(this);
    pShowActor->Start();
    m_ListActorTest.push_back(pShowActor);

    ITestActor * pDeleteActor = new CDeleteActor(this);
    pDeleteActor->Start();
    m_ListActorTest.push_back(pDeleteActor);

    return 1;
 
}

   
void  CStudyStlManager::AddElemt()
{
    if(m_pStudyList)
    {
        m_pStudyList->AddElement();
    }
    // if (m_pStudyMap)
    // {
    //     m_pStudyMap->AddElement();
    // }
}
void CStudyStlManager::DeletAllElement()
{
    if(m_pStudyList)
    {
        m_pStudyList->DeleteAllElement();
    }
    // if (m_pStudyMap)
    // {
    //     m_pStudyMap->DeleteAllElement();
    // } 
}
void  CStudyStlManager:: ShowElement()
{

    if(m_pStudyList)
    {
        m_pStudyList-> PrintAllElement();
    }
    // if (m_pStudyMap)
    // {
    //     m_pStudyMap-> PrintAllElement();
    // } 

}

     
