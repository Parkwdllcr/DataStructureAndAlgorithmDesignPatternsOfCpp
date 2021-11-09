#pragma once
#include <iostream>

class CPublicClass
{
public:
	template<typename T>
	void ShowAndSize(const T& testVar);
};

template<typename T>
void CPublicClass::ShowAndSize(const T& testVar)
{
	std::cout << "The Test Value is: " << testVar << std::endl;
	std::cout << "The Test Size is: " << sizeof(testVar) << std::endl;
}

