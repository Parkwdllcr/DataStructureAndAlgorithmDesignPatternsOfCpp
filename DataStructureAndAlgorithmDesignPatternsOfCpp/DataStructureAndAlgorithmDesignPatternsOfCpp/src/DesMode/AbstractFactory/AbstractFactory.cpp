#include "DesMode/AbstractFactory/AbstractFactory.h"

ConcreteFactory1::ConcreteFactory1()
{
	std::cout << "ConcreteFactory1" << std::endl;
}

AbstractProductA* ConcreteFactory1::CreateProductA()
{
	return new ConcreateProductA1();
}

AbstractProductB* ConcreteFactory1::CreateProductB()
{
	return new ConcreateProductB1();
}

ConcreteFactory2::ConcreteFactory2()
{
	std::cout << "ConcreteFactory2" << std::endl;
}

AbstractProductA* ConcreteFactory2::CreateProductA()
{
	return new ConcreateProductA2();
}

AbstractProductB* ConcreteFactory2::CreateProductB()
{
	return new ConcreateProductB2();
}
