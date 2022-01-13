
#pragma once

#include "Actor.h"
#include "thread_command_queue.h"
#include <stdio.h>
#include <memory.h>

// namespace


template < class COMMAND, class RETURN >
class CommandActor : public Actor
{
public:
    enum
    {
        CMD_SHUTDOWN = -1,
        CMD_INFINITE = -1,
    };

    CommandActor( void )
        : Actor( NULL )
        , m_bShutdown( false )
        , m_iTimeout( -1 )
    {
    }
    CommandActor( const char* sName )
        : Actor( sName )
        , m_bShutdown( false )
        , m_iTimeout( -1 )
    {
    }

    virtual ~CommandActor( void )
    {
        m_bShutdown = true;
    }

    bool Start( void )
    {
        //delete this, because of such situation: before Start(), there is command in the queue
        //m_oQueue.Empty();

        return ( ( Actor * )this )->Start();
    }


    virtual void SendCommand( const COMMAND oCommand, RETURN& oReturn )
    {
        // send message
        oReturn = m_oQueue.SendSyncCmd( oCommand, -1 );
    }

    virtual bool PostCommand( const COMMAND oCommand )
    {
        // post message
        return m_oQueue.SendCmd( oCommand );
    }

    virtual void TerminateThread( void )
    {
       m_bShutdown = true;

        // This will kill the thread if it still is active
        WaitForTermination( true, 1000 );
    }
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
    virtual void SetCommandTimeout( int64_t iTimeout )
    {
        m_iTimeout = iTimeout;
    }

    virtual void HandleTimeout( void )
    {
        //std::cout << "Timeout" << std::endl;
    }

    virtual void ParseCommand( const COMMAND& oCommand, RETURN& oReturn ) = 0;

 protected:

    CommandQueue< COMMAND, RETURN > m_oQueue;
    bool m_bShutdown;

    int64_t m_iTimeout;
};



