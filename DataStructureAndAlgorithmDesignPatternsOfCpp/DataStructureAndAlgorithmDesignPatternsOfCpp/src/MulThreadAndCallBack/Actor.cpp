#include "Actor.h"
#include "ActorImpl.h"

namespace thread {


	Actor::Actor(const char* ptName /*= NULL*/)
	{
		m_pImpl = new ActorImpl(ptName, this);
	}

	Actor::~Actor()
	{
		if (nullptr != m_pImpl)
		{
			delete m_pImpl;
			m_pImpl = nullptr;
		}
	}

	bool Actor::Start()
	{
		if (nullptr == m_pImpl)
		{
			return false;
		}
		return m_pImpl->Start();
	}

	bool Actor::Suspend(void)
	{
		if (nullptr != m_pImpl)
		{
			return m_pImpl->Suspend();
		}
		return false;
	}

	bool Actor::Kill(void)
	{
		if (nullptr != m_pImpl)
		{
			return m_pImpl->Kill();
		}
		return false;
		
	}

	void Actor::SetPriority(int64_t iPriority)
	{
		if (m_pImpl != nullptr)
		{
			m_pImpl->SetPriority(iPriority);
		}
		
	}

	void Actor::TerminateThread(void)
	{
		if (m_pImpl != nullptr)
		{
			m_pImpl->TerminateThread();
		}
	}

	void Actor::WaitForTermination(bool bEnforceKill, int64_t iTimeout)
	{
		if (m_pImpl != NULL)
		{
			m_pImpl->WaitForTermination(bEnforceKill, iTimeout);
		}
	}
}