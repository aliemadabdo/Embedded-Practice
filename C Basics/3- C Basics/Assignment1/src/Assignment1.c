/*
 ============================================================================
 Name        : Assignment1.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
=============================================================================
 */

#include <stdio.h>

void assignment1ex4(void){
/*
 Write C Program to Multiply two Floating Point Numbers
 i should see the Console as following:
 ##########Console-output###

 ###########################
 Enter two numbers: 2.4
 1.1
 Product: 2.640000
 */
	float in1,in2;

	printf("\n>>>C Program to Multiply two Floating Point Numbers\n");

	printf("\nEnter two numbers: ");
	fflush(stdout);
	scanf("%f",&in1);
	scanf("%f",&in2);
	printf("Product: %f \n",in1*in2);
}

void assignment1ex5(void){
/*
Write C Program to Find ASCII Value of a Character

#########Console_output######
Enter a character: G
ASCII value of G = 71
#############################
 */
	char in;

	printf("\n>>>C Program to Find ASCII Value of a Character\n");

	printf("\nEnter character: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&in);
	printf("ASCII value of %c is = %d \n",in,in);
}

void assignment1ex7(void){
/*
Write Source Code to Swap Two Numbers without temp variable.

#########Console_output######
Enter value of a: 1.20
Enter value of b: 2.45

After swapping, value of a = 2.45
After swapping, value of b = 1.2
#############################
*/
	double a,b;

	printf("\n>>>Source Code to Swap Two Numbers without temp variable.\n");

	printf("\nEnter value of a: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%lf",&a);
	printf("Enter value of b: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%lf",&b);

	//ex a=1 b=5
	a = a+b;  //1+5=6  a=6 b=5
	b = a-b;  //6-5=1  a=6 b=1
	a = a-b;  //6-1=5  a=5 b=1

	printf("After swapping, value of a = %lf \n",a);
	printf("After swapping, value of b = %lf \n",b);

}

int main(void) {
	assignment1ex4();
	assignment1ex5();
	assignment1ex7();

	return 0;
}
