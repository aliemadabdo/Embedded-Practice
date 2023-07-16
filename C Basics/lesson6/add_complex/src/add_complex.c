/*
 ============================================================================
 Name        : add_complex.c
 Author      : Ali Emad
 Version     : Exercise 3
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

struct Complex{
	float real;
	float img;
};

int main(void) {

	struct Complex complex1, complex2, sum;

	printf("Enter first complex number \nEnter real part then imaginary part: ");
	fflush(stdout);
	scanf("%f %f", &complex1.real, &complex1.img);

	printf("Enter second complex number \nEnter real part then imaginary part: ");
	fflush(stdout);
	scanf("%f %f", &complex2.real, &complex2.img);

	sum.real = complex1.real + complex2.real;
	sum.img = complex1.img + complex2.img;

	printf("\nSum of complex = %0.2f + j%0.2f", sum.real, sum.img);
	return 0;
}
