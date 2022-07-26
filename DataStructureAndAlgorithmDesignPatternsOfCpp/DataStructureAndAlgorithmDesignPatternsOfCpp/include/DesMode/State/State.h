///////////////////////////////////////////////////////////
//  State.h
//  Implementation of the Interface State
//  Created on:      26-7ÔÂ-2022 23:59:14
//  Original author: LEGION
///////////////////////////////////////////////////////////

#if !defined(EA_D1081FA5_95C6_4990_949F_325209C843A2__INCLUDED_)
#define EA_D1081FA5_95C6_4990_949F_325209C843A2__INCLUDED_

/**
 * Summary description for State.
 */
class State
{

public:
	State() {

	}

	virtual ~State() {

	}

	virtual string Dispense() =0;
	virtual string EjectQuarter() =0;
	virtual string InsertQuarter() =0;
	virtual string TurnCrank() =0;

};
#endif // !defined(EA_D1081FA5_95C6_4990_949F_325209C843A2__INCLUDED_)
