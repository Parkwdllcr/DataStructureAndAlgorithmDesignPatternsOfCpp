#include"CDeleteActor.h"
#include "../MulThread/cutil_box.h"

#include<iostream>




 CDeleteActor::CDeleteActor(IStudyStlManagder*  pStudyStlManager):m_bShutDown(true),
              m_pStudyStlManager(pStudyStlManager)
 {

 }
CDeleteActor:: ~CDeleteActor()
{
	m_bShutDown = false;
}

void CDeleteActor::svc(void)
{
    while (m_bShutDown)
    {
        if (nullptr != m_pStudyStlManager)
        {
             m_pStudyStlManager->DeletAllElement();
        }
		Util::CUtils::MSleep(1);
    }
     
	Util::CUtils::MSleep(50);
     m_Semaphore.Trigger();
};

void CDeleteActor::TerminateThread( void )
{
    m_bShutDown = false;
    if (1 != m_Semaphore.Wait())
    {
       std::cout<<"wait thread exit timeout! "<<std::endl;
       return ;
    }
	Util::CUtils::MSleep(50);
}