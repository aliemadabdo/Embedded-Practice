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

#define BATCH_ENQUEUE_1 6
#define BATCH_DEQUEUE_1 5
#define BATCH_ENQUEUE_2 3
#define BATCH_DEQUEUE_2 5

int main(void){
	printf("\n\t\t\tWelcome to FIFO circular buffer \n");

	FIFO_Cbuffer bufX;
	init_FIFO(&bufX);
	printf("Queue initialized. \n");
	printf("Queue base at 0x%p \nQueue tail at 0x%p \nQueue head at 0x%p \n",bufX.base ,bufX.tail ,bufX.head);

	for(int i=0; i<BATCH_ENQUEUE_1; i++){
		switch(FIFO_enqueue(&bufX, i+99)){
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
					printf("%d Dequeued, Queue tail at 0x%p \n",*(bufX.tail + FIFO_LENGTH) ,bufX.tail);
				else
					printf("%d Dequeued, Queue tail at 0x%p \n",*(bufX.tail - 1) ,bufX.tail);
				break;
			}
		}
	}

	for(int i=0; i<BATCH_ENQUEUE_2; i++){
		switch(FIFO_enqueue(&bufX, i+99)){
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
					printf("%d Dequeued, Queue tail at 0x%p \n",*(bufX.tail + FIFO_LENGTH) ,bufX.tail);
				else
					printf("%d Dequeued, Queue tail at 0x%p \n",*(bufX.tail - 1) ,bufX.tail);
				break;
			}
		}
	}

	return 0;
}
