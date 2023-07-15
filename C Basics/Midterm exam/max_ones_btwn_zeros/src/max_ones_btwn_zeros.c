/*
 ============================================================================
 Name        : max_ones_btwn_zeros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int max=0, varMax = 0;
	unsigned int dicimal;

	scanf("%d", &dicimal);

	while(dicimal != 0){
		if (dicimal % 2){
			varMax++;

			if(varMax > max)
				max = varMax;
		}
		else
			varMax = 0;

		dicimal /= 2;
	}

	printf("%d", max);

	return 0;
}
