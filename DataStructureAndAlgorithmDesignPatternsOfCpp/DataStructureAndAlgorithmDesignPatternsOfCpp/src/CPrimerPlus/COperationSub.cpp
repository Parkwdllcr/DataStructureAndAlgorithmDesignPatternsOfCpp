#include "CPrimerPlus/COperationSub.h"
#include <iostream>

bool COperationSub::GetResult(double& dbResult) const
{
	try
	{
		dbResult = m_dbNumberA - m_dbNumberB;
		return true;
	}
	catch (...)
	{
		std::cout << "COperationSub::GetResult UnKnow Error!" << std::endl;
		return false;
	}
}
