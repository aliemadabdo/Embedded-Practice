/*
 ============================================================================
 Name        : pointers_lecture.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * Operations:
 * pointer to function
 * pass function address as another function parameter
 *
 * */

#include <stdio.h>
#include <string.h>
void print_memory_range(char* ptr, int size);

void check_size(char str[], int (*ptr_sizeof)(const char*) );

int main(void) {

//	int x = 256*256*256-1;
	char mystring[] = "ali";

	int (*p)(const char*); // a function pointer
	p = strlen;
	check_size(mystring, p);

	print_memory_range(mystring, sizeof(mystring));

	printf("\nTHE NEXT IS THE OUTPUT OF THE FUNCTION CALLED WITH POINTER TO IT: \n");

	void (*ptrToFn) (char* , int);
	ptrToFn = print_memory_range;
	ptrToFn(mystring, sizeof(mystring));

	return 0;
}

void print_memory_range(char* ptr, int size){
	for(int i=0; i<size; i++){
		printf("%p \t %d\n", ptr+i,(unsigned char)*(ptr+i));
	}
}

void check_size(char str[], int (*ptr_sizeof)(const char*) ){
	if (!(ptr_sizeof(str)))
		printf("Empty\n!");
	else
		printf("Not Empty\n");
}

