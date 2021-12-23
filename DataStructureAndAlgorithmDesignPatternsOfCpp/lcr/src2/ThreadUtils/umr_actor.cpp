//////////////////////////////////////////////////////////////////////////
///
///  Copyright, (c) Shanghai United Imaging Health_care Inc., 2011
///  All rights reserved.
///
///  \author   Shi Yaoming  yaoming.shi@united-imaging.com
///
///  \file    umr_actor.cpp
///  \brief   implementation of class Actor
///
///  \version 1.0
///  \date    Sep.15, 2011
///
///  \ChangedBy       NO
///  \ChangedDate     NO
///  \ChangedContent  NO
//////////////////////////////////////////////////////////////////////////
#include "ThreadUtils/umr_actor.h"

#include "umr_actor_impl.h"

// namespace
namespace threadutils {

Actor::Actor(const char * ptName)
{
    // Create an instance
    m_pImpl = new ActorImpl(ptName, this);
}

Actor::~Actor( void )
{
    // Delete the implemtation instance
    if (m_pImpl != NULL)
    {
        delete m_pImpl;
        m_pImpl = NULL;
    }
}

bool Actor::Start( void )
{
    if (m_pImpl == NULL)
    {
        return false;
    }
    // Call the interface of the implemtation instance
    return m_pImpl->Start();
}

} // namespace
