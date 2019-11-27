#define _CRT_SECURE_NO_WARNINGS
#ifndef STUDENT_H_
#define STUDENT_H_

#include<cstddef>
#include<stdlib.h>
#include<cstdio>
#include<conio.h>
#include<cstring>

struct Student {
	char firstName[50];
	char lastName[80];
	char middleName[50];
	char group[20];
};

struct ListOfStudents {
	struct Student student;
	struct ListOfStudents *next;
	struct ListOfStudents *prev;
};

struct ListOfStudents * Init(struct Student student);
struct ListOfStudents * Sort(ListOfStudents * lst);
struct ListOfStudents * Swap(ListOfStudents * elem1, ListOfStudents * elem2, ListOfStudents * head);
struct ListOfStudents * Add(ListOfStudents * lst, struct Student student);
struct ListOfStudents * Del(ListOfStudents * lst);
struct ListOfStudent * Get(ListOfStudents * lst, struct Student student);
void ShowList(ListOfStudents * lst);

#endif // !STUDENT_H_
