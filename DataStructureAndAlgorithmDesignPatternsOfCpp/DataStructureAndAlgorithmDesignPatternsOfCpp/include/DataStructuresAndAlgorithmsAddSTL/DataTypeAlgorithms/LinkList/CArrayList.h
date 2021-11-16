#pragma once
#include"CLinearList.h"

class CArrayList:public CLinearList
{
public:
	CArrayList(int iInitialCapacity );
 
	 CArrayList(const CArrayList& theList);

    ~CArrayList(){delete [] m_element;}

public:
    //ADT函数
    int    get(int itheIndex) ;
    int   indexof(const int theElement) const ;
    void  erase(int itheIndex) ;
    void  insert(int itheIndex,const int theElement) ;
    void  output()const ;
	void  clear();
	void  push_back(const int theElement);
    //others function
    int    Capacity() const {return m_iArrayLength;}
	void   ChangeLength_1D(int* a, int iOldLength, int iNewLength);
private:
    int*  m_element;
    int   m_iArrayLength;
};


