/*
 ============================================================================
 Name        : reverse_string_recursion.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>



void reverse_string(char arr[],char *end);

int main(void) {

	char text[100];
	char *end;
	printf("enter a string: ");
	fflush(stdout);
	gets(text);

	end = text + strlen(text) - 1;
	reverse_string(text,end);

	printf("reversed string: %s",text);

	return 0;
}

void reverse_string(char arr[],char *end){
	if (arr >= end)
		return;

	arr[0] = *end   + arr[0];
	*end   = arr[0] - *end;
	arr[0] = arr[0] - *end;

	reverse_string(arr+1,end-1);
}
