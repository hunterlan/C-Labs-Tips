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
	char firstName[50]; ///< ��'� ��������
	char lastName[80]; ///< �� ������� ��������
	char patronyminc[60]; ///< �� ������� ��������
	char country[50]; ///< � ��� ���� ��������� �������
	char disctrict[50]; ///< � ��� ������ ��������� �������
	char city[50]; ///< � ����� ��� ��������� �������
	char phoneNumber[13]; ///< �������� ����� ��������
	int isLiveInHostel; ///< �� ���� ������� � ����������
	int isGetAScholarship; ///< �� ������ ������� �������� (�� �����.���������)
	float markZNO[3]; ///< ������ �������� �� �������� 
	void ShowData();
};

extern "C" DLLSHARYKINLAB17 bool ReadStudents(struct Student * students, int * sizeStudents, FILE * file);
extern "C" DLLSHARYKINLAB17 bool WriteStudents(struct Student * students, int sizeStudents, FILE * file);
extern "C" DLLSHARYKINLAB17 void SortStudent(struct Student * students, int sortBy, int sizeStudents);
extern "C" DLLSHARYKINLAB17 bool SortTwoCharElements(char * txt1, char * txt2);
extern "C" DLLSHARYKINLAB17 bool SortTwoIntElemnets(int num1, int num2);
extern "C" DLLSHARYKINLAB17 bool SortTwoFloatElements(float num1, float num2);

#endif STUDENTS_H_
