#include"testStudent.h"

/**
* @file Lab16.cpp
* Головний тестовий файл
* @author Шарикін Костянтин
* @version 1.0
* @date 2018.12.16
*/

int main()
{

	int sizeStudents = 0;
	Student * student = (Student *)malloc(1 * sizeof(Student));
	FILE * file = fopen("students.txt", "r+");
	ReadStudents(&student, &sizeStudents, file);
	TestReadStudent(student, sizeStudents);
	return 0;
}