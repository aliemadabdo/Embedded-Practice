/*
 * CA.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Mega Store
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#define STATE_DEFINE(_stateFn_) void SM_##_stateFn_() //function declaration
#define STATE(_stateFn_) SM_##_stateFn_

enum {
	ROTATING, RUNNING
}enum_state;

#endif /* STATEMACHINE_H_ */
