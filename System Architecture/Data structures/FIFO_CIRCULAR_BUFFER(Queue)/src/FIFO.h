/*
 * FIFO.h
 * Circular FIFO queue deriver header
 *  Created on: Jul 31, 2023
 *      Author: ALI EMAD
 */

//protection
#ifndef FIFO_H_
#define FIFO_H_

#define NULL ((void *)0)
#define uintp_t unsigned int*
#define uint_t unsigned int

#define FIFO_LENGTH 6

typedef struct {
	uintp_t base;
	uintp_t tail;
	uintp_t head;
	uint_t size;
}FIFO_Cbuffer;

typedef enum{
	NULL_STATE,
	EMPTY,
	NOT_EMPTY,
	FULL,
	NOT_FULL,
	NO_ERROR
}FIFO_state;

void init_FIFO (FIFO_Cbuffer* buf);
FIFO_state FIFO_enqueue(FIFO_Cbuffer* buf, int element);
int FIFO_dequeue(FIFO_Cbuffer* buf);
FIFO_state FIFO_is_empty(FIFO_Cbuffer* buf);
FIFO_state FIFO_is_full(FIFO_Cbuffer* buf);


#endif /* FIFO_H_ */
