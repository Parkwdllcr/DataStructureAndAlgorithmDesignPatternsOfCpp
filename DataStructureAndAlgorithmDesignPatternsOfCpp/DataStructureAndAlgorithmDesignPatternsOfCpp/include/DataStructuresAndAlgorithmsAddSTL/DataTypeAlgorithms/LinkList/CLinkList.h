#include"ILinkList.h"


template<typename T>
class CLinkList:public ILinearList<T>
{
public:
		CLinkList(int iInitialCapacity = 10);
		CLinkList(const CLinkList<T>& theList );//copy constructor
		~CLinkList();

		//ADT
		bool    empty() const { return m_iListSize == 0; }
		int     size() const { return m_iListSize; }
		T&      get(int iTheIndex) const;
		void    erase(int iTheIndex);
		void    insert(int iTheIndex, const T& theElement);
		void    output() const;
		int     indexof(const T& theElement) const;
		void    clear();
		void    push_back(const T& theElement);

protected:
	chainNode<T>* m_firstNode;

};

//this is write by myself,please test it!
template<typename T>
void CLinkList<T>::push_back(const T& theElement)
{
	chainNode<T>* newNode = new chainNode<T>(theElement, nullptr);
	chainNode<T>* lastNode = m_firstNode;
	for (int i = 0;i<m_iListSize;++i)
	{
		lastNode = lastNode->m_next;
	}
	if (nullptr == m_firstNode)
	{
		m_firstNode = lastNode = newNode;
	}
	else
	{
		lastNode->m_next = newNode;
	}
	++m_iListSize;

}

template<typename T>
void CLinkList<T>::clear()
{
	while (nullptr != m_firstNode )
	{
		chainNode<T>* nextNode = m_firstNode->m_next;
		delete m_firstNode;
		m_firstNode = nextNode;
	}
	m_iListSize = 0;
}

template<typename T>
void CLinkList<T>::output() const
{
	chainNode<T>* currentNode = m_firstNode;
	while (nullptr != currentNode)
	{
		std::cout << currentNode->m_element << std::endl;
	}
}

template<typename T>
void CLinkList<T>::insert(int iTheIndex, const T& theElement)
{
	CheckIndex(iTheIndex);

	if (0 == iTheIndex)
	{
		m_firstNode = new chainNode<T>(theElement, m_firstNode);
	}
	else
	{
		chainNode<T>* ptr = m_firstNode;
		for (int i = 0;i<iTheIndex-1;++i)
		{
			ptr = ptr->m_next;
		}
		//after ptr ,insert theElement
		ptr->m_next = new chainNode<T>(theElement, ptr->m_next);

	}
	++m_iListSize;

}

template<typename T>
int CLinkList<T>::indexof(const T& theElement) const
{
	chainNode<T>* currentNode = m_firstNode;
	int iIndex = 0;
	while (nullptr != currentNode && currentNode->m_element != theElement)
	{
		currentNode = currentNode->m_next;
		++iIndex;
	}
	//the traversal is complete,not found
	if (nullptr == currentNode)
	{
		return -1;
	}
	else
		return iIndex;
}

template<typename T>
void CLinkList<T>::erase(int iTheIndex)
{
	CheckIndex(iTheIndex);

	chainNode<T>* deleteNode;
	if (0 == iTheIndex)
	{
		deleteNode = m_firstNode;
		m_firstNode = m_firstNode->m_next;
	}
	else
	{
		chainNode<T>* ptrTest = m_firstNode;
		for (int i = 0;i<iTheIndex-1;++i)
		{
			p = ptrTest->m_next;
		}
		deleteNode = ptrTest->m_next;
		ptrTest->m_next = ptrTest->m_next->m_next;
	}

	--m_iListSize;
	delete deleteNode;
	//I think it should be add 
	//please test it
	deleteNode = nullptr;

}

template<typename T>
T& CLinkList<T>::get(int iTheIndex) const
{
	CheckIndex(iTheIndex);

	chainNode<T>* currentNode = m_firstNode;
	for (int i =0;i<iTheIndex;++i)
	{
		currentNode = currentNode->m_next;
	}
	return currentNode->m_element;

}

//I think  Destructor is same as clear!
template<typename T>
CLinkList<T>::~CLinkList()
{
	//delete all node in list
	while (m_firstNode != nullptr)
	{
		chainNode<T>* nextNode = m_firstNode->m_next;
		delete m_firstNode;
		m_firstNode = nextNode;
	}
	m_iListSize = 0;
}


template<typename T>
CLinkList<T>::CLinkList(const CLinkList<T>& theList)
{
	m_iListSize = theList.m_iListSize;
	if (m_iListSize == 0)
	{
		m_firstNode = nullptr;
		return;
	}
	//list is diffetent from node
	//I will get frist Node element and next Node ptr
	chainNode<T>* SourceNode = theList.m_firstNode;
	m_firstNode = new chainNode<T>(SourceNode->m_element);
	chainNode<T>* targetNode = m_firstNode;

	while (SourceNode != nullptr)
	{
		targetNode->m_next = new chainNode<T>(SourceNode->m_element);
		targetNode = SourceNode->m_next;
		SourceNode = SourceNode->m_next;
	}
	targetNode->m_next = nullptr;

}

template<typename T>
CLinkList<T>::CLinkList(int iInitialCapacity /*= 10*/)
{
	try
	{
		if (iInitialCapacity<1)
		{
			throw "iInitialCapacity is less than one";
		}
	}
	m_firstNode = nullptr;
	m_iListSize = 0;
	catch (std::string& strError)
	{
		std::cout << strError << std::endl;
	}
	catch (CMemoryException* e)
	{
		std::cout << "Unknow Error!" << std::endl;
	}

}
