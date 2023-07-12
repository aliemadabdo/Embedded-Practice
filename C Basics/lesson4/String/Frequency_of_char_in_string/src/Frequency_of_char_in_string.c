/*
 ============================================================================
 Name        : Frequency_of_char_in_string.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {

	char text[100],ch;
	int freq = 0;

	printf("enter a string: ");
	fflush(stdout);
	gets(text);

	printf("enter a character: ");
	fflush(stdout);
	scanf("%c", &ch);

	for(int i=0; i<strlen(text); i++){
		if(ch==text[i]){
			freq++;
		}
	}
	printf("the frequency of '%c' in the string \"%s\" = %d",ch,text,freq);

	return 0;
;
}
