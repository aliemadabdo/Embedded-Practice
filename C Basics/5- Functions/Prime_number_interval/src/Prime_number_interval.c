/*
 ============================================================================
 Name        : Prime_number_interval.c
 Author      : Ali_Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void primes(int s, int e);

int main(void) {

	int start, end;
	printf("enter start and end of interval: ");
	fflush(stdout);
	scanf("%d %d", &start, &end);

	primes(start, end);

	return 0;
}

void primes(int s, int e){
	printf("prime numbers between %d and %d are: ", s,e);

	int sum = 0;
	for(int i=s; i<e; i++){
		if((i!=1) && ((i==2 || i==3 || i==5 || i==7) || (i%2 && i%3 && i%5 && i%7))){
			printf("%d ",i);
			sum++;
		}
	}

	if (sum == 0){
		printf("\nthere are no prime numbers between %d and %d\n",s,e);
	}
	else
		printf("\nnumber of primes = %d\n",sum);

}
