///////////////////////////////////////////////////////////
//  DvdPlayer.h
//  Implementation of the Class DvdPlayer
//  Created on:      26-7ÔÂ-2022 23:21:36
//  Original author: LEGION
///////////////////////////////////////////////////////////
#pragma once

#include "Amplifier.h"

/**
 * Summary description for DvdPlayer.
 */
class DvdPlayer
{

public:
	DvdPlayer();
	virtual ~DvdPlayer();

	DvdPlayer(string description, Amplifier amplifier);
	string Description();
	string Eject();
	string Off();
	string On();
	string Pause();
	string Play(string movie);
	string Play(int track);
	string SetSurroundAudio();
	string SetTwoChannelAudio();
	string Stop();

private:
	Amplifier amplifier;
	int currentTrack;
	string description;
	string movie;

};

