#pragma once
#include <iostream>

class AbstractProductA
{
public:
	AbstractProductA() {}
	virtual ~AbstractProductA() {}
};

//������ConcreateProductAl,�̳���AbstractProductA,������ƷA�ĵ�һ��ʵ��
class ConcreateProductA1 :public AbstractProductA
{
public:
	ConcreateProductA1();
	
	virtual ~ConcreateProductA1() {}
};
//������ConcreateProductA2,�̳���AbstractProductA,������ƷA�ĵڶ���ʵ��
class ConcreateProductA2 :public AbstractProductA
{
public:
	ConcreateProductA2();
	
	virtual ~ConcreateProductA2() {}
};
//�������AbstractProductB,������ƷB�ĳ���
class AbstractProductB
{
public:
	AbstractProductB() {}
	virtual ~AbstractProductB() {}
};
//������ConcreateProductB1,�̳���AbstractProductB,������ƷB�ĵ�һ��ʵ��
class ConcreateProductB1 :public AbstractProductB
{
public:
	ConcreateProductB1();
	
	virtual ~ConcreateProductB1() {}
};
//������ConcreateProductB2,�̳���AbstractProductB,������ƷB�ĵڶ���ʵ��
class ConcreateProductB2 :public AbstractProductB
{
public:
	ConcreateProductB2();
	
	virtual ~ConcreateProductB2() {}
};