#include"ILinkList.h"

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
        std::copy(theList.m_element,theList.m_element+m_iListSize,m_element);//copy的用法是什么？

    }
    ~CArrayList(){delete [] m_element;}

public:
    //ADT函数
    bool empty() const {return m_iListSize == 0;}
    int  Size() const{return m_iListSize;}
    T    get(int itheIndex) const ;
    int  indexof(const T &theElement) const ;
    void erase(int itheIndex) ;
    void insert(int itheIndex,const T &theElement) ;
    void output(std::ostream &out)const ;
    //其他方法
    int    Capacity() const {return m_iArrayLength;}

protected:
    void CheckIndex(int iTheIndex)const;
    T* m_element;
    int m_iArrayLength;
    int m_iListSize;

};


template<typename T>
T CArrayList<T>::get(int itheIndex) const
{
    CheckIndex(itheIndex);
    return m_element[itheIndex];

}

template<typename T>
void CArrayList<T>::CheckIndex(int iTheIndex) const
{


}
