/*
 * FIFO.c
 * Circular FIFO queue deriver implemention
 *  Created on: Jul 31, 2023
 *      Author: ALI EMAD
 */
#include "FIFO.h"
#include <stdio.h>

FIFO_state init_FIFO (FIFO_Cbuffer_t* buf, element_type* UART_buffer){

	if (UART_buffer == NULL)
		return NULL_STATE;

	buf->base = UART_buffer;
	buf->tail = UART_buffer;
	buf->head = UART_buffer;
	buf->size = 0;

	return NO_ERROR;
}

FIFO_state FIFO_enqueue(FIFO_Cbuffer_t* buf, element_type element){
	//check valid buffer
	if (buf->base == NULL)
		return NULL_STATE;

	if (FIFO_is_full(buf) == FULL )
		return FULL;

	//circularity
	if (buf->head == (buf->base + FIFO_LENGTH - 1)){
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

element_type FIFO_dequeue(FIFO_Cbuffer_t* buf){
	//check valid buffer
	if (buf->base == NULL)
		return NULL_STATE;

	if (FIFO_is_empty(buf) == EMPTY )
		return EMPTY;

	//circularity
	if (buf->tail == (buf->base + FIFO_LENGTH - 1)){
		buf->tail = buf->base;
		buf->size--;

		return *(buf->tail + FIFO_LENGTH - 1);
	}

	buf->tail++;
	buf->size--;

	return *(buf->tail - 1);
}

FIFO_state FIFO_is_empty(FIFO_Cbuffer_t* buf){
	//check valid buffer
	if (buf->base == NULL)
		return NULL_STATE;

	if ( buf->size == 0 )
		return EMPTY;

	return NOT_EMPTY;
}

FIFO_state FIFO_is_full(FIFO_Cbuffer_t* buf){
	//check valid buffer
	if (buf->base == NULL)
		return NULL_STATE;

	if ( buf->size == FIFO_LENGTH )
		return FULL;

	return NOT_FULL;
}

void FIFO_print(FIFO_Cbuffer_t* buf){
	if(buf->base == NULL)
		return;

	element_type* temp = buf->tail;
	int loc_num = 0;

	printf("\n\t\t\t FIFO Content\n");

	for(int i=0; i<buf->size; i++){
		loc_num = (temp - buf->base) ;

		printf("location[%d] = %d , address : 0x%p \n",loc_num, *temp, temp );

		if ( temp == (buf->base + FIFO_LENGTH - 1) )
			temp = buf->base;
		else
			temp++;
	}

	printf("\t\t------DONE Printing----\n");

}
