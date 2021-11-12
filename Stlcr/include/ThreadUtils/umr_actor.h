//////////////////////////////////////////////////////////////////////////
/// \defgroup ThreadUtils
///  Copyright, (c) Shanghai United Imaging healthcare Inc., 2011
///  All rights reserved.
///
///  \author  Shi Yao Ming  yaoming.shi@united-imaging.com
///
///  \file    umr_actor.h
///  \brief   Define the Actor template class
///
///  \version 1.0
///  \date    Sep. 13, 2011
//////////////////////////////////////////////////////////////////////////

#ifndef UMR_ACTOR_H_
#define UMR_ACTOR_H_

#include <stdio.h>
#include <stdint.h>

#include "ThreadUtils/threadutils_os_type.h"

// namespace
namespace threadutils {

class ActorImpl;

/// \class Actor umr_actor.h
/// \brief Template for the Actor
///
///
/// \par  Usage of this class:
/// \code
///  Actor oActor
///  oActor.Start();
///  oActor.SendCmd();
/// \code
////
class THREADUTILS_EXPORT Actor
{
public:
    /////////////////////////////////////////////////////////////////
    ///  \brief constructor
    ///
    ///  \param[in]    ptName: the name of the Actor
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    Actor(const char * ptName = NULL);

    /////////////////////////////////////////////////////////////////
    ///  \brief deconstructor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~Actor();

    /////////////////////////////////////////////////////////////////
    ///  \brief Start a thread
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       bool: the resulte of starting the thread
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Start();

    /////////////////////////////////////////////////////////////////
    ///  \brief get name of actor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       const char* name
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    const char* GetName();

    /////////////////////////////////////////////////////////////////
    ///  \brief The main loop of the Actor. The method should be overload
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       void
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual void svc() = 0;

private:
    ActorImpl* m_pImpl;
};

} // namespace

#endif // UMR_ACTOR_H_
