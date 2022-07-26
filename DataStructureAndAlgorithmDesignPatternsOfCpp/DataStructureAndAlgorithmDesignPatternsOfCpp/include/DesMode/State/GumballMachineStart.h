///////////////////////////////////////////////////////////
//  GumballMachineStart.h
//  Implementation of the Class GumballMachineStart
//  Created on:      26-7ÔÂ-2022 23:59:13
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_3A44427A_BFFC_41de_8457_5D2359AD25C5__INCLUDED_)
#define EA_3A44427A_BFFC_41de_8457_5D2359AD25C5__INCLUDED_
#include <string>
using namespace std;

/**
 * Summary description for GumballMachine.
 */
class GumballMachineStart
{

public:
	GumballMachineStart();
	virtual ~GumballMachineStart();

	GumballMachineStart(int count);
	string Dispense();
	string EjectQuarter();
	string InsertQuarter();
	string MachineState();
	void Refill(int newGumballs);
	string TurnCrank();

private:
	int count;
	int HAS_QUARTER;
	int NO_QUARTER;
	int SOLD;
	int SOLD_OUT;
	int state;

};
#endif // !defined(EA_3A44427A_BFFC_41de_8457_5D2359AD25C5__INCLUDED_)
