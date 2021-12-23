
#ifndef __IDOACTOR_H__
#define __IDOACTOR_H__

#include "ThreadUtils/umr_actor.h"
#include "Utilsbox/utilsbox_semaphore.h"

using namespace threadutils;
using namespace utilsbox;

class ITestActor:public Actor
{
  public:
  virtual ~ITestActor(){}
  virtual void TerminateThread( void ) = 0;
};

#endif




