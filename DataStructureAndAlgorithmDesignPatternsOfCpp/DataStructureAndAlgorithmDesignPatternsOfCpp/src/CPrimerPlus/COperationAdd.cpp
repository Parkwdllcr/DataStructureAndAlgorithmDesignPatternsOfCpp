#include "CPrimerPlus/COperationAdd.h"
#include <iostream>



bool COperationAdd::GetResult(double& dbResult) const
{
	try
	{
		dbResult = m_dbNumberA + m_dbNumberB;
		return true;
	}
	catch (...)
	{
		std::cout << "COperationAdd::GetResult UnKnow Error!" << std::endl;
		return false;
	}
	
}
