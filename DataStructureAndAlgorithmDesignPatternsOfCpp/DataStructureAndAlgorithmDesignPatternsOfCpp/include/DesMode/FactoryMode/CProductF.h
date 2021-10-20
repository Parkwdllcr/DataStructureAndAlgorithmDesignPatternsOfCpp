#pragma once

class CProductFofAbstractFactoryMode
{
public:
	CProductFofAbstractFactoryMode();
	~CProductFofAbstractFactoryMode();
public:
	virtual int operation(int a, int b) = 0;
};

