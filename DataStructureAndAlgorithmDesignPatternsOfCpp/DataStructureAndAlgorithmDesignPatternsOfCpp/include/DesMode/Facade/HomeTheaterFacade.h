///////////////////////////////////////////////////////////
//  HomeTheaterFacade.h
//  Implementation of the Class HomeTheaterFacade
//  Created on:      26-7ÔÂ-2022 23:21:36
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_2956FF62_AB39_4748_BB49_F80DE1D2CD79__INCLUDED_)
#define EA_2956FF62_AB39_4748_BB49_F80DE1D2CD79__INCLUDED_

#include "Amplifier.h"
#include "CdPlayer.h"
#include "DvdPlayer.h"
#include "TheaterLights.h"
#include "PopcornPopper.h"
#include "Projector.h"
#include "Screen.h"
#include "Tuner.h"

/**
 * Summary description for HomeTheaterFacade.
 */
class HomeTheaterFacade
{

public:
	HomeTheaterFacade();
	virtual ~HomeTheaterFacade();

	HomeTheaterFacade(Amplifier amp, Tuner tuner, DvdPlayer dvd, CdPlayer cd, Projector projector, Screen screen, TheaterLights lights, PopcornPopper popper);
	object EndCd();
	object EndMovie();
	object EndRadio();
	object ListenToCd(string cdTitle);
	object ListenToRadio(double frequency);
	object WatchMovie(string movie);

private:
	Amplifier amp;
	CdPlayer cd;
	DvdPlayer dvd;
	TheaterLights lights;
	PopcornPopper popper;
	Projector projector;
	Screen screen;
	Tuner tuner;

};
#endif // !defined(EA_2956FF62_AB39_4748_BB49_F80DE1D2CD79__INCLUDED_)
