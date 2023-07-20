/*
 ============================================================================
 Name        : basic_database(complex_pointer).c
 Author      : Ali Emad
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//Need a FIX

#include <stdio.h>

#define NUM_OF_STUDENTS 3
#define NUM_OF_CLASSES 2

struct Student{
	char *name; //TODO change to pointer
	int id;
};

int main(void) {
//	struct Student* all_students_in_one_class_info;

	struct Student s1={"ali1",1}, s2={"ali2",2}, s3={"ali3",3},
				   s4={"ali4",4}, s5={"ali5",5}, s6={"Alex",1002};

	struct Student* school[NUM_OF_CLASSES][NUM_OF_STUDENTS] = {{&s1, &s2, &s3}, {&s4, &s5, &s6}};

	struct Student* (*school_Ptr)[NUM_OF_CLASSES][NUM_OF_STUDENTS] = school;



	printf("Employee Name: %s \nEmployee ID : %d\n"
			,(*( *(school_Ptr+1) + 2))->name, (*(*(school_Ptr+1) + 2))->id);

	return 0;
}
