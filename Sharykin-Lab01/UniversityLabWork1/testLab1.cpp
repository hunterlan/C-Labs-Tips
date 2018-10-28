#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
/**
* ��������� ��������
*/
struct Student
{
	char firstName[20]; ///< ���� ��������  
	char middleName[20]; ///< ������� ��������  
	char lastName[20]; ///< �� ������� ��������  
	int *marks; ///< ������ �������� 
};
/**
* ��������� ����� ��� ��������.
*  * ������� ������ �������� ϲ� �� ����� ������ ������� ��� ����,
* �� �������, ������;
* ������ ����������� ���������� ����� �� 1 �� 5, ���������� ���
* ���������� ���� ��������� Student
* @return ��������� Student � ����������� ������
*/
struct Student generateStudent(int marksCount)
{
	int const NAMES_COUNT = 3; // ʳ������ ����/������/�� �������  
	char firstNames[NAMES_COUNT][20];  /* ����� �������� ���� */
	const char middleNames[NAMES_COUNT][20] = { "Valerievich", "Valerievich", "Valerievich", }; /* ����� �� ������� */
	char lastNames[NAMES_COUNT][20] = { "Sharykin",  "Sharykin",  "Sharykin" }; /* ����� ������ */
	struct Student result;
	int i;
	strcpy_s(firstNames[0], "Konstantin");
	strcpy_s(firstNames[1], "Konstantin");
	strcpy_s(firstNames[2], "Konstantin");
	strcpy_s(result.firstName, firstNames[rand() % NAMES_COUNT]);
	strcpy_s(result.middleName, middleNames[rand() % NAMES_COUNT]);
	strcpy_s(result.lastName, lastNames[rand() % NAMES_COUNT]);
	result.marks = (int *)malloc(marksCount * 4);
	for (i = 0; i < marksCount; i++)
	{
		result.marks[i] = rand() % 5 + 1; // ������ �� 1 �� 5  
	}
	return result;
}

void showStudents(struct Student students[], int studentsCount, int marksCount)
{
	int i, j;
	for (i = 0; i < studentsCount; i++)
	{
		printf("Output Student #%d information: \n", i);
		printf("%s %s %s: ", students[i].lastName, students[i].firstName, students[i].middleName);
		for (j = 0; j < marksCount; j++)
		{
			printf("%d ", students[i].marks[j]);
		}
		printf("\n");
	}
}

int main()
{
	const int STUDENTS_COUNT = 10; // ʳ������ ��������  
	const int STUDENT_MARKS_COUNT = 5; // ʳ������ ������ � ��������  
	struct Student students[10];
	int i;
	for (i = 0; i < STUDENTS_COUNT; i++)
	{
		students[i] = generateStudent(STUDENT_MARKS_COUNT);
	}
	showStudents(students, STUDENTS_COUNT, STUDENT_MARKS_COUNT);
	return 0;
}