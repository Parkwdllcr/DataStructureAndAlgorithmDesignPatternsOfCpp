///////////////////////////////////////////////////////////
//  CdPlayer.h
//  Implementation of the Class CdPlayer
//  Created on:      26-7ÔÂ-2022 23:21:36
//  Original author: LEGION
///////////////////////////////////////////////////////////

#pragma once

#include "Amplifier.h"

/**
 * Summary description for CdPlayer.
 */
class CdPlayer
{

public:
	CdPlayer();
	virtual ~CdPlayer();

	CdPlayer(string description, Amplifier amplifier);
	string Description();
	string Eject();
	string Off();
	string On();
	string Pause();
	string Play(string title);
	string Play(int track);
	string Stop();

private:
	Amplifier amplifier;
	int currentTrack;
	string description;
	string title;

};
#endif // !defined(EA_FA415167_D2D2_4798_8396_0375595A8FB4__INCLUDED_)
