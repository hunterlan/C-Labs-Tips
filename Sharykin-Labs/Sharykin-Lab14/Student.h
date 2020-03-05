#ifndef STUDENT_H_
#define STUDENT_H_

#define _CRT_SECURE_NO_WARNINGS

#include<cstddef>
#include<stdlib.h>
#include<cstdio>
#include<conio.h>
#include<cstring>

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

ListOfStudents * PushAfterStudentToList(ListOfStudents * lst, Student getStudent, int pos);
bool ReadStudents(struct Student ** students, int * sizeStudents, FILE * file);
ListOfStudents * SortWithPointer(ListOfStudents * lst, int chooseSort);
void PushBackStudentToList(ListOfStudents ** lst, Student getStudent);
void PushStudentToList(ListOfStudents ** lst, Student getStudent);
ListOfStudents * GetLastElemInList(ListOfStudents * lst);
ListOfStudents * Swap(ListOfStudents * lst1, ListOfStudents * lst2, ListOfStudents * head);
ListOfStudents * Copy(ListOfStudents * lst);
void PopStudentFromList(ListOfStudents ** lst);
bool WriteStudents(ListOfStudents * lst, FILE * files);
bool FindStudent(ListOfStudents * lst, Student findStudent);
void ShowList(ListOfStudents * lst);



#endif STUDENT_H_