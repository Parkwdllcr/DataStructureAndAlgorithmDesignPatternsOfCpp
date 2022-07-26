///////////////////////////////////////////////////////////
//  NoQuarterState.h
//  Implementation of the Class NoQuarterState
//  Created on:      26-7ÔÂ-2022 23:59:13
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_32D01A4A_7B0A_4108_9610_BC019922DE85__INCLUDED_)
#define EA_32D01A4A_7B0A_4108_9610_BC019922DE85__INCLUDED_

#include "GumballMachine.h"
#include "State.h"

/**
 * Summary description for NoQuarterState.
 */
class NoQuarterState : public State
{

public:
	NoQuarterState();
	virtual ~NoQuarterState();

	NoQuarterState(GumballMachine gumballMachine);
	string Dispense();
	string EjectQuarter();
	string InsertQuarter();
	string ToString() override;
	string TurnCrank();

private:
	GumballMachine gumballMachine;
	State* hasQuarterState;

};
#endif // !defined(EA_32D01A4A_7B0A_4108_9610_BC019922DE85__INCLUDED_)
