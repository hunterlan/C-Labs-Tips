#include"Structs.h"

/**
* @file Struct.cpp
* Реалізація функції структур. 
* @author Шарикін Костянтин
* @version 1.0
* @date 2018.11.25
*/


/*!
Ця функція показує значення змінних у структурі "Студент"
*/
void Student::ShowData()
{
	printf("Frist name: %s", &firstName);
	printf("\nLast name: %s", &lastName);
	printf("\nPatronymic: %s", &patronyminc);
	printf("\nHome adress:\n\t   Country: %s", &country);
	printf("\n\t   Discrict: %s", &disctrict);
	printf("\n\t   City: %s", &city);
	printf("\nPhone number: %s", &phoneNumber);
	if (isLiveInHostel == 1)
	{
		printf("\nLive in hostel: true");
	}
	else
	{
		printf("\nLive in hostel: false");
	}
	if (isGetAScholarship == 1)
	{
		printf("\nGetting a scholar ship: true");
	}
	else
	{
		printf("\nGetting a scholar ship: true");
	}
	printf("\nFirst mark of exam: %.3f", markZNO[0]);
	printf("\nSecond mark of exam: %.3f", markZNO[1]);
	printf("\nThird mark of exam: %.3f", markZNO[2]);
	printf("\n");
}

/*!
Ця функція показує значення змінних у структурі "Робітник"
*/
void Worker::ShowData()
{
	printf("Frist name: %s", &firstName);
	printf("\nLast name: %s", &lastName);
	printf("\nPatronymic: %s", &patronyminc);
	printf("Birthday:\n");
	printf("\t\tYear: ", birthday[0]);
	printf("\n\t\tMonth: ", birthday[1]);
	printf("\n\t\tDay: ", birthday[2]);
	printf("\nPosition: %s", &position);
	printf("\nSalary: %d", salary);
	if (isWorkerTeacher == 1)
	{
		printf("\nWorker is teacher: true\n");
	}
	else
	{
		printf("\nWorker is teacher: false\n");
	}
}