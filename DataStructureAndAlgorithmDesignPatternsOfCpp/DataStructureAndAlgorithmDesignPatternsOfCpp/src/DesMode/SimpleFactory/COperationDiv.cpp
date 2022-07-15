#include "DesMode/SimpleFactory/COperationDiv.h"
#include <iostream>


bool COperationDiv::GetResult(double& dbResult) const
{
	try
	{
		if (0.0 != m_dbNumberB)
		{
			dbResult = m_dbNumberA / m_dbNumberB;
			return true;
		}
		else
		{
			std::cout<<"Input m_dbNumberB is Error!"<<std::endl;
			return false;
		}
	}
	catch (...)
	{
		std::cout << "Input m_dbNumberB is Error!" << std::endl;
		return false;
	}

}
