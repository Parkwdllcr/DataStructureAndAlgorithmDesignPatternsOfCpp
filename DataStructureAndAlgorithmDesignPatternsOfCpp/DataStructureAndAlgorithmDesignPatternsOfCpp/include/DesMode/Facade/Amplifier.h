///////////////////////////////////////////////////////////
//  Amplifier.h
//  Implementation of the Class Amplifier
//  Created on:      26-7ÔÂ-2022 23:21:35
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_BD65B812_5E2E_426c_9068_F0BC627A5AC0__INCLUDED_)
#define EA_BD65B812_5E2E_426c_9068_F0BC627A5AC0__INCLUDED_

#include "CdPlayer.h"
#include "DvdPlayer.h"
#include "Tuner.h"

/**
 * Summary description for Amplifier.
 */
class Amplifier
{

public:
	Amplifier();
	virtual ~Amplifier();

	Amplifier(string description);
	string Description();
	string Off();
	string On();
	string SetCd(CdPlayer cd);
	string SetDvd(DvdPlayer dvd);
	string SetStereoSound();
	string SetSurroundSound();
	string SetTuner(Tuner tuner);
	string SetVolume(int level);

private:
	CdPlayer cd;
	string description;
	DvdPlayer dvd;
	Tuner tuner;

};
#endif // !defined(EA_BD65B812_5E2E_426c_9068_F0BC627A5AC0__INCLUDED_)
