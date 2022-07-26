///////////////////////////////////////////////////////////
//  Screen.h
//  Implementation of the Class Screen
//  Created on:      26-7ÔÂ-2022 23:21:36
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_DA88D07A_BCC8_4a13_A7B5_9D6CF52F9D6E__INCLUDED_)
#define EA_DA88D07A_BCC8_4a13_A7B5_9D6CF52F9D6E__INCLUDED_

/**
 * Summary description for Screen.
 */
class Screen
{

public:
	Screen();
	virtual ~Screen();

	Screen(string description);
	string Description();
	string Down();
	string Up();

private:
	string description;

};
#endif // !defined(EA_DA88D07A_BCC8_4a13_A7B5_9D6CF52F9D6E__INCLUDED_)
