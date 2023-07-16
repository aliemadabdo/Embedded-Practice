/*
 ============================================================================
 Name        : inch-feet_summation.c
 Author      : Ali Emad
 Version     : Exercise 2
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

struct Distance{
	int feet;
	float inch;
};

int main(void) {
	struct Distance d1, d2, sum;

	printf("First distance:\nEnter feet: ");
	fflush(stdout);
	scanf("%d", &d1.feet);

	printf("Enter inches: ");
	fflush(stdout);
	scanf("%f", &d1.inch);

	printf("\nSecond distance:\nEnter feet: ");
	fflush(stdout);
	scanf("%d", &d2.feet);

	printf("Enter inches: ");
	fflush(stdout);
	scanf("%f", &d2.inch);

	sum.inch = d1.inch + d2.inch;
	sum.feet = d1.feet + d2.feet;
	while (sum.inch >= 12){
		sum.inch -= 12;
		sum.feet++;
	}

	printf("\nSum if distances = %d\'-%0.1f\"",sum.feet, sum.inch);
	return 0;
}
