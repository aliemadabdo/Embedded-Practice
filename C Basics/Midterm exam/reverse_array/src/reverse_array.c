/*
 ============================================================================
 Name        : reverse_array.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int len;
	scanf("%d", &len);

	int arr[len];
	for (int i=0; i<len; i++){
		scanf("%d", &arr[i]);
	}

	for (int i=0; i<len; i++){
		printf("%d ", arr[len-i-1]);
	}

	return 0;
}
