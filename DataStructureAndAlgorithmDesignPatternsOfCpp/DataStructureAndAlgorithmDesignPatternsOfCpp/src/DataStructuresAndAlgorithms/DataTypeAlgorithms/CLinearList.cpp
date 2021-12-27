#include "DataStructuresAndAlgorithms/DataTypeAlgorithms/CLinearList.h"



int CLinearList::CheckIndex(int iTheIndex)
{
	try
	{
		if (iTheIndex < 0)
		{
			std::cout << "iTheIndex is less than 0" << std::endl;
			throw LESS_THAN_ZERO;
		}
		if (iTheIndex > m_iListSize-1)
		{
			std::cout << "itheindex is more than listsize" << std::endl;
			throw MORE_THAN_SIZE;
		}
		return iTheIndex;
	}
	catch (int iError)
	{
		return iError;
	}
}



