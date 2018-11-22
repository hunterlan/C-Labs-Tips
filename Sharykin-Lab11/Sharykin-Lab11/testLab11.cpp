#define _CRT_SECURE_NO_WARNINGS
#include"WorkWithArr.h"
#include"WriteAndRead.h"

/**
* @mainpage
* <b> Лабораторна робота № 11. <br/>   Файли  </b>
* <br/><b><i>Мета роботи:</i></b>: Придбати практичні навички щодо 
* розроблення програм із використанням файлів для завантаження та збереження даних. <br/>
* <b>1 Завдання до роботи <br/> Основне завдання  <br/> </b>
* У програму, що розроблена в попередній лабораторній роботі (робота з рядками), 
* виконати наступні зміни: <br>
* 1. Читання даних виконувати не з клавіатури, а з файлу. При цьому функція, що читає дані, 
* не повинна мати в собі ім’я файлу. Ім’я файлу має передаватися як аргумент функції;<br/>
* 2. Видача даних проводиться не у консоль, а у файл. При цьому функція, що записує дані, 
* не повинна мати в  собі ім’я файлу. Ім’я файлу має передаватися як аргумент функції. <br/>
*
* @author Шарикін Костянтин.
* @date 29-oct-2018
* @version 1.0  */

/**
* @file testLab10.cpp
* Головний файл
* @author Шарикін Костянтин
* @version 1.0
* @date 2018.10.29
*/

void DemoInsert();
void DemoDelete();
void DemoEncryption();
void DemoDecryption();

int main()
{
	//DemoInsert();
	//DemoDelete();
	DemoEncryption();
	DemoDecryption();
	return 0;
}

void DemoInsert()
{
	char * nameFile1 = (char * )malloc(255 * sizeof(char));
	char * nameFile2 = (char *)malloc(255 * sizeof(char));
	int pos = 0;
	printf("Write the name of the first file");
	scanf("%s", nameFile1);
	printf("Write the name of the second file");
	scanf("%s", nameFile2);
	//scanf("%d", pos);
	Insert(4, nameFile1, nameFile2);
}

void DemoDelete()
{
	char * nameFile1 = (char *)malloc(255 * sizeof(char));
	printf("Write the name of the file");
	scanf("%s", nameFile1);
	DeleteCharFromText(4, 8, nameFile1);
}

void DemoEncryption()
{
	char * nameFile = (char *)malloc(255 * sizeof(char));
	printf("Write the name of the file");
	scanf("%s", nameFile);
	Encryption(1, nameFile);
}

void DemoDecryption()
{
	char * nameFile = (char *)malloc(255 * sizeof(char));
	printf("Write the name of the file");
	scanf("%s", nameFile);
	Decryption(1, nameFile);
}