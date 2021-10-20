#pragma once
#include "CProductofFactoryMode.h"
#include "CProducto_AddfFactoryMode.h"
#include "CProducto_MulfFactoryMode.h"

class CFactoryofFactoryMode {

public:
	CFactoryofFactoryMode();
	~CFactoryofFactoryMode();
public:
	virtual CProductofFactoryMode* Create() = 0;

	virtual void Destory() = 0;

protected:
	CProductofFactoryMode*  m_pProductofFactoryMode;
};