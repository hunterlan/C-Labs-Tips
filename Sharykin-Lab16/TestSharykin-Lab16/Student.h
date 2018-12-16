#ifndef STUDENT_H_
#define STUDENT_H_

#define _CRT_SECURE_NO_WARNINGS

#include<cstddef>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cstring>

struct Student {
	char firstName[50];
	char lastName[80];
	char patronyminc[80];
	char group[20];
};

bool ReadStudents(struct Student ** students, int * sizeStudents, FILE * file);
void FillStudents(struct Student ** students, int * sizeStudents);
bool WriteStudents(struct Student * students, int sizeStudents, FILE * file);


#endif STUDENT_H_