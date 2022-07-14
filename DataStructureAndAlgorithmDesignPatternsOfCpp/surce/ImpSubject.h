///////////////////////////////////////////////////////////
//  ImpSubject.h
//  Implementation of the Interface ImpSubject
//  Created on:      14-7月-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////

#ifndef _IMP_SUBJECT_H_
#define _IMP_SUBJECT_H_

#include "ImpObserver.h"
#include <memory>

/**
 * 气象站
 * 说明：主题接口类
 * 气象站主题接口类提供三个方法
 * 1. 注册观察者 RegisterObserver()
 * 2. 注销观察者 RemoveObserver()
 * 3. 通知观察者 NotifyObserver()
 */

class  ImpObserver;

class ImpSubject
{

public:
	ImpSubject() {

	}

	virtual ~ImpSubject() {

	}

	virtual void NotifyObservers() =0;
	virtual void RegisterObserver(ImpObserver* pObserver) =0;
	virtual void RemoveObserver(ImpObserver* pObserver) =0;

};
#endif 