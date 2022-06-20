#include "CPrimerPlus/COperation.h"
#include <iostream>
#include <exception>

COperation::COperation():m_dbNumberA(0.0),m_dbNumberB(0.1)
{

}

COperation::COperation(double dbNumberA, double dbNumberB):m_dbNumberA(dbNumberA),m_dbNumberB(dbNumberB)
{

}

COperation::~COperation()
{

}

bool COperation::SetNumberA(const double dbNumberA) 
{
	try
	{
		m_dbNumberA = dbNumberA;
		return true;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}

}

bool COperation::GetNumberA(double& dbResultA) const
{
	try
	{
		dbResultA = m_dbNumberA ;
		return true;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
}

bool COperation::SetNumberB(const double dbNumberB) 
{
	try
	{
		m_dbNumberB = dbNumberB;
		return true;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
}

bool COperation::GetNumberB(double& dbResultB) const
{
	try
	{
		dbResultB = m_dbNumberB;
		return true;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
}
