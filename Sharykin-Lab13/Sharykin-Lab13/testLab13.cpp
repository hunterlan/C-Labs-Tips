#include"Student.h"
#include"testStudent.h"

/*!
@mainpage
<b> ����������� ������ � 13. <br/>  �������� ����������  </b>
<br/><b><i>���� ������:</i></b>: �������� �������� 
������� � �������� ��������� �����.<br/>
<b>1 �������� �� ������ <br/> ������� ��������  <br/> </b>
��� ���������� ������������ ����������� �� ����� � ���������� �������, 
������ ������ � ������� �����, �� ������������ ���������� ������ ������������ �����������.
� ��� ������ ������� ����� �� ���������� ���������� ��� ��� �������-�����, � ����� ������ �����������
(������� / �� �������). ���� ����������� �� �������, ������� �� �����, 
�� ���� �� ������� ��������.<br>
@author ������ ���������.
@date 03-dec-2018
@version 1.0  */

/**
* @file testLab13.cpp
* �������� ����
* @author ������ ���������
* @version 1.0
* @date 2018.12.03
*/

int main()
{
	FILE * file = fopen("Students.txt", "a+");
	struct Student * students = (Student * )malloc(1 * sizeof(Student));
	int sizeStudents = 0;
	ReadStudents(students, &sizeStudents, file);
	TestReadStudents(students);
	/*for (int i = 0; i < sizeStudents; i++)
	{
		printf("Student #%d\n", i+1);
		students[i].ShowData();
	}
	SortStudent(students, 2, sizeStudents);
	for (int i = 0; i < sizeStudents; i++)
	{
		printf("Student #%d\n", i + 1);
		students[i].ShowData();
	}
	AddStudent(students, &sizeStudents);
	for (int i = 0; i < sizeStudents; i++)
	{
		printf("Student #%d\n", i + 1);
		students[i].ShowData();
	}
	file = fopen("StudentsSorted.txt", "w+");
	WriteStudents(students, sizeStudents, file);*/
	return 0;
}