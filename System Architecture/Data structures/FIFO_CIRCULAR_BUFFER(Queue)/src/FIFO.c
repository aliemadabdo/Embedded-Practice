/*
 * FIFO.c
 * Circular FIFO queue deriver implemention
 *  Created on: Jul 31, 2023
 *      Author: ALI EMAD
 */
#include "FIFO.h"

void init_FIFO (FIFO_Cbuffer* buf){
	static uint_t arr[FIFO_LENGTH];

	buf->base =arr;
	buf->tail =arr;
	buf->head =arr;
	buf->size = 0;
}

FIFO_state FIFO_enqueue(FIFO_Cbuffer* buf, int element){
	//check valid buffer
	if (buf->base == NULL)
		return NULL_STATE;

	if (FIFO_is_full(buf) == FULL )
		return FULL;

	//circularity
	if (buf->head == (buf->base + FIFO_LENGTH)){
		*(buf->head) = element;
		buf->head = buf->base;
		buf->size++;
		return NO_ERROR;
	}

	*(buf->head) = element;
	buf->head++;
	buf->size++;

	return NO_ERROR;
}

int FIFO_dequeue(FIFO_Cbuffer* buf){
	//check valid buffer
	if (buf->base == NULL)
		return NULL_STATE;

	if (FIFO_is_empty(buf) == EMPTY )
		return EMPTY;

	//circularity
		if (buf->tail == (buf->base + FIFO_LENGTH)){
			buf->tail = buf->base;
			buf->size--;
			return *(buf->tail + FIFO_LENGTH);
		}

	buf->tail++;
	buf->size--;

	return *(buf->tail - 1);
}

FIFO_state FIFO_is_empty(FIFO_Cbuffer* buf){
	//check valid buffer
	if (buf->base == NULL)
		return NULL_STATE;

	if ( buf->size == 0 )
		return EMPTY;

	return NOT_EMPTY;
}

FIFO_state FIFO_is_full(FIFO_Cbuffer* buf){
	//check valid buffer
	if (buf->base == NULL)
		return NULL_STATE;

	if ( buf->size == FIFO_LENGTH )
		return FULL;

	return NOT_FULL;
}

