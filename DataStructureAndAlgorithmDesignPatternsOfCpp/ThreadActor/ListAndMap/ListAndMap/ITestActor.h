
#pragma once
#include "../MulThread/Actor.h"
//#include "MulThread/thread_semaphore.h"

class ITestActor:public Actor
{
  public:
  virtual ~ITestActor(){}
  virtual void TerminateThread( void ) = 0;
};






