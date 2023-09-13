/*
 ============================================================================
 Name        : StateMachine.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : State Machine (Rotating and Running), Ansi-style
 ============================================================================
 */

#include "state.h"
#include "SM.h"

extern int speed, distance, limit;

void SM_init(){
	printf("initializing States machine...");
	SM_gpf_nextState = STATE(ROTATING);

}

STATE_DEFINE(ROTATING){
	e_state = ROTATING; // rotating speed is zero
	speed = 0;

	(distance > limit)? ( SM_gpf_nextState = STATE(RUNNING) ) : ( SM_gpf_nextState = STATE(ROTATING) );

}

STATE_DEFINE(RUNNING){
	e_state = RUNNING;
	speed = 50;

	(distance > limit)? ( SM_gpf_nextState = STATE(RUNNING) ) : ( SM_gpf_nextState = STATE(ROTATING) );

}

			/************************************************************************* FIX **********************************************************/
//int SM_get_distance(){
//}
