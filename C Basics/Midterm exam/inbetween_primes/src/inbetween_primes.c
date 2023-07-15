/*
 ============================================================================
 Name        : inbetween_primes.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int start,end;
	scanf("%d %d", &start, &end);

	for(int i=start; i<end; i++){
		if( (i!=1) && ((i==2 || i==3 || i==5 || i==7) || (i%2 && i%3 && i%5 && i%7))){
		// check if i is not 1
		// and check if i is 2 or 3 or 5 or 7
		// or check if i is not divisible by 2 and 3 and 5 and 7
		// if all this conditions satisfied print this number
			printf("%d ", i);
		}
	}
	return 0;
}
