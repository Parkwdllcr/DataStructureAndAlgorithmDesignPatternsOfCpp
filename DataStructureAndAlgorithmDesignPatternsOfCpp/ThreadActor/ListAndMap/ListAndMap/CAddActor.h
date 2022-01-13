#pragma once 
#include"ITestActor.h"
#include "../MulThread/Actor.h"
#include "../MulThread/thread_semaphore.h"
#include "IStudyStlManager.h"

class CAddActor:public ITestActor
{
public:
     CAddActor(IStudyStlManagder*  pStudyStlManager);
     ~CAddActor();
public:
    void svc(void);
    void TerminateThread( void );
private:
    bool                    m_bShutDown;
    CSemaphore              m_Semaphore;
    IStudyStlManagder*      m_pStudyStlManager;
    
};
