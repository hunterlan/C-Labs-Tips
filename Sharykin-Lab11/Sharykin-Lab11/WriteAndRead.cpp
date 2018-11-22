#define _CRT_SECURE_NO_WARNINGS
#include"WriteAndRead.h"

/**
* Функція, яка читає строки з файлу
* Опис змінних:<br>
* FILE * file - файоловий поток<br>
* Послідовність дій:
* <ul>
* <li>Cтворення змінних</li>
* <li>Перевиряємо, чи існує файл</li>
* <li>Читаємо строки з файлу</li>
* </ul>
* \param txt - символьний масив, у якій потрібно записати строки
* \param nameFile - путь до файлу
*/


void ReadFromFile(char *nameFile, char * txt)
{
	FILE *fp = fopen(nameFile, "a+");
	if (fp == NULL)
	{
		printf("Cannot open file.\n");
	}
	else
	{
		rewind(fp);
		fscanf(fp, "%s", txt);
	}
	fclose(fp);
}

/**
* Функція, яка записує текст у файл
* Опис змінних:<br>
* FILE * file - файоловий поток<br>
* Послідовність дій:
* <ul>
* <li>Cтворення змінних</li>
* <li>Записуємо текст у файл</li>
* </ul>
* \param txt - символьний масив, з якого ми читаємо текст у файлф
* \param nameFile - путь до файлу
*/

void WriteToFile(char * nameFile, char * txt)
{
	FILE *fp = fopen(nameFile, "w+");

	fprintf(fp, "%s", txt);
	fclose(fp);
}


/**
* Функція, яка підрухововає кількість символів у файлу
* Опис змінних:<br>
* FILE * file - файоловий поток<br>
* long sizeTxt - кількість символів у файлу
* Послідовність дій:
* <ul>
* <li>Cтворення змінних</li>
* <li>Перевиряємо, чи існує файл</li>
* <li>Читаємо кількість символів у файлу</li>
* </ul>
* \param nameFile - путь до файлу
*/
long GetLengthSymbInFile(char * nameFile)
{
	long sizeTxt;
	FILE *stream;
	if ((stream = fopen(nameFile, "r")) == NULL)
	{
		printf("Cannot open file.\n");
		sizeTxt = 0;
	}
	else
	{
		fseek(stream, 0, SEEK_END);
		sizeTxt = ftell(stream);
		fseek(stream, 0, SEEK_SET);
	}
	return sizeTxt;
}