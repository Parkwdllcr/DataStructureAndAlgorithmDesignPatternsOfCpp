//////////////////////////////////////////////////////////////////////////
///
///  Copyright, (c) Shanghai United Imaging Health_care Inc., 2011
///  All rights reserved.
///
///  \author   Shi Yaoming  yaoming.shi@united-imaging.com
///
///  \file    umr_actor_impl.cpp
///  \brief
///
///  \version 1.0
///  \date    Sep.15, 2011
///
///  \ChangedBy       NO
///  \ChangedDate     NO
///  \ChangedContent  NO
//////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

#include "umr_actor_impl.h"
#include "ThreadUtils/umr_actor.h"

// namespace
namespace threadutils {

// WIN32 system
#ifndef _THREADUTILS_OS_LINUX_
static unsigned long __cdecl ThreadFunc(void * ptr)
{
    ActorImpl * pImpl = (ActorImpl *)ptr;
    pImpl->svc();
    return 0;
}
#else // Linux system
static void * ThreadFunc(void * ptr)
{
    ActorImpl * pImpl = (ActorImpl *)ptr;
    pImpl->svc();
    return NULL;
}
#endif


ActorImpl::ActorImpl(const char * ptName, Actor * pActor) :
    m_pActor(NULL),
    m_bStarted(false)
{
    m_pActor = pActor;
    memset(acName, 0, sizeof(acName));
    if ( ptName )
    {
        snprintf(acName, sizeof(acName), "%s", ptName);
    }
}

ActorImpl::~ActorImpl( void )
{
    void* thread_result;

    if (m_bStarted)
    {
        pthread_cancel(m_Thread);
        pthread_join(m_Thread, &thread_result);
    }
}

/////////////////////////////////////////////////////////////////
///  \brief  Start the thread via the ACE component
///
///  \param[in]    None
///  \param[out]   None
///  \return       bool: true - successful  false - fail
///
/////////////////////////////////////////////////////////////////
bool ActorImpl::Start( void )
{
#ifdef _THREADUTILS_OS_LINUX_
    if ( 0!=pthread_create(&m_Thread, NULL, ThreadFunc, this) )
    {
        return false;
    }
    m_bStarted = true;
    return true;
#else
    return false;
#endif
}

/////////////////////////////////////////////////////////////////
///  \brief  The main loop of the actor
///
///  \param[in]    None
///  \param[out]   None
///  \return       None
///
/////////////////////////////////////////////////////////////////
void ActorImpl::svc( void )
{
    if (m_pActor != NULL)
    {
        m_pActor->svc();
    }
}

} // namespace
