#ifndef __TEST_ACTOR_H__
#define __TEST_ACTOR_H__

// #include "ThreadUtils/umr_command_actor.h"
#include "ThreadUtils/umr_actor.h"

using namespace threadutils;

class TestActor : public Actor
{
public:
    void svc(void);
};

#endif