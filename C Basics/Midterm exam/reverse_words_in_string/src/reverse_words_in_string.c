/*
 ============================================================================
 Name        : reverse_words_in_string.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio.h>
int main(void) {

	char str[] = "Spaces are the delimiters";
	char *backPtr = str, *spacePtr = str, *frontPtr = str;

	do{

		while((*(frontPtr+1) != ' ') && (*(frontPtr+1) != '\0')){
			frontPtr++;
		}

		spacePtr = frontPtr+1;

		while(backPtr < frontPtr){
			//Swapping
			*frontPtr = *frontPtr + *backPtr;
			*backPtr  = *frontPtr - *backPtr;
			*frontPtr = *frontPtr - *backPtr;

			backPtr++;
			frontPtr--;
		}

		backPtr = spacePtr + 1;
		frontPtr = spacePtr + 1;

	}while(*(backPtr-1) != '\0');

	printf("%s", str);

	return 0;
}
