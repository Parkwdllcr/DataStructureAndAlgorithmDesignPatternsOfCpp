//#include "CFactory_MulofFactoryMode.h"
#include "DesMode/FactoryMode/CFactory_MulofFactoryMode.h"


CFactory_MulofFactoryMode::CFactory_MulofFactoryMode()
{

}

CFactory_MulofFactoryMode::~CFactory_MulofFactoryMode()
{
	
}

CProductofFactoryMode* CFactory_MulofFactoryMode::Create()
{
	m_pProductofFactoryMode = new CProducto_MulfFactoryMode;
	return  m_pProductofFactoryMode;
}

void CFactory_MulofFactoryMode::Destory()
{
	if (m_pProductofFactoryMode != nullptr)
	{
		delete m_pProductofFactoryMode;
		m_pProductofFactoryMode = nullptr;
	}
}

