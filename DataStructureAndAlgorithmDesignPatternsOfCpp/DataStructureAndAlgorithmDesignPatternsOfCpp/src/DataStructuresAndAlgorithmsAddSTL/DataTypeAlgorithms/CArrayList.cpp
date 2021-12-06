#include "DataStructuresAndAlgorithmsAddSTL/DataTypeAlgorithms/CArrayList.h"
#include <algorithm>


CArrayList::CArrayList(int iInitialCapacity):m_iArrayLength(iInitialCapacity)
{
	try {
		if (iInitialCapacity < 1)
		{
			throw "iInitialCapacity < 1";
		}
		m_element = new int[m_iArrayLength];
		CArrayList::m_iListSize = 0;

	}
	catch (const char* pStrErr) {
		std::cout << pStrErr << std::endl;
	}

}

CArrayList::CArrayList(const CArrayList& theList):m_iArrayLength(theList.m_iArrayLength)
{
	CArrayList::m_iListSize = theList.CArrayList::m_iListSize;
	m_element = new int[m_iArrayLength];
	std::copy(theList.m_element, theList.m_element + CArrayList::m_iListSize, m_element);
}


void CArrayList::push_back(const int theElement)
{
	std::cout<<"<-------------------------------------------------->"<<std::endl;
	std::cout << "void CArrayList<T>::push_back(const T& theElement)" << std::endl;

	int iCheakNum = CheckIndex(m_iArrayLength);
	switch (iCheakNum)
	{
	case LESS_THAN_ZERO:
		break;
	case MORE_THAN_SIZE:
		ChangeLength_1D(m_element, m_iArrayLength, 2 * m_iArrayLength);
		m_element[m_iArrayLength] = theElement;
		break;
	default:
		m_element[m_iArrayLength] = theElement;
		break;
	}
}

void CArrayList::clear()
{
	delete[]m_element;
	CLinearList::m_iListSize = 0;
	m_iArrayLength = 0;
}

void CArrayList::ChangeLength_1D(int*a, int iOldLength, int iNewLength)
{
	try
	{
		CheckIndex(iNewLength);
		int* Temp = new int[iNewLength];
		int iNumber = std::min(iOldLength, iNewLength);
		std::copy(a, a + iNumber, Temp);
		delete[]a;
		a = Temp;

	}
	catch (const std::string str)
	{
		std::cout << str << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void CArrayList::output() const
{
	for (int i =0;i != CArrayList::m_iListSize;i++)
	{
		std::cout << m_element[i]<< std::endl;
	}
	
}


void CArrayList::insert(int itheIndex, const int theElement)
{
	CheckIndex(itheIndex);
	if (CArrayList::m_iListSize == m_iArrayLength)
	{
		ChangeLength_1D(m_element, m_iArrayLength, 2 * m_iArrayLength);
		m_iArrayLength *= 2;
	}
	std::copy_backward(m_element + itheIndex, m_element + CArrayList::m_iListSize, m_element + CArrayList::m_iListSize + 1);
	m_element[itheIndex] = theElement;
	CArrayList::m_iListSize++;
}

void CArrayList::erase(int itheIndex)
{
	CheckIndex(itheIndex);
	std::copy(m_element + itheIndex + 1, m_element + CArrayList::m_iListSize, m_element + itheIndex);
	//delete one element memory
	m_element[--CArrayList::m_iListSize];//this is out my think ! I will check it ! 
}


int CArrayList::indexof(const int theElement) const
{
	//get the frist index by theElement
	//std::find
	/*int theIndex = (int)(std::find(m_element,m_element+m_iListSize,theElement)-m_element);
	if (theIndex == m_iListSize)
	{
		return -1;
	}
	else
	{
		return theIndex;
	}*/
	//if I write ,it is following example
	//Use STL a lot
	for (int i = 0;i != CArrayList::m_iListSize;i++)
	{
		//some element is not ==,it is wrong£¡
		if (theElement == m_element[i])
		{
			return i;//if return ptr ,this is wrong!!
		}
	}
	return -1;

}


int CArrayList::get(int itheIndex)
{
    CheckIndex(itheIndex);
    return m_element[itheIndex];
}

