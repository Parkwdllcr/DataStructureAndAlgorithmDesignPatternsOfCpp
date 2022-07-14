///////////////////////////////////////////////////////////
//  ImpObserver.h
//  Implementation of the Interface ImpObserver
//  Created on:      14-7月-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////
#ifndef _IMP_OBSERVER_H_
#define _IMP_OBSERVER_H_

/**
 * 所有的气象组件都实现此观察者接口，这样，主题在需要通知观察者的时候，有一个共同接口
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