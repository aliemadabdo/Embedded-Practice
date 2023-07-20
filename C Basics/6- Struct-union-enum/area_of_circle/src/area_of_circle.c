/*
 ============================================================================
 Name        : area_of_circle.c
 Author      : Ali Emad
 Version     : Exercise 5 & 6
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define PI 3.14159265358979323846264338327

#define area(r) (PI *(r)*(r))  //passing arguments to macro

int main(void) {

	float r;

	printf("Enter radius: ");
	fflush(stdout);
	scanf("%f", &r);

	printf("%f", area(r));
	return 0;
}

// Exercise 6: Output size will be 32 for union, 40 for struct
