
#include"CShowActor.h"
#include "../MulThread/cutil_box.h"
#include<iostream>

CShowActor:: CShowActor(IStudyStlManagder*  pStudyStlManager):m_bShutDown(true),
              m_pStudyStlManager(pStudyStlManager)
 {

 }

 CShowActor:: ~ CShowActor()
{
	m_bShutDown = false;
}

void  CShowActor::svc(void)
{
    while (m_bShutDown)
    {
        if (nullptr != m_pStudyStlManager)
        {
             m_pStudyStlManager-> ShowElement();
        }
		Util::CUtils::MSleep(1);
    }
     
	Util::CUtils::MSleep(50);
     m_Semaphore.Trigger();
};

void  CShowActor::TerminateThread( void )
{
    m_bShutDown = false;
    if (m_Semaphore.Wait())
    {
       std::cout<<"wait thread exit timeout! "<<std::endl;
       return ;
    }
	Util::CUtils::MSleep(50);
}