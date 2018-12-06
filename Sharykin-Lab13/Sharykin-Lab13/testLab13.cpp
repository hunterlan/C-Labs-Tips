#include"Student.h"
#include"testStudent.h"

/*!
@mainpage
<b> Лабораторна робота № 13. <br/>  Модульне тестування  </b>
<br/><b><i>Мета роботи:</i></b>: придбати практичні 
навички з розробки модульних тестів.<br/>
<b>1 Завдання до роботи <br/> Основне завдання  <br/> </b>
Для попередньо розробленого функціоналу по роботі з прикладною областю, 
додати методи – модульні тести, що демонструють коректність роботи розробленого функціоналу.
В ході роботи кожного тесту має виводитися інформація про ім’я функції-тесту, а також статус верифікації
(пройшов / не пройшов). Якщо верифікація не пройшла, вивести на екран, 
що саме не пройшло перевірку.<br>
@author Шарикін Костянтин.
@date 03-dec-2018
@version 1.0  */

/**
* @file testLab13.cpp
* Головний файл
* @author Шарикін Костянтин
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