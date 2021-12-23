
#include "ListAndMap/CAddActor.h"
#include "UtilsBox/utilsbox_utils.h"


#include <iostream>

 CAddActor:: CAddActor(IStudyStlManagder*  pStudyStlManager):m_bShutDown(true),
              m_pStudyStlManager(pStudyStlManager)
 {

 }
 
 CAddActor:: ~ CAddActor()
 {
    m_pStudyStlManager = nullptr;
 }

void  CAddActor::svc(void)
{
    while (m_bShutDown)
    {
        

        if (nullptr != m_pStudyStlManager)
        {
             m_pStudyStlManager->AddElemt();
        }
          utilsbox::CUtils::MSleep(1);

    }
     
     utilsbox::CUtils::MSleep(50);
     m_Semaphore.Trigger();
};

void  CAddActor::TerminateThread( void )
{
    m_bShutDown = false;
    if (1 != m_Semaphore.Wait(30*60*1000))
    {
       std::cout<<"wait thread exit timeout! "<<std::endl;
       return ;
    }
    utilsbox::CUtils::MSleep(50);
}