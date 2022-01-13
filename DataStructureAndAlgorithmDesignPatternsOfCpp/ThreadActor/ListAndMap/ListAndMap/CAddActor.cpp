
#include "CAddActor.h"
#include "../MulThread/cutil_box.h"
#include <iostream>

 CAddActor:: CAddActor(IStudyStlManagder*  pStudyStlManager):m_bShutDown(true),
              m_pStudyStlManager(pStudyStlManager)
 {

 }
 
 CAddActor:: ~ CAddActor()
 {
	m_bShutDown = false;
 }

void  CAddActor::svc(void)
{
    while (m_bShutDown)
    {
        if (nullptr != m_pStudyStlManager)
        {
             m_pStudyStlManager->AddElemt();
        }
		Util::CUtils::MSleep(1);
    }
	Util::CUtils::MSleep(50);
    m_Semaphore.Trigger();
};

void  CAddActor::TerminateThread( void )
{
    m_bShutDown = false;
    if (m_Semaphore.Wait())
    {
       std::cout<<"wait thread exit timeout! "<<std::endl;
       return ;
    }
	Util::CUtils::MSleep(50);
}