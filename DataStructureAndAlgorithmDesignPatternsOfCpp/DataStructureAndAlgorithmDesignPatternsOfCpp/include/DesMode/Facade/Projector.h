///////////////////////////////////////////////////////////
//  Projector.h
//  Implementation of the Class Projector
//  Created on:      26-7ÔÂ-2022 23:21:36
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_2D545828_8502_41bf_A7F1_8CB57F284C22__INCLUDED_)
#define EA_2D545828_8502_41bf_A7F1_8CB57F284C22__INCLUDED_

#include "DvdPlayer.h"

/**
 * Summary description for Projector.
 */
class Projector
{

public:
	Projector();
	virtual ~Projector();

	Projector(string description, DvdPlayer dvdPlayer);
	string Description();
	string Off();
	string On();
	string TvMode();
	string WideScreenMode();

private:
	string description;
	DvdPlayer dvdPlayer;

};
#endif // !defined(EA_2D545828_8502_41bf_A7F1_8CB57F284C22__INCLUDED_)
