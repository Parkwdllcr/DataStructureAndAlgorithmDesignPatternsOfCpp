///////////////////////////////////////////////////////////
//  Amplifier.h
//  Implementation of the Class Amplifier
//  Created on:      26-7ÔÂ-2022 23:21:35
//  Original author: LEGION
///////////////////////////////////////////////////////////

#pragma once

#include "CdPlayer.h"
#include "DvdPlayer.h"
#include "Tuner.h"
#include<string>

using namespace std;

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

