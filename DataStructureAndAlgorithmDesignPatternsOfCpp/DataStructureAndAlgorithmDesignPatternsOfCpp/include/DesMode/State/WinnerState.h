///////////////////////////////////////////////////////////
//  WinnerState.h
//  Implementation of the Class WinnerState
//  Created on:      26-7ÔÂ-2022 23:59:14
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_0F6A0C4F_3EE4_4dbd_BF4A_8E8902A1DE1F__INCLUDED_)
#define EA_0F6A0C4F_3EE4_4dbd_BF4A_8E8902A1DE1F__INCLUDED_

#include "GumballMachine.h"
#include "State.h"

/**
 * Summary description for WinnerState.
 */
class WinnerState : public State
{

public:
	WinnerState();
	virtual ~WinnerState();

	WinnerState(GumballMachine gumballMachine);
	string Dispense();
	string EjectQuarter();
	string InsertQuarter();
	string ToString() override;
	string TurnCrank();

private:
	GumballMachine gumballMachine;
	State noQuarterState;
	State soldOutState;

};
#endif // !defined(EA_0F6A0C4F_3EE4_4dbd_BF4A_8E8902A1DE1F__INCLUDED_)
