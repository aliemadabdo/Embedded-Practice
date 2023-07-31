/*
 * FIFO.h
 * Circular FIFO queue deriver header
 *  Created on: Jul 31, 2023
 *      Author: ALI EMAD
 */

//protection
#ifndef FIFO_H_
#define FIFO_H_

#include <stdint.h>

#define NULL ((void *)0)

/* USER Configuration */
//Select the element data type (uint8_t,uint32_t,uintptr_t,...)
#define element_type uint32_t
//Select buffer length
#define FIFO_LENGTH 6

typedef struct {
	element_type* base;
	element_type* tail;
	element_type* head;
	int size;
}FIFO_Cbuffer_t;

typedef enum{
	NULL_STATE,
	EMPTY,
	NOT_EMPTY,
	FULL,
	NOT_FULL,
	NO_ERROR
}FIFO_state;

/* FIFO APIs */
FIFO_state init_FIFO (FIFO_Cbuffer_t* buf, element_type* UART_buffer);
FIFO_state FIFO_enqueue(FIFO_Cbuffer_t* buf, element_type element);
element_type FIFO_dequeue(FIFO_Cbuffer_t* buf);
FIFO_state FIFO_is_empty(FIFO_Cbuffer_t* buf);
FIFO_state FIFO_is_full(FIFO_Cbuffer_t* buf);
void FIFO_print(FIFO_Cbuffer_t* buf);


#endif /* FIFO_H_ */
