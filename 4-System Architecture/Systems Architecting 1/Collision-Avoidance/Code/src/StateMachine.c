/*
 ============================================================================
 Name        : StateMachine.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : State Machine (Rotating and Running), Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define STATE_DEFINE(_stateFn_) void SM_##_stateFn_() //function declaration
#define STATE(_stateFn_) SM_##_stateFn_

enum {
	ROTATING, RUNNING
}e_state;

unsigned int distance, speed, limit = 50;

void (*gpf_nextState)();

STATE_DEFINE(ROTATING);
STATE_DEFINE(RUNNING);

int rand_distance(int start, int end, int amount);

int main(void) {

	volatile int i;
	gpf_nextState = STATE(ROTATING);

	while(1){
		gpf_nextState();
		for(i = 0; i < 1000; i++); //delay
	}
	return 0;
}

STATE_DEFINE(ROTATING){
	printf(" distance = %d | speed = %d | state: ROTATING ", distance, speed);

	e_state = ROTATING;
	speed = 0;
	distance = rand_distance(0, 100, 1);

	(distance > limit)? ( gpf_nextState = STATE(RUNNING) ) : ( gpf_nextState = STATE(ROTATING) );

}

STATE_DEFINE(RUNNING){
	printf(" distance = %d | speed = %d | state: RUNNING ", distance, speed);

	e_state = RUNNING;
	speed = 0;
	distance = rand_distance(0, 100, 1);

	(distance > limit)? ( gpf_nextState = STATE(RUNNING) ) : ( gpf_nextState = STATE(ROTATING) );

}

int rand_distance(int start, int end, int amount){
	int randomDistance = 0;
	for(int i = 0; i < amount; i++){
		randomDistance = (rand() % (end - start + 1)) + 1;
	}
	return randomDistance;
}
