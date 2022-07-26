///////////////////////////////////////////////////////////
//  TheaterLights.h
//  Implementation of the Class TheaterLights
//  Created on:      26-7ÔÂ-2022 23:21:36
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_C9B9E0EE_AF5E_4fd3_9778_911DE62D98A9__INCLUDED_)
#define EA_C9B9E0EE_AF5E_4fd3_9778_911DE62D98A9__INCLUDED_

/**
 * Summary description for TheaterLights.
 */
class TheaterLights
{

public:
	TheaterLights();
	virtual ~TheaterLights();

	TheaterLights(string description);
	string Description();
	string Dim(int level);
	string Off();
	string On();

private:
	string description;

};
#endif // !defined(EA_C9B9E0EE_AF5E_4fd3_9778_911DE62D98A9__INCLUDED_)
