/*
 * DC.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Ali Emad
 */

#ifndef DCMOTOR_DC_H_
#define DCMOTOR_DC_H_

#include "state.h"

enum {
	DC_IDLE, DC_BUSY
}DC_state;

void DC_init();

STATE_DEFINE(DC_IDLE);
STATE_DEFINE(DC_BUSY);

/* global pointer to function*/
void (*DC_gpf_nextState)();

#endif /* DCMOTOR_DC_H_ */
