/*
 * US.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Ali Emad
 */

#ifndef ULTRASONIC_US_H_
#define ULTRASONIC_US_H_

#include "state.h"

enum{
	READING
}US_state;

/* APIs */
void US_init();
int US_randDist(int start, int end, int amount);

STATE_DEFINE(READING);

/* global pointer to function read distance*/
void (*US_gpf_nextState)(void);

#endif /* ULTRASONIC_US_H_ */
