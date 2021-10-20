#pragma once

class  Target
{
public:
	Target();
	~Target();
	virtual void Request();//难受
};

//都是些什么注释
class Adaptee
{
public:
	Adaptee();
	~Adaptee();
	void	SpecificRequest();
};
//this is a wrong 
//test one wrong
class CAdapter :public Target, private Adaptee
{
public:
	CAdapter();
	~CAdapter();
	virtual void Request();//ʵ��Target�����Request�ӿ�
};

//I will test the VM

//no ok?


//
//class CAdapter1 :public Target
//{
//public:
//	CAdapter1() :m_padaptee(new Adaptee) {}
//	CAdapter1(Adaptee* _adaptee);
//	~CAdapter1();
//	virtual void Request();
//private:
//	Adaptee* m_padaptee;
//};