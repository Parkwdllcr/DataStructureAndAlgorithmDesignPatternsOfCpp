//////////////////////////////////////////////////////////////////////////
///
///  Copyright, (c) Shanghai United Imaging Health_care Inc., 2011
///  All rights reserved.
///
///  \author   Shi Yaoming  yaoming.shi@united-imaging.com
///
///  \file    umr_command_actor.h
///  \brief   Define the command actor
///
///  \version 1.0
///  \date    Sep.15, 2011
///
///  \ChangedBy       NO
///  \ChangedDate     NO
///  \ChangedContent  NO
//////////////////////////////////////////////////////////////////////////
#ifndef UMR_COMMAND_ACTOR_H_
#define UMR_COMMAND_ACTOR_H_

#include <stdio.h>
#include <memory.h>

#include "ThreadUtils/umr_actor.h"
#include "ThreadUtils/umr_command_queue.h"

// namespace
namespace threadutils {

/// \class CommandActor umr_command_actor.h
/// \brief Define synchronous and asynchronous message function
///
///
/// \par  Usage of this class:
/// \code
///      CommandActor* pActor = new CommandActor( "LoadCommandActor" );
///      pActor->SendCommand( LOAD_COMMAND, NULL, 0 );
/// \code
////
template < class COMMAND, class RETURN >
class CommandActor : public Actor
{
public:
    enum
    {
        CMD_SHUTDOWN = -1,
        CMD_INFINITE = -1,
    };

    /////////////////////////////////////////////////////////////////
    ///  \brief Constructor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    CommandActor( void )
        : Actor( NULL )
        , m_bShutdown( false )
        , m_iTimeout( -1 )
    {
    }

    /////////////////////////////////////////////////////////////////
    ///  \brief Constructor
    ///
    ///  \param[in]    const char* sName: actor's name
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    CommandActor( const char* sName )
        : Actor( sName )
        , m_bShutdown( false )
        , m_iTimeout( -1 )
    {
    }

    /////////////////////////////////////////////////////////////////
    ///  \brief Deconstructor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual ~CommandActor( void )
    {
        m_bShutdown = true;
    }

    /////////////////////////////////////////////////////////////////
    ///  \brief Start the thread. Firstly empty the queue, then spawn a thread
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    bool Start( void )
    {
        //delete this, because of such situation: before Start(), there is command in the queue
        //m_oQueue.Empty();

        return ( ( Actor * )this )->Start();
    }

    /////////////////////////////////////////////////////////////////
    ///  \brief Send a command(synchronous method)
    ///
    ///  \param[in]    int32_t iCmd: command's id
    ///                const void * pBuffer: command's data
    ///                int32_t iSize: size of command's data
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual void SendCommand( const COMMAND oCommand, RETURN& oReturn )
    {
        // send message
        oReturn = m_oQueue.SendSyncCmd( oCommand, -1 );
    }

    /////////////////////////////////////////////////////////////////
    ///  \brief Pend a command(asynchronous method)
    ///
    ///  \param[in]    int32_t iCmd: command's id
    ///                const void * pBuffer: command's data
    ///                int32_t iSize: size of command's data
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual bool PostCommand( const COMMAND oCommand )
    {
        // post message
        return m_oQueue.SendCmd( oCommand );
    }

    /////////////////////////////////////////////////////////////////
    ///  \brief Terminate the thread of the actor
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual void TerminateThread( void )
    {
       m_bShutdown = true;

        // This will kill the thread if it still is active
        WaitForTermination( true, 1000 );
    }

    //virtual void Empty()
    //{
    //    m_oQueue.Empty();
    //}

    /////////////////////////////////////////////////////////////////
    ///  \brief actor's main function
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual void svc( void )
    {
        COMMAND oCommand;
        RETURN oReturn;

        while( ! m_bShutdown )
        {
            if( m_oQueue.GetCmd( oCommand, m_iTimeout ) )
            {
                // parse the received command
                ParseCommand( oCommand, oReturn );
                m_oQueue.SetRetun( oReturn );
            }
            else
            {
                HandleTimeout();
                // Timeout
            }
        }
    }

protected:
    /////////////////////////////////////////////////////////////////
    ///  \brief set the time about timeout
    ///
    ///  \param[in]    int64_t iTimeout: time
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual void SetCommandTimeout( int64_t iTimeout )
    {
        m_iTimeout = iTimeout;
    }

    /////////////////////////////////////////////////////////////////
    ///  \brief handle timeout
    ///
    ///  \param[in]    None
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual void HandleTimeout( void )
    {
        //std::cout << "Timeout" << std::endl;
    }

    /////////////////////////////////////////////////////////////////
    ///  \brief Parse the received command
    ///
    ///  \param[in]    int32_t iCmd: command's id
    ///                const void * pBuffer: command's data
    ///                int32_t iSize: size of command's data
    ///  \param[out]   None
    ///  \return       None
    ///  \pre \e
    /////////////////////////////////////////////////////////////////
    virtual void ParseCommand( const COMMAND& oCommand, RETURN& oReturn ) = 0;

 protected:
    ///< list of command
    CommandQueue< COMMAND, RETURN > m_oQueue;

    ///< close flag
    bool m_bShutdown;

    /// command's timeout
    int64_t m_iTimeout;
};

} // namespace

#endif // UMR_COMMAND_ACTOR_H_
