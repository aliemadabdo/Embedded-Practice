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
#include "stdio.h"
#include "stdlib.h"

//remember that The scope of local static variables in C is limited to the block in which they are defined
int main(void) {

    int choice;

    while(1){
		printf("\n\t\t\tMenu\n");
		printf("0. Exit\n");
		printf("1. Add Student\n");
		printf("2. Delete Student\n");
		printf("3. View Students\n");
		printf("4. Delete All Students\n");
	    printf("5. Find Element\n");
	    printf("6. Get Length\n");
	    printf("7. Get Middle\n");
	    printf("8. Reverse List\n");
	    printf("9. Loop Detection\n");
		printf("\n");

		printf("Enter your choice: ");
		fflush(stdout);
		scanf("%d", &choice);

		switch (choice) {
			case ADD_STUDENT:
				printf("You chose to add a student.\n");
				add_student();
				break;
			case DELET_STUDENT:
				printf("You chose to delete a student.\n");
				delete_student();
				break;
			case VIEW_STUDENTS:
				printf("You chose to view students.\n");
				print_list();
				break;
			case DELET_ALL:
				printf("You chose to delete all students.\n");
				delete_all();
				break;
			case FIND_ELEMENT:
				printf("You chose to find an element.\n");
				findElement(); // Function for finding an element
				break;
			case GET_LENGTH:
				printf("You chose to get the length of the list.\n");
				getLength(); // Function for getting the length
				break;
			case GET_MIDDLE:
				printf("You chose to get the middle element.\n");
				getMiddle(); // Function for getting the middle element
				break;
			case REVERSE_LIST:
				printf("You chose to reverse the list.\n");
				reverseList(); // Function for reversing the list
				break;
			case LOOP_DETECTION:
				printf("You chose loop detection.\n");
				loopDetection(); // Function for loop detection
				break;
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

