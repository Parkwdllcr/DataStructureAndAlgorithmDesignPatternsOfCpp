#include"ILinkList.h"

//vector 

template<typename T>
class CArrayList:public ILinearList<T>
{
public:
    CArrayList(int iInitialCapacity = 10)
    {
        try {
            if(iInitialCapacity < 1)
            {
             throw "iInitialCapacity < 1";
            }
            m_iArrayLength = iInitialCapacity;
            m_element = new T[m_iArrayLength];
            m_iListSize = 0;

        }
        catch (std::string str) {
            std::cout<<str<<std::endl;
        }

    }
    CArrayList(const CArrayList<T>& theList)
    {
        m_iArrayLength = theList.m_iArrayLength;
        m_iListSize = theList.m_iListSize;
        m_element = new T[m_iArrayLength];
        std::copy(theList.m_element,theList.m_element+m_iListSize,m_element);
    }
    ~CArrayList(){delete [] m_element;}

public:
    //ADT函数
    bool empty() const {return m_iListSize == 0;}
    int  size() const{return m_iListSize;}
    T    get(int itheIndex) const ;
    int  indexof(const T &theElement) const ;
    void erase(int itheIndex) ;
    void insert(int itheIndex,const T &theElement) ;
    void output()const ;
	void clear();
	void push_back(const T& theElement);
    //others function
    int    Capacity() const {return m_iArrayLength;}
	void ChangeLength_1D(T*& a, int iOldLength, int iNewLength);

protected:
    T* m_element;
    int m_iArrayLength;
   // int m_iListSize;

};

template<typename T>
void CArrayList<T>::clear()
{
	delete[]m_element;
	m_iListSize = 0;
	m_iArrayLength = 0;
}

template<typename T>
void CArrayList<T>::ChangeLength_1D(T*& a, int iOldLength, int iNewLength)
{
	try
	{
		CheckIndex(iNewLength);
		T* Temp = new T[iNewLength];
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

template<typename T>
void CArrayList<T>::output() const
{
	for (int i =0;i != m_iListSize;i++)
	{
		std::cout << m_element[i]<< std::endl;
	}
	
}

template<typename T>
void CArrayList<T>::insert(int itheIndex, const T& theElement)
{
	CheckIndex(itheIndex);
	if (m_iListSize == m_iArrayLength)
	{
		ChangeLength_1D(m_element, m_iArrayLength, 2 * m_iArrayLength);
		m_iArrayLength *= 2;
	}
	std::copy_backward(m_element + itheIndex,m_element+m_iListSize,m_element+m_iListSize+1);
	m_element[itheIndex] = theElement;
	m_iListSize++;
}

template<typename T>
void CArrayList<T>::erase(int itheIndex)
{
	CheckIndex(itheIndex);
	std::copy(m_element + itheIndex + 1, m_element + m_iListSize, m_element + itheIndex);
	//delete one element memory
	m_element[--m_iListSize].~T();//this is out my think ! I will check it ! 
}

template<typename T>
int CArrayList<T>::indexof(const T& theElement) const
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
	for (int i = 0;i != m_iListSize;i++)
	{
		//some element is not ==,it is wrong！
		if (theElement == m_element[i])
		{
			return i;//if return ptr ,this is wrong!!
		}
	}
	return -1;

}

template<typename T>
T CArrayList<T>::get(int itheIndex) const
{
    CheckIndex(itheIndex);
    return m_element[itheIndex];

}

