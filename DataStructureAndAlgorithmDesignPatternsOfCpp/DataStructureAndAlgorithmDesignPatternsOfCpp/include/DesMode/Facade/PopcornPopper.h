///////////////////////////////////////////////////////////
//  PopcornPopper.h
//  Implementation of the Class PopcornPopper
//  Created on:      26-7ÔÂ-2022 23:21:36
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_E81598FE_0601_4248_8CA5_C68275D10FFD__INCLUDED_)
#define EA_E81598FE_0601_4248_8CA5_C68275D10FFD__INCLUDED_

/**
 * Summary description for PopcornPopper.
 */
class PopcornPopper
{

public:
	PopcornPopper();
	virtual ~PopcornPopper();

	PopcornPopper(string description);
	string Description();
	string Off();
	string On();
	string Pop();

private:
	string description;

};
#endif // !defined(EA_E81598FE_0601_4248_8CA5_C68275D10FFD__INCLUDED_)
