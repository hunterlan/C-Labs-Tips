#include"Student.h"

/*!
@mainpage
<b> Лабораторна робота № 16. <br/>  Макроси  </b>
<br/><b><i>Мета роботи:</i></b>: Придбати практичні навички щодо розроблення програм 
з використанням макросів<br/>
<b>1 Завдання до роботи <br/> Основне завдання  <br/> </b>
Для попередньо розробленого функціоналу по роботі з прикладною областю за допомогою макровизначень
зробити наступну «кастомізацію»: якщо визначене макровизначення DEBUG, то при виклику кожної
функції роботи з прикладною областю виконувати таке:<br/>
− виводити поточну дату та час; <br/>
− виводити ім’я поточної функції; <br/>
− при завершенні програми вивести загальний час роботи програми.<br/>
− при запуску кожного тесту виводити ім’я тесту, а по завершенні тесту виводити час, 
що було потрачено на виконання даного тесту; <br/>
− по завершення всіх тестів було виведено час їх виконання.<br/>
@author Шарикін Костянтин.
@date 03-dec-2018
@version 1.0  */

/**
* @file Lab16.cpp
* Головний файл
* @author Шарикін Костянтин
* @version 1.0
* @date 2018.12.16
*/

int main()
{
	srand(time(0));
	int sizeOfStudents = 0;
	Student * students = (Student *)malloc(1 * sizeof(Student));
	clock_t startWorkProgramm, finishWorkProgramm;
	startWorkProgramm = clock();
	char * path = (char *)malloc(255 * sizeof(char));
	FILE * file;
	bool exit;
	do
	{
		exit = true;
		printf("Put the path: ");
		scanf("%s", path);
		file = fopen(path, "r");
		if (!(ReadStudents(&students, &sizeOfStudents, file)))
		{
			printf("Can't open the file.\n");
			exit = false;
		}
	} while (!exit);

	for (int i = 0; i < sizeOfStudents; i++)
	{
		printf("%s\n%s\n%s\n%s\n", students[i].firstName, students[i].lastName,
			students[i].patronyminc, students[i].group);
	}
	//FillStudents(students, &sizeOfStudents);

	do
	{
		exit = true;
		printf("Put the path: ");
		scanf("%s", path);
		file = fopen(path, "a+");
		if (!(WriteStudents(students, sizeOfStudents, file)))
		{
			printf("Can't write.\n");
			exit = false;
		}
	} while (!exit);

#if _DEBUG
	finishWorkProgramm = clock();
	float result = float(finishWorkProgramm - startWorkProgramm) / CLK_TCK;
	printf("Time of work programm: %f", result);
#endif
	return 0;
}
 