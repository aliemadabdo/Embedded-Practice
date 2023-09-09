/*
 * Linked_List.h
 *
 *  Created on: Jul 31, 2023
 *      Author: ALI
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#define DEBUG 1

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
	DELET_ALL,
	FIND_ELEMENT,
	GET_LENGTH,
	GET_MIDDLE,
	REVERSE_LIST,
	LOOP_DETECTION
};


void add_student(void);
void delete_student(void);
void print_list();
void delete_all(void);
void findElement();
void getLength();
void getMiddle();
void reverseList();
void loopDetection();
void add(struct Sstudent* ptr_student);
void delete(int ID);
#endif /* LINKED_LIST_H_ */
