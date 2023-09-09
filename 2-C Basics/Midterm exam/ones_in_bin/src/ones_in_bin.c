/*
 ============================================================================
 Name        : ones_in_bin.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int sum = 0, input;
	scanf("%d", &input);

	while(input != 0){
		sum += input & 1;
		input = input >> 1;
	}

	printf("%d", sum);
	return 0;
}
