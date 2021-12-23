#pragma once 

#include"ITestActor.h"
#include "ThreadUtils/umr_actor.h"
#include "UtilsBox/utilsbox_semaphore.h"
#include "ListAndMap/IStudyStlManager.h"

using namespace threadutils;
using namespace utilsbox;

class IStudyManager;

class CDeleteActor:public ITestActor
{
public:
     CDeleteActor(IStudyStlManagder*  pStudyStlManager);
     ~CDeleteActor();
public:
    void svc(void);
    void TerminateThread( void );
private:
    bool                    m_bShutDown;
    CSemaphore              m_Semaphore;
    IStudyStlManagder*      m_pStudyStlManager;
};
