#include "CPrimerPlus/COperationMul.h"
#include <iostream>
bool COperationMul::GetResult(double& dbResult) const
{
	try
	{
		dbResult = m_dbNumberA * m_dbNumberB;
		return true;
	}
	catch (...)
	{
		std::cout << "COperationMul::GetResult UnKnow Error!" << std::endl;
		return false;
	}

}
