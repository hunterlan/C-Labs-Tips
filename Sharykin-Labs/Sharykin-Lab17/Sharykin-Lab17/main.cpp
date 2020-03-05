//"StaticLibSharykinLab17.lib"

#include "Student.h"
#pragma comment (lib, "StaticLibSharykinLab17.lib")

int main()
{
	//��� ���� ���������������� 3 � 4 ������ � � 9 �� 30 ������
	int sizeStudent = 0;
	Student * students = (Student *)malloc(1 * sizeof(Student));
	FILE * file = fopen("students.txt", "r+");
	ReadStudents(students, &sizeStudent, file);
	fclose(file);
	for (int i = 0; i < sizeStudent; i++)
	{
		students[i].ShowData();
	}

	SortStudent(students, 2, sizeStudent);

	printf("\nAfter sorting\n");
	for (int i = 0; i < sizeStudent; i++)
	{
		students[i].ShowData();
	}

	file = fopen("resultSorted.txt", "w+");
	WriteStudents(students, sizeStudent, file);

	free(students);

	return 0;
}