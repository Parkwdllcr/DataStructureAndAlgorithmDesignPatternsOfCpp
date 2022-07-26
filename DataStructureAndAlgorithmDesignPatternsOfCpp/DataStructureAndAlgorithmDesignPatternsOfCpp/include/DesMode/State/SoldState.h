///////////////////////////////////////////////////////////
//  SoldState.h
//  Implementation of the Class SoldState
//  Created on:      26-7ÔÂ-2022 23:59:14
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_F2A3EBFB_3662_4350_86B2_03C307F3A4E9__INCLUDED_)
#define EA_F2A3EBFB_3662_4350_86B2_03C307F3A4E9__INCLUDED_

#include "GumballMachine.h"
#include "State.h"

/**
 * Summary description for Class1.
 */
class SoldState : public State
{

public:
	SoldState();
	virtual ~SoldState();

	SoldState(GumballMachine gumballMachine);
	string Dispense();
	string EjectQuarter();
	string InsertQuarter();
	string ToString() override;
	string TurnCrank();

private:
	GumballMachine gumballMachine;
	State* noQuarterState;
	State* soldOutState;

};
#endif // !defined(EA_F2A3EBFB_3662_4350_86B2_03C307F3A4E9__INCLUDED_)
