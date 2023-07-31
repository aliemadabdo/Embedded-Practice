/*
 * LIFO.c
 *
 *  Created on: Jul 30, 2023
 *      Author: ALI EMAD
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "LIFO.h"

void LIFO_init(LIFO_Buf_t* buf){

	static int arr[BUFFER_LENGTH];

	buf->size = 0;
	buf->base = arr;
	buf->head = arr;

}

buffer_state LIFO_push(LIFO_Buf_t* buf, int element){

	//check valid buffer
	if(buf->base == NULL || buf->head == NULL){
		if(DEBUG) printf("Error: Buffer is not valid \n");
		return NULL_STATE;
	}

	if(LIFO_isFull(buf)){
		if(DEBUG) printf("Error: Unable to push to a full stack \n");
		return FULL;
	}

	*(buf->head) = element;
	buf->head++;
	buf->size++;

	return NO_ERROR;
}

buffer_state LIFO_pop(LIFO_Buf_t* buf){
	//check valid buffer
	if(buf->base == NULL || buf->head == NULL){
		if(DEBUG) printf("Error: Buffer is not valid \n");
		return NULL_STATE;
	}

	if(LIFO_isEmpty(buf)){
		if(DEBUG) printf("Error: Unable to pop from an empty stack \n");
		return EMPTY; //
	}

	buf->head--;
	buf->size--;

	return NO_ERROR;
}

_Bool LIFO_isEmpty(LIFO_Buf_t* buf){
	//check valid buffer
	if(buf->base == NULL || buf->head == NULL){
		if(DEBUG) printf("Error: Buffer is not valid \n");
		return 0;
	}

	return !(buf->size);
}

_Bool LIFO_isFull(LIFO_Buf_t* buf){
	//check valid buffer
	if(buf->base == NULL || buf->head == NULL){
		if(DEBUG) printf("Error: Buffer is not valid \n");
		return 0;
	}

	if (buf->head >= (buf->base + BUFFER_LENGTH)){
		return 1;
	}
	
	return 0;
}















