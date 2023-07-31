/*
 * main.c
 * Testing LIFO driver implementation
 *
 *  Created on: Jul 30, 2023
 *      Author: ALI EMAD
 */

#include "LIFO.h"
#include <stdio.h>

int main(){

	LIFO_Buf_t bufX;
	LIFO_init(&bufX);

	if(DEBUG) printf("PUSH to Stack \n\n");
	for (int i=0; i<BUFFER_LENGTH; i++){

		if(DEBUG) printf("Empty? %d \n",LIFO_isEmpty(&bufX));
		if(DEBUG) printf("Full? %d \n",LIFO_isFull(&bufX));

		LIFO_push(&bufX, i+99);
		if(DEBUG) printf("stack top = %d \n", *(bufX.head - 1));

	}

	if(DEBUG) printf("\n\nPOP from Stack \n\n");
	for (int i=BUFFER_LENGTH; i>=0; i--){

		if (LIFO_pop(&bufX) == NO_ERROR){
			if(DEBUG) printf("Popped value = %d \n", *(bufX.head));
		}

		if(DEBUG) printf("Empty? %d \n",LIFO_isEmpty(&bufX));
		if(DEBUG) printf("Full? %d \n",LIFO_isFull(&bufX));
	}

	return 0;
}
