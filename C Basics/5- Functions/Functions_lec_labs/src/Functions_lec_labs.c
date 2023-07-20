/*
 ============================================================================
 Name        : Functions_lec_labs.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void print_triangle(int x);

int main(void) {
	print_triangle(5);

	return 0;
}

void print_triangle(int x){
	for(int i = x; i>0; i--){
			for(int j = x-i; j<x; j++){
				printf("%d",j);
			}
			printf("\n");
		}
}
