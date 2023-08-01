/*
 ============================================================================
 Name        : Linked_List.c
 Author      : Ali Emad
 Version     : V1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Linked_List.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
//remember that The scope of local static variables in C is limited to the block in which they are defined

    int choice ;

    while(1){
		printf("\n\t\t\tMenu\n");
		printf("0. Exit\n");
		printf("1. Add Student\n");
		printf("2. Delete Student\n");
		printf("3. View Students\n");
		printf("4. Delete All Students\n");
		printf("\n");

		printf("Enter your choice: ");
		fflush(stdout);
		scanf("%d", &choice);

		switch (choice) {
			case ADD_STUDENT:
				add_student();    break;
			case DELET_STUDENT:
				delete_student(); break;
			case VIEW_STUDENTS:
				print_list(); 	  break;
			case DELET_ALL:
				delete_all();     break;
			case EXIT:
				printf("Exiting the program.\n");
				return 0;
			default:
				printf("Invalid choice.\n");
				break;
		}
    }
	return 0;
}

