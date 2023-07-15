/*
 ============================================================================
 Name        : reverse_digits.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int input, reverse = 0;
	scanf("%d", &input);

	while(input != 0){
		reverse = reverse * 10 + input % 10;
		input /= 10;
	}

	printf("%d", reverse);
	return 0;
}
