/*
 ============================================================================
 Name        : Linked_List.c
 Author      : Ali Emad
 Version     : V1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sdata{
	int id;
	char name[50];
	float height;
};

struct Sstudent{
	struct Sdata data;
	struct Sstudent* next;
};

enum{
	EXIT,
	ADD_STUDENT,
	DELET_STUDENT,
	VIEW_STUDENTS,
	DELET_ALL
};

struct Sstudent* g_p_base = NULL;


void print_list();
void add(struct Sstudent* ptr_student);
void delete(int ID);

#define DEBUG 1

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
if(DEBUG)  scanf("%d", &choice);
if(!DEBUG) choice = 1;
		switch (choice) {
			case ADD_STUDENT:
			{
				printf("You chose to add a student.\n");

				struct Sstudent* p_student = (struct Sstudent*)malloc( sizeof(struct Sstudent) );
				p_student->next = NULL;

				// Input the ID, name, and height of the person
			    printf("Enter the ID: ");
				fflush(stdout);
				if(DEBUG) scanf("%d", &p_student->data.id);
				if(!DEBUG) p_student->data.id = 19016028;

			    printf("Enter the name: ");
				fflush(stdout); fflush(stdin);
				if(DEBUG) gets(p_student->data.name);
				if(!DEBUG) strcpy(p_student->data.name , "ALI");

			    printf("Enter the height: ");
				fflush(stdout);
				if(DEBUG) scanf("%f", &p_student->data.height);
				if(!DEBUG) p_student->data.height = 188.5;

				add(p_student);

				break;
			}
			case DELET_STUDENT:
			{
				int ID;
				printf("You chose to delete a student.\n");
				printf("Enter student ID to be deleted: .\n");
				fflush(stdout);
				scanf("%d", &ID);

				delete(ID);

				break;
			}
			case VIEW_STUDENTS:
			{
				printf("You chose to view students.\n");
				print_list();
				break;
			}
			case DELET_ALL:
			{
				printf("You chose to delete all students.\n");
				g_p_base = NULL;
				break;
			}
			case EXIT:
			{
				printf("Exiting the program.\n");
				return 0;
			}
			default:
				printf("Invalid choice.\n");
				break;
		}
    }
	return 0;
}


void add(struct Sstudent* ptr_student){

	if (g_p_base == NULL){
		g_p_base = ptr_student;
		return;
	}

	struct Sstudent* temp = g_p_base;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = ptr_student;

}

void delete(int ID){

	if (g_p_base == NULL){
		printf("ERROR!: can not delete from empty list\n");
		return;
	}

	if ( g_p_base->data.id == ID ){
		g_p_base = g_p_base->next;
		return;
	}

	struct Sstudent* prev_temp = g_p_base;
	struct Sstudent* temp = g_p_base;

	while (temp->data.id != ID ){
		prev_temp = temp;
		temp = temp->next;

		if (temp == NULL){
			printf("ERROR!: ID not found\n");
			return;
		}
	}

	prev_temp->next = temp->next;
	temp->next = NULL;
}

void print_list(){
	if (g_p_base == NULL){
		printf("ERROR!: can not print from empty list\n");
		return;
	}

	struct Sstudent* temp = g_p_base;
	int record = 1;

	do{
		printf("\nrecord number: %d\n",record);
		printf("ID: %d\n",temp->data.id);
		printf("name: %s\n",temp->data.name);
		printf("height: %f\n",temp->data.height);

		temp = temp->next;
		record++;
	}while(temp != NULL); //!!!BE AWARE!!!

}




















