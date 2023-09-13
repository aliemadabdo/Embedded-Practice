/*
 * CA.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Mega Store
 */

#ifndef SM_H_
#define SM_H_

#include "state.h"

enum {
	ROTATING, RUNNING
}e_state;


void SM_init();

STATE_DEFINE(ROTATING);
STATE_DEFINE(RUNNING);

void (*SM_gpf_nextState)();


#endif /* SM_H_ */
