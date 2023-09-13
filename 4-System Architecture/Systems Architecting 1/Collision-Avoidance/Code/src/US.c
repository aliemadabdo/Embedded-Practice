/*
 * US.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Ali Emad
 */
#include "US.h"

int distance, limit = 50;


void US_init(){
	printf("Initializing Sensors...");
	US_gpf_nextState = STATE(READING);

}

STATE_DEFINE(READING){
	US_state = READING;
	distance = US_randDist(0, 100, 1);
//	US_gpf_readDistance = STATE(READING);
//	SM_set_distance(distance);
	printf("Sensor Reading state\n");

}


int US_randDist(int start, int end, int amount){
	int randomDistance = 0;
	for(int i = 0; i < amount; i++){
		randomDistance = (rand() % (end - start + 1)) + 1;
	}
	return randomDistance;
}


