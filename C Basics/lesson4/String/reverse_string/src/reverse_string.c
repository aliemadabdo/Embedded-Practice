/*
 ============================================================================
 Name        : reverse_string.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {

	char text[100];

	printf("enter a string: ");
	fflush(stdout);
	gets(text);

	printf("reversed string: ");
	for(int i=0; i<strlen(text); i++){
		printf("%c", text[strlen(text)-i-1]);
	}
	return 0;
}
