#pragma once

#include"IStudyStlManager.h"
#include"CStudyList.h"
#include"CStudyMap.h"
#include"ITestActor.h"
#include<list>

class CStudyStlManager:public IStudyStlManagder
{
public:
     CStudyStlManager();
     virtual ~CStudyStlManager();

public:
     int   Initialize();
     void  Shutdown();
     int   StartProcessThread();

public:
     void  AddElemt();
     void  DeletAllElement();
     void  ShowElement();

private:
     IStudyStl*              m_pStudyList;
     IStudyStl*              m_pStudyMap;
     std::list<ITestActor*>  m_ListActorTest;

private:
    // CStudyStlManager(const CStudyStlManager& other);
    // CStudyStlManager& operator=(const CStudyStlManager& other);
};