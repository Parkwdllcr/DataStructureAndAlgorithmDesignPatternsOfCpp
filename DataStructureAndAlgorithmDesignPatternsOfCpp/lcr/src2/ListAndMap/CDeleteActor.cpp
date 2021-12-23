#include"ListAndMap/CDeleteActor.h"
#include "UtilsBox/utilsbox_utils.h"

#include<iostream>




 CDeleteActor::CDeleteActor(IStudyStlManagder*  pStudyStlManager):m_bShutDown(true),
              m_pStudyStlManager(pStudyStlManager)
 {

 }
CDeleteActor:: ~CDeleteActor()
{
    m_pStudyStlManager = nullptr;
}

void CDeleteActor::svc(void)
{
    while (m_bShutDown)
    {
        if (nullptr != m_pStudyStlManager)
        {
             m_pStudyStlManager->DeletAllElement();
        }
          utilsbox::CUtils::MSleep(1);
    }
     
     utilsbox::CUtils::MSleep(50);
     m_Semaphore.Trigger();
};

void CDeleteActor::TerminateThread( void )
{
    m_bShutDown = false;
    if (1 != m_Semaphore.Wait(30*60*1000))
    {
       std::cout<<"wait thread exit timeout! "<<std::endl;
       return ;
    }
    utilsbox::CUtils::MSleep(50);
}