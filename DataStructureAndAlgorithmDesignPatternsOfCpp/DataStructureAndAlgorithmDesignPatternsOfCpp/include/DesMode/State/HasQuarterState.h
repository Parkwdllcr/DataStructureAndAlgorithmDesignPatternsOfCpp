///////////////////////////////////////////////////////////
//  HasQuarterState.h
//  Implementation of the Class HasQuarterState
//  Created on:      26-7ÔÂ-2022 23:59:13
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_E59B36F3_1432_4539_802A_387DE2338BA0__INCLUDED_)
#define EA_E59B36F3_1432_4539_802A_387DE2338BA0__INCLUDED_

#include "GumballMachine.h"
#include "State.h"

/**
 * Summary description for HasQuarterState.
 */
class HasQuarterState : public State
{

public:
	HasQuarterState();
	virtual ~HasQuarterState();

	HasQuarterState(GumballMachine gumballMachine);
	string Dispense();
	string EjectQuarter();
	string InsertQuarter();
	string ToString() override;
	string TurnCrank();

private:
	GumballMachine gumballMachine;
	Random randomWinner;

};
#endif // !defined(EA_E59B36F3_1432_4539_802A_387DE2338BA0__INCLUDED_)
