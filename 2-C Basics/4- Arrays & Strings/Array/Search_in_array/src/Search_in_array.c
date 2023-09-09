/*
 ============================================================================
 Name        : Search_in_array.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int len,search;

	printf("Enter the NO. elements: ");
	fflush(stdout);
	scanf("%d", &len);

	int arr[len];

	printf("Enter the elements: ");
	fflush(stdout);
	for(int i=0; i<len; i++){
		scanf("%d", &arr[i]);
	}

	printf("Enter the element to search for: ");
	fflush(stdout);
	scanf("%d", &search);

	int i;
	for(i=0; i<len; i++){
		if (arr[i] == search){
			printf("Number found at location %d",i);
			break;
		}
	}

	if(i==len)
		printf("Element not found!!!\n");

	return 0;
}
