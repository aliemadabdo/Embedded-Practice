/*
 * main.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Ali Emad
 */

#include "SM.h"
#include "US.h"
#include "DC.h"

int main(void) {

	volatile int i;

	/* Setup */
	US_init();
	SM_init();
	DC_init();

	while(1){
		US_gpf_nextState();
		SM_gpf_nextState();
		DC_gpf_nextState();
		for(i = 0; i < 1000; i++); //delay
	}

	return 0;
}
