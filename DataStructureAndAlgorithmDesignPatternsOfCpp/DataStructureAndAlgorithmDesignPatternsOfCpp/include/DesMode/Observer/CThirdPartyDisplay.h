///////////////////////////////////////////////////////////
//  CThirdPartyDisplay.h
//  Implementation of the Class CThirdPartyDisplay
//  Created on:      14-7ÔÂ-2022 9:37:14
//  Original author: Administrator
///////////////////////////////////////////////////////////

#ifndef _THIRD_PARTY_DISPLAY_H_
#define _THIRD_PARTY_DISPLAY_H_

#include "ImpObserver.h"
#include <memory>

class ImpSubject;
class CThirdPartyDisplay : public ImpObserver
{

public:
	CThirdPartyDisplay();
	CThirdPartyDisplay(ImpSubject*   pSubject);
	virtual ~CThirdPartyDisplay();

	void DisPlay();
	void Updata(strucUpdataValue stuUpdata);
private:

	float                             m_fPress;
	ImpSubject*                       m_pSubject;

};
#endif // !defined(EA_9D6E16CD_3F0C_4466_980A_620F5F4C3D2F__INCLUDED_)
