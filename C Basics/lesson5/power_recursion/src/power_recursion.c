/*
 ============================================================================
 Name        : power_recursion.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int poww (int base, int power);

int main(void) {
	int base, power;

	printf("enter base and power: ");
	fflush(stdout);
	scanf("%d %d", &base, &power);

	if (base==power && base == 0)
		printf("\nUNDEFINED OPERATION\n");
	else
		printf("%d power %d = %d",base, power, poww(base,power));

	return 0;
}

int poww (int base, int power){
	if(power == 0)
		return 1;
	else
		return base*poww(base,power-1);
}
