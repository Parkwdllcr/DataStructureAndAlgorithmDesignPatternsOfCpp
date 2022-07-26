///////////////////////////////////////////////////////////
//  GumballMachine.h
//  Implementation of the Class GumballMachine
//  Created on:      26-7ÔÂ-2022 23:59:13
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_DF4CADCF_D179_4146_BCFD_7C63F65D2E7E__INCLUDED_)
#define EA_DF4CADCF_D179_4146_BCFD_7C63F65D2E7E__INCLUDED_

#include "State.h"
#include <string>
using namespace std;

/**
 * Summary description for GumballMachine.
 */
class GumballMachine
{

public:
	GumballMachine();
	virtual ~GumballMachine();

	GumballMachine(int numberOfGumballs);
	int Count();
	string EjectQuarter();
	string InsertQuarter();
	string MachineStateHeader();
	string Refill(int numberOfGumballs);
	string ReleaseBall();
	State StateOfMachine();
	string TurnCrank();

private:
	int count;
	State* hasQuarterState;
	State* noQuarterState;
	State* soldOutState;
	State* soldState;
	State* state;

};
#endif // !defined(EA_DF4CADCF_D179_4146_BCFD_7C63F65D2E7E__INCLUDED_)
