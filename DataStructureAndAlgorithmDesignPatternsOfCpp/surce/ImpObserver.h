///////////////////////////////////////////////////////////
//  ImpObserver.h
//  Implementation of the Interface ImpObserver
//  Created on:      14-7��-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////
#ifndef _IMP_OBSERVER_H_
#define _IMP_OBSERVER_H_

/**
 * ���е����������ʵ�ִ˹۲��߽ӿڣ���������������Ҫ֪ͨ�۲��ߵ�ʱ����һ����ͬ�ӿ�
 */
typedef struct  
{
	float fTemperature;
	float fHumidity;
	float fPressure;
}strucUpdataValue;


class ImpObserver
{

public:
	virtual ~ImpObserver() {}
	virtual void DisPlay() = 0;
	virtual void Updata(strucUpdataValue stuUpdata) =0;
	

};
#endif 