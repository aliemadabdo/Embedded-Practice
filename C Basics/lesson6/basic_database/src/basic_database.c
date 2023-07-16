/*
 ============================================================================
 Name        : basic_database.c
 Author      : Ali Emad
 Version     : Exercise 4
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define NUM_OF_STUDENTS 3

struct Student{
	char name[50];
	int roll;
	float mark;
};

int main(void) {
	struct Student student[NUM_OF_STUDENTS];

	for(int i=0; i<NUM_OF_STUDENTS; i++){

		student[i].roll = i+1;
		printf("\nEnter roll %d information \n",student[i].roll);

		printf("Enter name: ");
		fflush(stdin); fflush(stdout);
		gets(student[i].name);

		printf("Enter mark: ");
		fflush(stdin); fflush(stdout);
		scanf("%f", &student[i].mark);
	}


	for(int i=0; i<NUM_OF_STUDENTS; i++){
		printf("\nDisplaying information:\nRoll: %d\nName: %s\nMark: %0.2f\n"
				, student[i].roll, student[i].name, student[i].mark);
	}

	return 0;
}
