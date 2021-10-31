

//list or vector
#include<string>
#include<iostream>

template<typename T>
struct chainNode
{
    T m_element;
    chainNode<T> *m_next;
    chainNode(){};
    chainNode(const T& element){this->m_element = element;}
    chainNode(const T& element ,chainNode<T>* nest){this->m_element = element;this->m_next = nest;}

};

template<class T>
void ChangeLength_1D(T*& a,int iOldLength,int iNewLength)
{
    try
    {
        if (iNewLength <0)
        {
            throw  "iNewLength is less than zero";
        }

        T * Temp = new T[iNewLength];
        int iNumber = std::min(iOldLength,iNewLength);
        std::copy(a,a+iNumber,Temp);
        delete []a;
        a = Temp; 
    
    }
    catch(const std::string str)
    {
        std::cout<<str<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}

template<class T>
class ILinearList
{
public:
	virtual ~ILinearList() {};
	virtual bool empty() const = 0;
	virtual int  size() const = 0;
	virtual T    get(int itheIndex) const = 0;
	virtual int indexof(const T& theElement) const = 0;
	virtual void erase(int itheIndex) = 0;
	virtual void insert(int itheIndex, const T& theElement) = 0;
	virtual void output()const = 0;

};










