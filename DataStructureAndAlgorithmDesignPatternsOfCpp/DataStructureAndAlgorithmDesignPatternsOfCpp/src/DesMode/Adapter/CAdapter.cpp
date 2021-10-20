#include"DesMode/Adapter/CAdapter.h"
#include <iostream>


Target::Target()
{

}

Target::~Target()
{

}

void Target::Request()
{
	std::cout << "Target::Request()" << std::endl;
}

Adaptee::Adaptee()
{

}

Adaptee::~Adaptee()
{

}

void Adaptee::SpecificRequest()
{
	std::cout << "Adaptee::SpecificRequest()" << std::endl;

}

CAdapter::CAdapter()
{

}

CAdapter::~CAdapter()
{

}

void CAdapter::Request()
{
	std::cout << "CAdapter::Request()" << std::endl;
	this->SpecificRequest();
	std::cout << "----------------" << std::endl;
}

//CAdapter1::CAdapter1(Adaptee* _adaptee)
//{
//	this->m_padaptee = _adaptee;
//}
//
//CAdapter1::~CAdapter1()
//{
//
//}
//
//void CAdapter1::Request()
//{
//	std::cout << "CAdapter1::Request()" << std::endl;
//	this->m_padaptee->SpecificRequest();
//	std::cout << "----------------" << std::endl;
//}
