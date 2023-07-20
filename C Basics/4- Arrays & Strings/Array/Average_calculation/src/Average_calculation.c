/*
 ============================================================================
 Name        : Average_calculation.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int len;

	printf("The number of data elements: ");
	fflush(stdout);
	scanf("%d", &len);

	float arr[len];
	float sum = 0.0;

	for(int i=0; i<len ;i++){
		printf("Enter number: ");
		fflush(stdout);
		scanf("%f", &arr[i]);

		sum += arr[i];
	}
	printf("Average = %f\n", sum/len);


	return 0;
}
