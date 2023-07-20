/*
 ============================================================================
 Name        : Factorial_wz_recursion.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int factorial(int n);

int main(void) {
	int n;
	printf("Enter +ve int: ");
	fflush(stdout);
	scanf("%d", &n);

	if (n<0)
		printf("\nno factorial for a negative values");
	else
		printf("\nfactorial of %d = %d",n,factorial(n));

	return 0;
}

int factorial(int n){
	if (n==0)
		return 1;
	else
		return n*factorial(n-1);
}
