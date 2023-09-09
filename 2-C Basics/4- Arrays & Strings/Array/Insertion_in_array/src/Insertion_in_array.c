/*
 ============================================================================
 Name        : Insertion_in_array.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {

	int arr[50],len,inserted,pos;

	printf("Enter NO. elements: ");
	fflush(stdout);
	scanf("%d", &len);

	printf("Enter the elements: ");
	fflush(stdout);
	for(int i=0; i<len; i++){
		scanf("%d", &arr[i]);
	}

	printf("Enter the element to be inserted: ");
	fflush(stdout);
	scanf("%d", &inserted);

	printf("Enter the position: "); //constrains should be applied
	fflush(stdout);
	scanf("%d", &pos);

	for(int i=len; i>=pos; i--){
		arr[i+1] = arr[i];
	}
	arr[pos]=inserted;
	len++;

	printf("The new array: ");
	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}

	return 0;
}
