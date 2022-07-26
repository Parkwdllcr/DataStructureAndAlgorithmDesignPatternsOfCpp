///////////////////////////////////////////////////////////
//  CafeMenuIterator.cpp
//  Implementation of the Class CafeMenuIterator
//  Created on:      26-7ÔÂ-2022 23:38:19
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/Iterator/CafeMenuIterator.h"


CafeMenuIterator::CafeMenuIterator() : menuItems(new Hashtable()), position(1){

}



CafeMenuIterator::~CafeMenuIterator(){

}





CafeMenuIterator::CafeMenuIterator(Hashtable menuItems){

}


bool CafeMenuIterator::HasNext(){

	return false;
}


object CafeMenuIterator::Next(){

	return  NULL;
}