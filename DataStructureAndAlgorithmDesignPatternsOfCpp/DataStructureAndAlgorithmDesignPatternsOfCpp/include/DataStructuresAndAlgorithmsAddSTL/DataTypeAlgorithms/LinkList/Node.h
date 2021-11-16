#pragma once

#define NOT_FIND	       -4
#define LESS_THAN_ZERO     -3
#define MORE_THAN_SIZE     -2
#define UNKOWN_ERR		   -1

//Storage structure of singly linked list
typedef  struct chainNode
{
	int m_element;
	chainNode* m_next;
	chainNode() {};
	chainNode(const int element) :m_element(element) {};
	/*chainNode(const int element) { this->m_element = element; }*/
	chainNode(const int element, chainNode* nest) { this->m_element = element; this->m_next = nest; }

} * LinkListNode;