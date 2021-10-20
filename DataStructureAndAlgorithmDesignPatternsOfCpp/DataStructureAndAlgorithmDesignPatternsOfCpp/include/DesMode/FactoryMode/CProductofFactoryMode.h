#pragma once

//Factory Mode

class CProductofFactoryMode
{
public:
	CProductofFactoryMode();
	~CProductofFactoryMode();
public:
	virtual int operation(int a, int b) = 0;
};


