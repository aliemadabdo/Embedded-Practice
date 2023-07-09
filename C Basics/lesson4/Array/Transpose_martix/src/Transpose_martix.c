/*
 ============================================================================
 Name        : Transpose_martix.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int rows, cols;

	printf("Enter NO. rows then NO. columns: ");
	fflush(stdout);
	scanf("%d %d",&rows, &cols);

	double arr[rows][cols];

	printf("Enter the matrix elements\n");

	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			printf("Enter the element a%d%d: ",i+1,j+1);
			fflush(stdout);
			scanf("%lf", &arr[i][j]);
		}
	}

	printf("\nEntered Matrix\n");
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			printf("%lf ", arr[i][j]);
		}
		printf("\n");
	}

	printf("\nTransposed Matrix\n");
	for(int i=0; i<cols; i++){
		for(int j=0; j<rows; j++){
			printf("%lf ", arr[j][i]);
		}
		printf("\n");
	}


	return 0;
}
