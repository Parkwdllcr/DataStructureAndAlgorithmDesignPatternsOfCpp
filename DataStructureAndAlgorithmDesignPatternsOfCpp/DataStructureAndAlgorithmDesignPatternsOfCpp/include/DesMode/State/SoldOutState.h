///////////////////////////////////////////////////////////
//  SoldOutState.h
//  Implementation of the Class SoldOutState
//  Created on:      26-7ÔÂ-2022 23:59:13
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_CF148E94_965C_4a3c_916F_71641FDF0C64__INCLUDED_)
#define EA_CF148E94_965C_4a3c_916F_71641FDF0C64__INCLUDED_

#include "GumballMachine.h"
#include "State.h"

/**
 * Summary description for SoldOutState.
 */
class SoldOutState : public State
{

public:
	SoldOutState();
	virtual ~SoldOutState();

	SoldOutState(GumballMachine gumballMachine);
	string Dispense();
	string EjectQuarter();
	string InsertQuarter();
	string ToString() override;
	string TurnCrank();

private:
	GumballMachine gumballMachine;

};
#endif // !defined(EA_CF148E94_965C_4a3c_916F_71641FDF0C64__INCLUDED_)
