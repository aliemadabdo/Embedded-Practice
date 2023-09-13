/*
 * state.h
 *
 *  Created on: Sep 11, 2023
 *      Author: Mega Store
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

#define STATE_DEFINE(_stateFn_) void SM_##_stateFn_() //function declaration
#define STATE(_stateFn_) SM_##_stateFn_

int SM_get_distance();
void DC_set_speed(int s);


#endif /* STATE_H_ */
