/*
 * queue.h
 *
 *  Created on: sep 28, 2023
 *      Author: ALI Emad
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define DEBUG 1

struct Sstudent{
	char fristName[50];
	char lasttName[50];
	int id;
	float GPA;
	int courseID;
};

struct Sstudent queue[50];

// 1- Add student details manually. 
// 2- Add students details from text file. 
// 3- Find student by a given roll number. 
// 4- Find students by a given first name. 
// 5- Find students registered in specific course. 
// 6- Number of students registered. 
// 7- Delete student by Roll number. 
// 8- Update student information.
// 9- SHOW_ALL,
// 10- EXIT

enum menu{
	ADD_S_MANUALY,
	ADD_S_FROM_TXT,
	FIND_S_FROM_ID,
	FIND_STUDENT_FROM_1stNAME,
	FIND_COURSE_STUDENTS,
	STUDENTS_AMOUNT,
	DELET_BY_ROLE,
	UPDATE_STUDENT,
	SHOW_ALL,
	EXIT
};

void add_student(void);
void add_student_from_txt(void); //char absPath[]
void find_student_with_id(void); //int id
void find_student_with_1stname(void); //char name[]
void find_course_students(void); //int courseID
void total_num_of_students(void);
void delete_student_with_id(void); //int id
void update_student_with_id(void); //int id
void show_all(void);
void exit(void);

#endif /* QUEUE_H_ */
