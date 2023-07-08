/*
 ============================================================================
 Name        : U2Lec3Labs.c
 Author      : ali emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {
 	printf("Hello from main function\n\n");

	/* LAB 5
	 * A program to print numbers from 1 to 9 as triangle with nested for loop */
	for(int i = 10; i>0; i--){
		for(int j = 10-i; j<10; j++){
			printf("%d",j);
		}
		printf("\n");
	}
	return 0;
}

