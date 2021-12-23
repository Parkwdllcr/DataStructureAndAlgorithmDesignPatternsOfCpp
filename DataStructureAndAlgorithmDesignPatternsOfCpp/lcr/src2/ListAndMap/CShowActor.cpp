
#include"ListAndMap/CShowActor.h"
#include "UtilsBox/utilsbox_utils.h"
#include<iostream>

CShowActor:: CShowActor(IStudyStlManagder*  pStudyStlManager):m_bShutDown(true),
              m_pStudyStlManager(pStudyStlManager)
 {

 }

 CShowActor:: ~ CShowActor()
{
    m_pStudyStlManager = nullptr;
}

void  CShowActor::svc(void)
{
    while (m_bShutDown)
    {
        if (nullptr != m_pStudyStlManager)
        {
             m_pStudyStlManager-> ShowElement();
        }
          utilsbox::CUtils::MSleep(1);
    }
     
     utilsbox::CUtils::MSleep(50);
     m_Semaphore.Trigger();
};

void  CShowActor::TerminateThread( void )
{
    m_bShutDown = false;
    if (1 != m_Semaphore.Wait(30*60*1000))
    {
       std::cout<<"wait thread exit timeout! "<<std::endl;
       return ;
    }
    utilsbox::CUtils::MSleep(50);
}