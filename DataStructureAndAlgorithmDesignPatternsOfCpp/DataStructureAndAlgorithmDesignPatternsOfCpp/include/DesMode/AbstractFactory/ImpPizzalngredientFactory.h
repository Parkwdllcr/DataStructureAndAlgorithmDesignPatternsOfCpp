///////////////////////////////////////////////////////////
//  ImpPizzalngredientFactory.h
//  Implementation of the Interface ImpPizzalngredientFactory
//  Created on:      18-7��-2022 19:09:31
//  Original author: chongrui.lu
///////////////////////////////////////////////////////////

#ifndef _IMP_PIZZA_LNGREDIENT_FACTORY_H_
#define _IMP_PIZZA_LNGREDIENT_FACTORY_H_
/**
 * ������ԭ�Ϲ���
 * 
 * ԭ��Ҳ�ǳ���,���ݲ�ͬ������ң�������ͬ��ԭ��
 * 
 * ԭ�ϰ�����
 * 1. ����Dough
 * 2. ����Cheese
 * 3. ��Clam
 */

#include "ImpCheese.h"
#include "ImpClam.h"
#include "ImpDough.h"

class ImpPizzalngredientFactory
{
public:
	virtual ImpCheese* CreatCheese() =0;
	virtual ImpClam* CreateClam() =0;
	virtual ImpDough* CreateDough() =0;
	virtual ~ImpPizzalngredientFactory() {}
};
#endif
