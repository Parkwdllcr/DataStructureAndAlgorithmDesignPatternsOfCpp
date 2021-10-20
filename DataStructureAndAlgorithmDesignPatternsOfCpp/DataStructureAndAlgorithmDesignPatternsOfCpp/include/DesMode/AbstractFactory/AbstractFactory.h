#pragma once
#include "AbstractProduct.h"

class AbstractFactory
{
public:
	AbstractFactory() {}
	virtual ~AbstractFactory() {}
	virtual AbstractProductA* CreateProductA() = 0;
	virtual AbstractProductB* CreateProductB() = 0;
};

class ConcreteFactory1 :public AbstractFactory
{
public:
	ConcreteFactory1();
	virtual ~ConcreteFactory1() {}
	virtual AbstractProductA* CreateProductA();
	virtual AbstractProductB* CreateProductB();
};

class ConcreteFactory2 :public AbstractFactory
{
public:
	ConcreteFactory2();
	virtual ~ConcreteFactory2() {}
	virtual AbstractProductA* CreateProductA();
	virtual AbstractProductB* CreateProductB();

};
