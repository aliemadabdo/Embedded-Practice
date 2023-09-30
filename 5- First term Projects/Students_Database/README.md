# Student Database Management System Documentation

## Introduction
This document provides an overview and documentation for the Student Database Management System, a C program authored by Ali Emad. The program allows users to manage a database of student records using a queue data structure.

## Table of Contents
1. [Main Function](#main-function)
2. [Queue Data Structure](#queue-data-structure)
3. [add_student](#add_student)
4. [add_student_from_txt](#add_student_from_txt)
5. [find_student_with_id](#find_student_with_id)
6. [find_student_with_1stname](#find_student_with_1stname)
7. [find_course_students](#find_course_students)
8. [total_num_of_students](#total_num_of_students)
9. [delete_student_with_id](#delete_student_with_id)
10. [update_student_with_id](#update_student_with_id)
11. [show_all](#show_all)

## 1. Main Function<a name="main-function"></a>
The main function of the program serves as the entry point and user interface for the Student Database Management System. It presents a menu of options to the user, allowing them to perform various operations on the student database.

## 2. Queue Data Structure<a name="queue-data-structure"></a>
The program uses a queue data structure to manage student records. The queue is implemented as an array, and each element of the array represents a student record.

## 3. add_student<a name="add_student"></a>
- Purpose: Allows the user to manually add a new student to the database.
- Input: User enters student details (First name, Last name, ID, GPA, Course ID) interactively.
- Usage: `add_student()`

## 4. add_student_from_txt<a name="add_student_from_txt"></a>
- Purpose: Reads student records from a text file and adds them to the database.
- Input: Student records are read from a specified text file.
- Usage: `add_student_from_txt()`

## 5. find_student_with_id<a name="find_student_with_id"></a>
- Purpose: Searches for a student record by a given ID (roll number).
- Input: User enters the ID to search for.
- Usage: `find_student_with_id()`

## 6. find_student_with_1stname<a name="find_student_with_1stname"></a>
- Purpose: Searches for student records by a given first name.
- Input: User enters the first name to search for (case sensitive).
- Usage: `find_student_with_1stname()`

## 7. find_course_students<a name="find_course_students"></a>
- Purpose: Finds the number of students registered in a specific course.
- Input: User enters the course ID to search for.
- Usage: `find_course_students()`

## 8. total_num_of_students<a name="total_num_of_students"></a>
- Purpose: Calculates and displays the total number of students in the database.
- Usage: `total_num_of_students()`

## 9. delete_student_with_id<a name="delete_student_with_id"></a>
- Purpose: Deletes a student record by a given ID (roll number).
- Input: User enters the ID of the student to be deleted.
- Usage: `delete_student_with_id()`

## 10. update_student_with_id<a name="update_student_with_id"></a>
- Purpose: Updates student information (First name, Last name, ID, GPA, Course ID) for a given ID.
- Input: User enters the ID of the student to update, followed by the new details.
- Usage: `update_student_with_id()`

## 11. show_all<a name="show_all"></a>
- Purpose: Displays all student records in the database.
- Usage: `show_all()`

## Conclusion
The Student Database Management System provides a user-friendly interface to manage student records using a queue data structure. Users can perform operations such as adding, searching, updating, and deleting student records.

## Author
- Name: Ali Emad

