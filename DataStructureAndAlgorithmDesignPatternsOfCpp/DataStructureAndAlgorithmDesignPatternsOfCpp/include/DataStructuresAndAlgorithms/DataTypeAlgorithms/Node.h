#pragma once

#define NOT_FIND	       -4
#define LESS_THAN_ZERO     -3
#define MORE_THAN_SIZE     -2
#define UNKOWN_ERR		   -1

enum RBTColor{RED,BLACK};

//Storage structure of singly linked list
typedef  struct chainNode
{
	int m_element;
	chainNode* m_next;
	chainNode() {};
	chainNode(const int element) :m_element(element) {};
	chainNode(const int element, chainNode* nest) { this->m_element = element; this->m_next = nest; }

} * LinkListNode;


template<class T>
struct RBTNode {
	RBTColor m_color;
	T        m_key;
	RBTNode* m_pLeftChild;
	RBTNode* m_pRightChild;
	RBTNode* m_pParent;

	RBTNode(T value, RBTColor color, RBTNode* pParent, RBTNode* pLeftChild, RBTNode* pRightChild) :m_key(value), m_color(color)
		, m_pParent(pParent), m_pLeftChild(pLeftChild), m_pRightChild(pRightChild) {}

};