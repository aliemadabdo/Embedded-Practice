/*
 ============================================================================
 Name        : FIFO_CIRCULAR_BUFFER(Queue).c
 Author      : Ali Emad
 Version     : V1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "FIFO.h"

#define BATCH_ENQUEUE_1 9
#define BATCH_DEQUEUE_1 5
#define BATCH_ENQUEUE_2 3
#define BATCH_DEQUEUE_2 7

int main(void){
	printf("\n\t\t\tWelcome to FIFO circular buffer \n");

	element_type UART_buffer[FIFO_LENGTH];
	FIFO_Cbuffer_t bufX;

	switch( init_FIFO(&bufX, UART_buffer) ){
			case NULL_STATE:{
				printf("ERROR?: Invalid buffer or structure. \n");
				break;
			}
			case NO_ERROR:{
				printf("Queue initialized successfully. \n");
				break;
			}
	}

	printf("Queue base at 0x%p \nQueue tail at 0x%p \nQueue head at 0x%p \n",bufX.base ,bufX.tail ,bufX.head);

	FIFO_print(&bufX);

//BATCH_ENQUEUE_1
	for(element_type i=0; i<BATCH_ENQUEUE_1; i++){
		switch(FIFO_enqueue(&bufX, (element_type)(i+99) )){
			case NULL_STATE:{
				printf("ERROR?: Invalid FIFO initialization. \n");
				break;
			}
			case FULL:{
				printf("ERROR?: Can not enqueue to a full FIFO. \n");
				break;
			}
			case NO_ERROR:{
				printf("%d Enqueued, Queue head at 0x%p \n",i+99 ,bufX.head);
				break;
			}
		}
	}
	FIFO_print(&bufX);

//BATCH_DEQUEUE_1
	for(int i=0; i<BATCH_DEQUEUE_1; i++){
		switch(FIFO_dequeue(&bufX)){
			case NULL_STATE:{
				printf("ERROR?: Invalid FIFO initialization. \n");
				break;
			}
			case EMPTY:{
				printf("ERROR?: Can not dequeue from an empty FIFO. \n");
				break;
			}
			default:{
				if(bufX.base == bufX.tail)
					printf("%d Dequeued, Queue tail at 0x%p \n",*(bufX.tail + FIFO_LENGTH - 1) ,bufX.tail);
				else
					printf("%d Dequeued, Queue tail at 0x%p \n",*(bufX.tail - 1) ,bufX.tail);
				break;
			}
		}
	}
	FIFO_print(&bufX);

//BATCH_ENQUEUE_2
	for(element_type i=0; i<BATCH_ENQUEUE_2; i++){
		switch(FIFO_enqueue(&bufX, (element_type)(i+99) )){
			case NULL_STATE:{
				printf("ERROR?: Invalid FIFO initialization. \n");
				break;
			}
			case FULL:{
				printf("ERROR?: Can not enqueue to a full FIFO. \n");
				break;
			}
			case NO_ERROR:{
				printf("%d Enqueued, Queue head at 0x%p \n",i+99 ,bufX.head);
				break;
			}
		}
	}
	FIFO_print(&bufX);

//BATCH_DEQUEUE_2
	for(int i=0; i<BATCH_DEQUEUE_2; i++){
		switch(FIFO_dequeue(&bufX)){
			case NULL_STATE:{
				printf("ERROR?: Invalid FIFO initialization. \n");
				break;
			}
			case EMPTY:{
				printf("ERROR?: Can not dequeue from an empty FIFO. \n");
				break;
			}
			default:{
				if(bufX.base == bufX.tail)
					printf("%d Dequeued, Queue tail at 0x%p \n",*(bufX.tail + FIFO_LENGTH - 1) ,bufX.tail);
				else
					printf("%d Dequeued, Queue tail at 0x%p \n",*(bufX.tail - 1) ,bufX.tail);
				break;
			}
		}
	}
	FIFO_print(&bufX);

	printf("===========================Done Testing========================");

	return 0;
}
