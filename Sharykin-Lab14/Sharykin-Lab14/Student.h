#ifndef STUDENT_H_
#define STUDENT_H_

#define _CRT_SECURE_NO_WARNINGS

#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>

struct Student {
	char * firstName;
	char * lastName;
	char * patronyminc;
	char * group;
};

struct ListOfStudents {
	Student student;
	ListOfStudents * next;
};

bool ReadStudents(struct Student * students, int * sizeStudents, FILE * file);
void PushBackStudentToList(ListOfStudents ** lst, Student getStudent);
void PushStudentToList(ListOfStudents ** lst, Student getStudent);
ListOfStudents * GetLastElemInList(ListOfStudents * lst);
void PopStudentFromList(ListOfStudents ** lst);
void WriteStudents(ListOfStudents * lst);
void ShowList(ListOfStudents * lst);



#endif STUDENT_H_