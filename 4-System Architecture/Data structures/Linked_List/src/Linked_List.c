/* Future plans:
 * 1-check for duplicated IDs  */

#include "Linked_List.h"
#include "stdio.h"
#include "stdlib.h"

struct Sstudent* g_p_base = NULL;

void add_student(void){

	//allocate a new space to structure of type Sstudent
	struct Sstudent* p_student = (struct Sstudent*)malloc( sizeof(struct Sstudent) );
	p_student->next = NULL; //default equal NULL i think

	// Input the ID, name, and height of the person
	printf("Enter the ID: ");
	fflush(stdout);
	scanf("%d", &p_student->data.id);

	printf("Enter the name: ");
	fflush(stdout); fflush(stdin);
	gets(p_student->data.name);

	printf("Enter the height: ");
	fflush(stdout);
	scanf("%f", &p_student->data.height);

	add(p_student);
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

void delete_student(void){
	int ID;

	printf("Enter student ID to be deleted: .\n");
	fflush(stdout);
	scanf("%d", &ID);

	delete(ID);
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
	free(temp);
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

void delete_all(void){
	g_p_base = NULL;
}

void findElement(){

}

void getLength(){

}

void getMiddle(){

}

void reverseList(){

}

void loopDetection(){

}










