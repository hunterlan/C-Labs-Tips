#ifndef STUDENTS_H_
#define STUDENTS_H

//#define _CRT_SECURE_NO_WARNINGS

#ifdef DLLSHARYKINLAB17_EXPORTS
#define DLLSHARYKINLAB17 __declspec(dllexport)
#else
#define DLLSHARYKINLAB17 __declspec(dllimport)
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern "C" DLLSHARYKINLAB17 struct Student
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

extern "C" DLLSHARYKINLAB17 bool ReadStudents(struct Student * students, int * sizeStudents, FILE * file);
extern "C" DLLSHARYKINLAB17 bool WriteStudents(struct Student * students, int sizeStudents, FILE * file);
extern "C" DLLSHARYKINLAB17 void SortStudent(struct Student * students, int sortBy, int sizeStudents);
extern "C" DLLSHARYKINLAB17 bool SortTwoCharElements(char * txt1, char * txt2);
extern "C" DLLSHARYKINLAB17 bool SortTwoIntElemnets(int num1, int num2);
extern "C" DLLSHARYKINLAB17 bool SortTwoFloatElements(float num1, float num2);

#endif STUDENTS_H_
