///////////////////////////////////////////////////////////
//  Tuner.h
//  Implementation of the Class Tuner
//  Created on:      26-7ÔÂ-2022 23:21:36
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_0CC3D475_B25F_4c4f_97A7_BB41D95A532D__INCLUDED_)
#define EA_0CC3D475_B25F_4c4f_97A7_BB41D95A532D__INCLUDED_

#include "Amplifier.h"

/**
 * Summary description for Tuner.
 */
class Tuner
{

public:
	Tuner();
	virtual ~Tuner();

	Tuner(string description, Amplifier amplifier);
	string Description();
	string Off();
	string On();
	string SetAm();
	string SetFm();
	string SetFrequency(double frequency);

private:
	string description;
	double frequency;

};
#endif // !defined(EA_0CC3D475_B25F_4c4f_97A7_BB41D95A532D__INCLUDED_)
