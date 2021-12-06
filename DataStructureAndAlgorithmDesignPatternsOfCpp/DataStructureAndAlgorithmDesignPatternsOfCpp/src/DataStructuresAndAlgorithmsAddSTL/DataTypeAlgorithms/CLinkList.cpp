#include "DataStructuresAndAlgorithmsAddSTL/DataTypeAlgorithms/CLinkList.h"

//CLinkList::CLinkList(const CLinkList& theList)
//{
//	CLinearList::m_iListSize = theList.m_iListSize;
//	m_pPublicClass = new CPublicClass;
//
//	if (CLinearList::m_iListSize == 0)
//	{
//		m_firstNode = nullptr;
//		return;
//	}
//	//list is diffetent from node
//	//I will get frist Node element and next Node ptr
//	LinkListNode SourceNode = theList.m_firstNode;
//	m_firstNode = new chainNode(SourceNode->m_element);
//	LinkListNode targetNode = m_firstNode;
//
//	while (SourceNode != nullptr)
//	{
//		targetNode->m_next = new chainNode(SourceNode->m_element);
//		targetNode = SourceNode->m_next;
//		SourceNode = SourceNode->m_next;
//	}
//	targetNode->m_next = nullptr;
//}

CLinkList::CLinkList(int iInitialSize /*= 10*/,enCREAT_WAY enCreatWay /*= TAIL_INSERTION*/ )
{
	try
	{
		if (iInitialSize < 1)
		{
			throw "iInitialCapacity less than 1";
		}
		//initlist
		m_pPublicClass = new CPublicClass;
		m_firstNode = new chainNode(0, nullptr);
		CLinearList::m_iListSize = iInitialSize;
		//creat a list by a way
		switch (enCreatWay)
		{
			LinkListNode NewNode;
		case HEAD_INSERTION:
		{
			for (int i = iInitialSize - 1; i != 0; i--)
			{
				NewNode = new chainNode(i, nullptr);
				NewNode->m_next = m_firstNode->m_next;
				m_firstNode->m_next = NewNode;
			}
			break;
		}
		case TAIL_INSERTION:
		{
			LinkListNode qTestNode = m_firstNode;
			for (int i = 1; i != iInitialSize; i++)
			{
				NewNode = new chainNode(i, nullptr);
				qTestNode->m_next = NewNode;
				qTestNode = NewNode;
			}
			break;
		}
		default:
			throw "input a wrong Creat way";
			break;
		}
		
	}

	catch (const char* pStrError)
	{
		std::cout << pStrError << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknow Error!" << std::endl;
	}

}

//I think  Destructor is same as clear!
CLinkList::~CLinkList()
{
	if (nullptr != m_pPublicClass)
	{
		delete m_pPublicClass;
		m_pPublicClass = nullptr;
	}
	//delete all node in list
	while (m_firstNode != nullptr)
	{
		LinkListNode nextNode = m_firstNode->m_next;
		delete m_firstNode;
		m_firstNode = nextNode;
	}
	CLinearList::m_iListSize = 0;
}


//by Tail inserttion push back
void CLinkList::push_back(const int theElement)
{
	
	m_pPublicClass->PrintfTestFunctionFlag("void CLinkList::push_back(const int theElement)");
	LinkListNode newNode = new chainNode(theElement, nullptr);
	LinkListNode lastNode = m_firstNode;


	if (nullptr == m_firstNode)
	{
		m_firstNode = newNode;
	}
	else
	{
		//get the last node adress
		for (int i =0; i != CLinearList::m_iListSize-1;++i)
		{
			lastNode = lastNode->m_next;
		}
		//set the last node address(nullptr) as new node address
		lastNode->m_next = newNode;
	}
	++CLinearList::m_iListSize;

}

void CLinkList::clear()
{
	while (nullptr != m_firstNode)
	{
		LinkListNode nextNode = m_firstNode->m_next;
		delete m_firstNode;
		m_firstNode = nextNode;
	}
	CLinearList::m_iListSize = 0;
}


void CLinkList::output() const
{
	m_pPublicClass->PrintfTestFunctionFlag("void CLinkList::output() const");
	LinkListNode currentNode = m_firstNode;
	while (nullptr != currentNode)
	{
		std::cout << currentNode->m_element << std::endl;
		currentNode = currentNode->m_next;
	}
}
//
void CLinkList::insert(int iTheIndex, const int theElement)
{
	m_pPublicClass->PrintfTestFunctionFlag("void CLinkList::insert(int iTheIndex, const int theElement)");
	try
	{
		if (CheckIndex(iTheIndex)<0)
		{
			throw "input a wrong iTheIndex ,please input right ";
		}
		if (0 == iTheIndex)
		{
			m_firstNode = new chainNode(theElement,m_firstNode);
		}
		else
		{
			LinkListNode InsertedNode = m_firstNode;
			for (int i = 0; i != iTheIndex - 1; i++)
			{
				InsertedNode = InsertedNode->m_next;
			}
			InsertedNode->m_next = new chainNode(theElement, InsertedNode->m_next);
		}

		++CLinearList::m_iListSize;
	}
	catch (const char* pChar)
	{
		std::cout << pChar << std::endl;
	}
	catch (...)
	{
		std::cout << "UnKown Err!" << std::endl;
	}

}


int CLinkList::indexof(const int theElement) const
{
	m_pPublicClass->PrintfTestFunctionFlag("int CLinkList::indexof(const int theElement) const");
	try
	{
		LinkListNode currentNode = m_firstNode;
		int iIndex = 0;
		while (nullptr != currentNode && currentNode->m_element != theElement)
		{
			currentNode = currentNode->m_next;
			++iIndex;
		}
		//the traversal is complete,not found
		if (nullptr == currentNode)
		{
			throw "the traversal is complete,not found ";
		}
		else
			return iIndex;
	}
	catch (const char* pStrErr)
	{
		std::cout << pStrErr << std::endl;
		return NOT_FIND;
	}
	catch (...)
	{
		return UNKOWN_ERR;
	}

	
}


void CLinkList::erase(int iTheIndex)
{
	m_pPublicClass->PrintfTestFunctionFlag("void CLinkList::erase(int iTheIndex)");
	if (CheckIndex(iTheIndex) < 0)
	{
		return;
	}

	LinkListNode deleteNode;
	if (0 == iTheIndex)
	{
		deleteNode = m_firstNode;
		m_firstNode = m_firstNode->m_next;
	}
	else
	{
		LinkListNode PrecuresorNode = m_firstNode;
		//for (int i = 0; (i<(iTheIndex-1)&& (nullptr != PrecuresorNode->m_next)); ++i)
		for (int i = 0; i < (iTheIndex - 1); ++i)
		{
			PrecuresorNode = PrecuresorNode->m_next;
		}
		deleteNode = PrecuresorNode->m_next;
		PrecuresorNode->m_next = deleteNode->m_next;
	}
	--CLinearList::m_iListSize;	
}

int CLinkList::get(int iTheIndex) 
{
	m_pPublicClass->PrintfTestFunctionFlag("int CLinkList::get(int iTheIndex) const");
	int iError = CheckIndex(iTheIndex);
	if (iError <0)
	{
		return iError;
	}
	else
	{
		LinkListNode currentNode = m_firstNode;
		for (int i = 0; i < iTheIndex; ++i)
		{
			currentNode = currentNode->m_next;
		}
		return currentNode->m_element;
	}
}





