/*
 ============================================================================
 Name        : assignment2.c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void assignment2ex2(void){
/*
 C Program to Check Vowel or consonant
 */
	char in;

	printf("\n>>>C Program to Check Vowel or consonant\n");
	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c", &in);

	switch(in){
		case 'a':
		case 'e':
		case 'o':
		case 'i':
		case 'u':
		case 'A':
		case 'E':
		case 'O':
		case 'I':
		case 'U':
			printf("%c is a vowel\n", in);
			break;
		default:
			printf("%c is a consonant\n", in);
	}
}

void assignment2ex5(void){
/*
 * C Program to Check if alphabet or not
 * */
	char ch;

	printf("\n>>>C Program to Check if alphabet or not\n");
	printf("Enter a character: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c", &ch);

	if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)){
		printf("%c is an alphabet\n", ch);
	}
	else{
		printf("%c is not an alphabet\n", ch);
	}
}

void assignment2ex7(void){
/*
 * C Program to find the factorial of the number
 * */
	int in,temp;

	printf("\n>>>C Program to find the factorial of the number\n");
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d", &in);
	temp = in;
	if (in < 0)
		printf("Error!!! Factorial of negative number does not exist");
	else if(in == 0)
		printf("Factorial = 1");
	else{
		for(int i=1; i<in; i++){
			temp = temp * i;
		}
		printf("Factorial = %d\n", temp);
	}

}

void assignment2ex8(void){
/*
 * C Program to make a simple calculator using switch case
 * */
	double a,b,op;
	char operator;

	printf("\n>>>C Program to make a simple calculator using switch case\n");

	printf("Enter operator [ + - * /]: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c", &operator);

	printf("Enter two operands:\n");
	fflush(stdout);
	scanf("%lf", &a);
	scanf("%lf", &b);

	switch(operator){
	case'+':
		op = a+b;
		break;
	case'-':
		op=a-b;
		break;
	case'*':
		op=a*b;
		break;
	case'/':
		op=a/b;
		break;
	}

	printf("%lf %c %lf = %lf\n",a,operator,b,op);
}

int main(void) {
	assignment2ex2();
	assignment2ex5();
	assignment2ex7();
	assignment2ex8();

	return 0;
}

