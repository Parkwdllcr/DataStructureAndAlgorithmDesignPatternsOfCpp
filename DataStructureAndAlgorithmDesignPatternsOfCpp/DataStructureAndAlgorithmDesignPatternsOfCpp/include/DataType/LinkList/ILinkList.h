

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
class ILinearList
{
public:
	virtual ~ILinearList() {};
	virtual bool empty() const = 0;
	virtual int  size() const = 0;
	virtual T    get(int itheIndex) const = 0;
	virtual int  indexof(const T& theElement) const = 0;
	virtual void erase(int itheIndex) = 0;
	virtual void insert(int itheIndex, const T& theElement) = 0;
	virtual void output()const = 0;
	virtual void clear() = 0;
	virtual void push_back(const T& theElement) = 0;
protected:
	void         CheckIndex(int iTheIndex)const;
	int          m_iListSize;

};

template<class T>
void ILinearList<T>::CheckIndex(int iTheIndex) const
{
	try
	{
		if (iTheIndex < 0 || iTheIndex = >m_iListSize)
		{
			throw "iTheIndex is out Range";
		}
	}
	catch (std::string& strCheckError)
	{
		std::cout << strCheckError << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknow Error!" << std::endl;
	}
}









