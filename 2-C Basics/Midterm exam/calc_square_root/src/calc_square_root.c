/*
 ============================================================================
 Name        : calc_square_root.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int input;
	float delta, root, expected_root;

	scanf("%d", &input);
	expected_root = input;

	do{
		root = input / expected_root;				//try a guess
		delta = expected_root - root;				//update precision point condition
		expected_root = (expected_root + root) / 2; //update expected root
	}while(delta > 0.001);							//check if valid precision point

	printf("%f", expected_root);
	return 0;
}
