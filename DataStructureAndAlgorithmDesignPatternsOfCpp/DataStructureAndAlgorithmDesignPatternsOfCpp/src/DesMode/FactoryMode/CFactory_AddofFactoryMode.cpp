#include"DesMode/FactoryMode/CFactory_AddofFactoryMode.h"

CProductofFactoryMode* CFactory_AddofFactoryMode::Create()
{
	m_pProductofFactoryMode = new CProducto_AddfFactoryMode;
	return  m_pProductofFactoryMode;
}

void CFactory_AddofFactoryMode::Destory()
{
	if (m_pProductofFactoryMode != nullptr)
	{
		delete m_pProductofFactoryMode;
		m_pProductofFactoryMode = nullptr;
	}
}
