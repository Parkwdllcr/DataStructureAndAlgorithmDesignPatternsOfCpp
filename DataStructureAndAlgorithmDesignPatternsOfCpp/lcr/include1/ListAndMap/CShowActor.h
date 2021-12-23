#pragma once 

#include "ITestActor.h"
#include "ThreadUtils/umr_actor.h"
#include "UtilsBox/utilsbox_semaphore.h"
#include "ListAndMap/IStudyStlManager.h"

using namespace threadutils;
using namespace utilsbox;


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
