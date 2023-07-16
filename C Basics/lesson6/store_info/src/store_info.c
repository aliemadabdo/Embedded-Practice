/*
 ============================================================================
 Name        : store_info.c
 Author      : Ali Emad
 Version     : Exercise 1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

struct Student{
	char name[50];
	int roll;
	float mark;
};

int main(void) {
	struct Student student;

	printf("Enter your name: ");
	fflush(stdout);
	gets(student.name);

	printf("Enter your Roll: ");
	fflush(stdout);
	scanf("%d", &student.roll);

	printf("Enter your Mark: ");
	fflush(stdout);
	scanf("%f", &student.mark);

	printf("\nDisplaying information:\nName: %s\nRoll: %d\nMark: %0.2f\n"
			,student.name, student.roll, student.mark);

	return 0;
}
