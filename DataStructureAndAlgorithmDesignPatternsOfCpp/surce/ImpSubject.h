///////////////////////////////////////////////////////////
//  ImpSubject.h
//  Implementation of the Interface ImpSubject
//  Created on:      14-7��-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////

#ifndef _IMP_SUBJECT_H_
#define _IMP_SUBJECT_H_

#include "ImpObserver.h"
#include <memory>

/**
 * ����վ
 * ˵��������ӿ���
 * ����վ����ӿ����ṩ��������
 * 1. ע��۲��� RegisterObserver()
 * 2. ע���۲��� RemoveObserver()
 * 3. ֪ͨ�۲��� NotifyObserver()
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