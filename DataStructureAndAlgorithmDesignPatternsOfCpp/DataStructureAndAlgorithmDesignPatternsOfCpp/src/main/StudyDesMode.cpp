// StudyDesMode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CPrimerPlus/CPrimerPlus.h"
#include "DataStructuresAndAlgorithms/DataTypeAlgorithms/CLinkList.h"
#include "DataStructuresAndAlgorithms/DataTypeAlgorithms/CArrayList.h"

int main()
{
	double dbResult;
	std::shared_ptr<CStudyCPrimerPlus> pStudyPrimerPlus (new CStudyCPrimerPlus);
	COperation* pOperation = pStudyPrimerPlus->CreateOperation(ADDITION);
	if (true != pOperation->GetResult(dbResult))
	{
		std::cout << "COperation Get Result Failed!" << std::endl;
		return 0;
	}
	std::cout << "Get Result Value  = " << dbResult << std::endl;

}


