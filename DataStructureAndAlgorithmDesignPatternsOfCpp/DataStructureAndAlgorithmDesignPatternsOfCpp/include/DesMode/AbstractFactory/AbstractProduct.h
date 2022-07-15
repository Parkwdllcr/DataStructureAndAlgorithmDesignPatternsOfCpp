#pragma once
#include <iostream>

class AbstractProductA
{
public:
	AbstractProductA() {}
	virtual ~AbstractProductA() {}
};


class ConcreateProductA1 :public AbstractProductA
{
public:
	ConcreateProductA1();
	
	virtual ~ConcreateProductA1() {}
};

class ConcreateProductA2 :public AbstractProductA
{
public:
	ConcreateProductA2();
	
	virtual ~ConcreateProductA2() {}
};

class AbstractProductB
{
public:
	AbstractProductB() {}
	virtual ~AbstractProductB() {}
};

class ConcreateProductB1 :public AbstractProductB
{
public:
	ConcreateProductB1();
	
	virtual ~ConcreateProductB1() {}
};

class ConcreateProductB2 :public AbstractProductB
{
public:
	ConcreateProductB2();
	
	virtual ~ConcreateProductB2() {}
};