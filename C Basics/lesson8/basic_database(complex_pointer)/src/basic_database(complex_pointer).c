///*
// ============================================================================
// Name        : basic_database(complex_pointer).c
// Author      : Ali Emad
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
// ============================================================================
// */
//
//#include <stdio.h>
//
//#define NUM_OF_STUDENTS 3
//#define NUM_OF_CLASSES 2
//
//struct Student{
//	char *name; //TODO change to pointer
//	int id;
//};
//
//int main(void) {
////	struct Student* all_students_in_one_class_info;
//
//	struct Student s1={"ali1",1}, s2={"ali2",2}, s3={"ali3",3},
//				   s4={"ali4",4}, s5={"ali5",5}, s6={"Alex",1002};
//
//	struct Student* school[NUM_OF_CLASSES][NUM_OF_STUDENTS] = {{&s1, &s2, &s3}, {&s4, &s5, &s6}};
//
//	struct Student* (*school_Ptr)[NUM_OF_CLASSES][NUM_OF_STUDENTS] = school;
//
//
//
//	printf("Employee Name: %s \nEmployee ID : %d\n"
//			,(*( *(school_Ptr+1) + 2))->name, (*(*(school_Ptr+1) + 2))->id);
//
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define OUTPUT_FILE "E:\\learnInDepth\\Unit 2\\lesson8\\Top100C_Codes.txt"

void extractQuestionTitle(char *line, FILE *outputFile) {
    char *titleStart = strstr(line, "1)");
    if (titleStart != NULL) {
        titleStart += 2; // Move past the question number and closing parenthesis
        fprintf(outputFile, "%s\n", titleStart);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];

    // Open input file for reading
    inputFile = fopen("E:\\learnInDepth\\Unit 2\\lesson8\\Top100C_Codes.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file for writing
    outputFile = fopen(OUTPUT_FILE, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Read input file line by line
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Extract question titles
        extractQuestionTitle(line, outputFile);
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    printf("Question titles extracted and saved to '%s'.\n", OUTPUT_FILE);

    return 0;
}
