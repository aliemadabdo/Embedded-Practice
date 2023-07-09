/*
 ============================================================================
 Name        : Sum_of_multidimensional_array.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/* Unit 2 lesson 4 exercise 1
 * Sum of multidimensional array where elements are entered by the user
  */
#include <stdio.h>
//The default keyboard shortcut to run in eclipse is Ctrl + F11

int main(void) {

	double a[2][2],b[2][2];

	printf("Enter the elements of the 1st matrix\n");

	printf("Enter a11: ");
	fflush(stdout);
	scanf("%lf", &a[0][0]);

	printf("Enter a12: ");
	fflush(stdout);
	scanf("%lf", &a[0][1]);

	printf("Enter a21: ");
	fflush(stdout);
	scanf("%lf", &a[1][0]);

	printf("Enter a22: ");
	fflush(stdout);
	scanf("%lf", &a[1][1]);

	printf("Enter the elements of the 2st matrix\n");

	printf("Enter b11: ");
	fflush(stdout);
	scanf("%lf", &b[0][0]);

	printf("Enter b12: ");
	fflush(stdout);
	scanf("%lf", &b[0][1]);

	printf("Enter b21: ");
	fflush(stdout);
	scanf("%lf", &b[1][0]);

	printf("Enter b22: ");
	fflush(stdout);
	scanf("%lf", &b[1][1]);

	printf("Sum of the two Matrices:\n");
	for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
		for(int j=0; j<sizeof(a[0])/sizeof(double); j++){
			 printf("%lf\t",a[i][j] + b[i][j]);
		}
		printf("\n");
	}

	return 0;
}
