//////////////////////////////////////////////////////////////////////////
///
///  Copyright, (c) Shanghai United Imaging Health_care Inc., 2011
///  All rights reserved.
///
///  \author   Huang Jintao jintao.huang@united-imaging.com
///
///  \file    umr_actor_impl.h
///  \brief   specific implementation details
///
///  \version 1.0
///  \date    Aug. 15, 2014
///
///  \ChangedBy       NO
///  \ChangedDate     NO
///  \ChangedContent  NO
//////////////////////////////////////////////////////////////////////////
#ifndef UMR_ACTOR_IMPL_H_
#define UMR_ACTOR_IMPL_H_

#include "ThreadUtils/threadutils_os_type.h"
#include <pthread.h>
//#ifndef _THREADUTILS_OS_LINUX_
//#else
//#include <pthread.h>
//#endif
#include "ThreadUtils/umr_semaphore.h"

// namespace
namespace threadutils {

class Actor;

/// \class ActorImpl umr_actor_impl.h
/// \brief Implementation of the Actor
///
///
/// \par  Usage of this class:
/// \code
/// \code
////
class ActorImpl
{
public:
    ActorImpl(const char * ptName, Actor * pActor);

    virtual ~ActorImpl( void );

    /////////////////////////////////////////////////////////////////
    ///  \brief  Start the thread
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       bool: true - successful  false - fail
    ///
    /////////////////////////////////////////////////////////////////
    bool Start(void);

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
    ///  \brief  The main loop of the actor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///
    /////////////////////////////////////////////////////////////////
    virtual void svc( void );

protected:
    ///< The pointer of the Actor
    Actor* m_pActor;

private:
    ///< If the thread being started
    bool m_bStarted;
	pthread_t m_Thread;

//#ifndef _THREADUTILS_OS_LINUX_
//#else
//    pthread_t m_Thread;
//#endif
    char acName[64];
};

} // namespace

#endif // UMR_ACTOR_IMPL_H_
