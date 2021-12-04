#pragma once
#include <iostream>
#include<string>

class CPublicClass
{
public:
	template<typename T>
	void ShowAndSize(const T& testVar);
	void PrintfTestFunctionFlag(std::string strFunctionNmae);
};

template<typename T>
void CPublicClass::ShowAndSize(const T& testVar)
{
	std::cout << "The Test Value is: " << testVar << std::endl;
	std::cout << "The Test Size is: " << sizeof(testVar) << std::endl;
}

