#include"CPrimerPlus/4thComplexDataType/CFourthComplexDataType.h"
#include<cstdlib>
#include <cstring>
#include <iostream>


//注释掉得都是有问题错误的，需要慢慢研究
void CFourthComplexDataType::TestFourthComplexDataType()
{
	std::cout << "test this void CFourthComplexDataType::GetMemory(char* pChar, int iNum)" << std::endl;
	size_t iSize = 0;
	char* pChar = nullptr;
	GetMemory(pChar, 100);//pChar 依然还是nullptr
	iSize = sizeof(pChar);
	std::cout << "pChar size is :" << iSize << std::endl;
	//std::strcpy(pChar,"hello");//运行时候错误，why?

	//std::cout << "test this void CFourthComplexDataType::GetMemory(char** pChar, int iNum)" << std::endl;
	//char* pStr = nullptr;
	//GetMemory(&pStr, 100);
	//iSize = sizeof(pStr);
	//std::cout << "pStr size is :" << iSize << std::endl;
	//strcpy(pStr, "hello");//this is ok
	//iSize = sizeof(pStr);
	//std::cout << "after strcpy pStr size is :" << iSize << std::endl;
	//std::cout << "after strcpy Value of pStr is :" << pStr << std::endl;
	//free(pStr);//成对出现malloc/free

	//std::cout << "test this char* CFourthComplexDataType::GetMemory(int inum)" << std::endl;
	//char* pChar3 = nullptr;
	//pChar3 = GetMemory(100);
	//iSize = sizeof(pChar3);
	//std::cout << "before strcpy pChar3 size is :" << iSize << std::endl;
	//strcpy(pChar3,"hellolcr");
	//iSize = sizeof(pChar3);
	//std::cout << "after strcpy pChar3 size is :" << iSize << std::endl;
	//std::cout << "after strcpy Value of pChar3  is :" << pChar3 << std::endl;
	//free(pChar3);

	//std::cout << "test this char* CFourthComplexDataType::GetString(void)" << std::endl;
	//char* pCharGetString = nullptr;
	//pCharGetString = GetString();
	//iSize = sizeof(pCharGetString);
	//std::cout << "PCharGetString size is :" << iSize << std::endl;
	//std::cout << "Value of PCharGetString  is :" << pCharGetString << std::endl;

	//std::cout << "test this char* CFourthComplexDataType::GetStringSecond(void)" << std::endl;
	//char* pCharGetStringSecond = nullptr;
	//pCharGetStringSecond = GetStringSecond();
	//iSize = sizeof(pCharGetStringSecond);
	//std::cout << "pCharGetStringSecond size is :" << iSize << std::endl;
	//std::cout << "Value of pCharGetStringSecond  is :" << pCharGetStringSecond << std::endl;

}

void CFourthComplexDataType::GetMemory(char* pChar, int iNum)
{
	pChar = (char*)std::malloc(sizeof(char) * iNum);
}

void CFourthComplexDataType::GetMemory(char** pChar, int iNum)
{
	*pChar = (char*)std::malloc(sizeof(char)*iNum);
}

char* CFourthComplexDataType::GetMemory(int inum)
{
	char* pChar = (char*)std::malloc(sizeof(char) * inum);
	return pChar;
}

char* CFourthComplexDataType::GetString(void)
{
	char pCharArray[] = "hello world";
	return pCharArray;
}

//char* CFourthComplexDataType::GetStringSecond(void)
//{
//	//char* pChar = "hello world";//这里有错误
//	//return pChar;
//}
