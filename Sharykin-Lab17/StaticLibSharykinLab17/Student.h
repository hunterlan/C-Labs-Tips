#define _CRT_SECURE_NO_WARNINGS
#ifndef STUDENT_H_
#define STUDENT_H_

#include<cstdio>
#include<cstdlib>
#include<cstring>

struct Student
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

bool ReadStudents(struct Student * students, int * sizeStudents, FILE * file);
bool WriteStudents(struct Student * students, int sizeStudents, FILE * file);
void SortStudent(struct Student * students, int sortBy, int sizeStudents);
void AddStudent(struct Student * students, int * sizeStudents);
bool SortTwoCharElements(char * txt1, char * txt2);
bool SortTwoIntElemnets(int num1, int num2);
bool SortTwoFloatElements(float num1, float num2);

#endif STUDENT_H


