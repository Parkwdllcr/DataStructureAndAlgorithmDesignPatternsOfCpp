#pragma once 


#include "ITestActor.h"
#include "../MulThread/Actor.h"
#include "../MulThread/thread_semaphore.h"
#include "IStudyStlManager.h"


class CShowActor:public ITestActor
{
public:
     CShowActor(IStudyStlManagder*  pStudyStlManager);
     ~CShowActor();
public:
    void svc(void);
    void TerminateThread( void );
private:
    bool                    m_bShutDown;
    CSemaphore              m_Semaphore;
    IStudyStlManagder*      m_pStudyStlManager;
};
