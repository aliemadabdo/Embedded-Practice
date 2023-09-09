/*
 ============================================================================
 Name        : sum_range_without_loop.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int sum = 0,start, end;
	scanf("%d %d", &start, &end);

	int packet = end + start ;
	int len = (end - start) /2;
	if ((end - start) % 2 == 0){
		sum = packet * len + packet/2;
	}
	else{
		sum = (packet-1) * len + (packet-1)/2 + end;
	}

	printf("%d", sum);
	return 0;
}
