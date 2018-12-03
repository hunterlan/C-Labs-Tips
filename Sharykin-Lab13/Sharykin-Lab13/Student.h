#define _CRT_SECURE_NO_WARNINGS
#ifndef STUDENT_H_
#define STUDENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
	char firstName[50]; ///< Ім'я студента
	char lastName[80]; ///< По батькові студента
	char patronyminc[60]; ///< По батькові студента
	char country[50]; ///< У якій країні народився студент
	char disctrict[50]; ///< У якій області народився студент
	char city[50]; ///< У якому місті народився студент
	char phoneNumber[13]; ///< Мобільний номер студента
	int isLiveInHostel; ///< Чи живе студент у гуртожитку
	int isGetAScholarship; ///< Чи отримує студент стипендію (за індив.завданням)
	float markZNO[3]; ///< Оцінки студента за екзамени 
	void ShowData();
};

bool ReadStudents(struct Student * students, int * sizeStudents, FILE * file);
bool WriteStudents(struct Student * students, int sizeStudents, FILE * file);
void SortStudent(struct Student * students, int sortBy, int sizeStudents);
void AddStudent(struct Student * students, int * sizeStudents);
bool SortTwoCharElements(char * txt1, char * txt2);
bool SortTwoIntElemnets(int num1, int num2);
bool SortTwoFloatElements(float num1, float num2);

#endif STUDENT_H_
