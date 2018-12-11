#ifndef STUDENT_H_
#define STUDENT_H_

#define _CRT_SECURE_NO_WARNINGS

#include<cstddef>
#include<stdlib.h>
#include<cstdio>
#include<conio.h>

struct Student {
	char firstName[50];
	char lastName[80];
	char patronyminc[80];
	char group[20];
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
bool FindStudent(ListOfStudents * lst, Student findStudent);
void ShowList(ListOfStudents * lst);



#endif STUDENT_H_