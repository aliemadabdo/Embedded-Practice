/*
 * LIFO.h
 *
 *  Created on: Jul 30, 2023
 *      Author: ALI EMAD
 */

#ifndef LIFO_H_
#define LIFO_H_

#define DEBUG 1
#define BUFFER_LENGTH 5

typedef struct {
	unsigned int* base;
	unsigned int* head;
	unsigned int size;
}LIFO_Buf_t;

typedef enum {
	NULL_STATE,
	EMPTY,
	FULL,
	NO_ERROR
}buffer_state;

void LIFO_init(LIFO_Buf_t* buf);
buffer_state LIFO_push(LIFO_Buf_t* buf, int element);
buffer_state LIFO_pop(LIFO_Buf_t* buf);
_Bool LIFO_isEmpty(LIFO_Buf_t* buf);
_Bool LIFO_isFull(LIFO_Buf_t* buf);

#endif /* LIFO_H_ */
