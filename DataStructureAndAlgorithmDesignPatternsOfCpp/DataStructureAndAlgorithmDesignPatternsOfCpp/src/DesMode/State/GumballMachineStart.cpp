///////////////////////////////////////////////////////////
//  GumballMachineStart.cpp
//  Implementation of the Class GumballMachineStart
//  Created on:      26-7ÔÂ-2022 23:59:13
//  Original author: LEGION
///////////////////////////////////////////////////////////

#include "DesMode/State/GumballMachineStart.h"


GumballMachineStart::GumballMachineStart() : count(0), HAS_QUARTER(2), NO_QUARTER(1), SOLD(3), SOLD_OUT(0), state(SOLD_OUT){

}



GumballMachineStart::~GumballMachineStart(){

}





GumballMachineStart::GumballMachineStart(int count){

}


string GumballMachineStart::Dispense(){

	return  NULL;
}


string GumballMachineStart::EjectQuarter(){

	return  NULL;
}


string GumballMachineStart::InsertQuarter(){

	return  NULL;
}


string GumballMachineStart::MachineState(){

	return  NULL;
}


void GumballMachineStart::Refill(int newGumballs){

}


string GumballMachineStart::TurnCrank(){

	return  NULL;
}