#pragma once


//define some node

template<typename T>
struct chainNode
{
	T m_element;
	chainNode<T>* m_next;
	chainNode() {};
	chainNode(const T& element) :m_next(element), m_next(nullptr) {}
	chainNode(const T& element, chainNode<T>* nest) :m_next(element), m_next(nest) {}
	//chainNode(const T& element) { this->m_element = element; }
	//chainNode(const T& element, chainNode<T>* nest) { this->m_element = element; this->m_next = nest; }

};