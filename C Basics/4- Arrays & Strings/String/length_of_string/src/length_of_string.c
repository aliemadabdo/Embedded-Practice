/*
 ============================================================================
 Name        : length_of_string.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	char text[100];
	int i = 0;

	printf("enter a string:");
	fflush(stdout);
	gets(text);


	while(text[i] != 0){
		i++;
	}
	printf("length of the string = %d",i);
	return 0;
}
