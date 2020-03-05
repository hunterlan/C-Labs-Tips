#include"Tasks.h"
/**
* @file Tasks.cpp
* Файл, у якому реалізовані прототипі функції з Tasks.h
* @author Шарикін Костянтин
* @version 1.0
* @date 2018.10.29
*/

/**
* Функція, яка перевіряє, чи позиція більше розміру.<br>
* Послідовність дій:
* <ul>
* <li>Якщо розмір менш за позицію, то тоді ми від позиції віднімаємо значення розмір 
* символьного масиву</li>
* <li>Якщо розмір дорівнює позіції, то ми віднімаємо 1</li>
* </ul>
* * \param size - розмір символьного масиву
* * \param pos - якась позиція
*/

void CheckPos(int size, int * pos)
{
	if (size < *pos)
	{
		*pos -= size;
	}
	else if (size == *pos)
	{
		*pos -= 1;
	}
}

/**
* Функція, яка перевіряє, чи позиція від'ємна<br>
* Послідовність дій:
* <ul>
* <li>Якщо позиція менш, ніж 0, тоді ми робимо позицию додатнє
* </ul>
* \param pos - якась позиція
*/


void CheckPosNotNegative(int * pos)
{
	{
		if (pos < 0)
		{
			*pos = -*pos;
		}
	}
}

/**
* 20. «Зашифрувати» вхідний текст, для чого в кожному рядку тексту виконати циклічну перестановку символів
* на n позицій вправо ( i-й символ стає i+1-м, а останній – першим). Значення n ввести з клавіатури.
* Функція, яка шифрує текст<br>
* Опис змінних:<br>
* int size - розмір одержуваємого символьного масиву<br>
* char * temp - тимчасивой буфер символьного масиву<br>
* Послідовність дій:
* <ul>
* <li>Cтворення змінних</li>
* <li>Копює масив та додаємо \0</li>
* <li>Шифруємо текст у циклі методом перестановкі</li>
* </ul>
* \param txt - символьни масив, якій потрібно зашифрувати
* \param countShift - кількість перестановок у тексті
*/

void Encryption(char * txt, int countShift)
{
	int size = strlen(txt);
	char * temp = (char *)malloc(size+1 * sizeof(char));
	for (int i = 0; i < size; i++)
	{
		temp[i] = txt[i];
	}
	temp[size] = '\0';
	for (int i = 0; i < countShift; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j + 1 == size)
			{
				txt[j] = temp[0];
			}
			else
			{
				txt[j] = temp[j + 1];
			}
		}
	}
	free(temp);
}
/**
* Функція, яка дешифровує текст
* Опис змінних:<br>
* int size - розмір одержуваємого символьного масиву<br>
* char * temp - тимчасивой буфер символьного масиву<br>
* Послідовність дій:
* <ul>
* <li>Cтворення змінних</li>
* <li>Копює масив та додаємо \0</li>
* <li>Дешифруємо текст у циклі методом перестановкої</li>
* </ul>
* \param txt - символьни масив, якій потрібно дешифрувати
* \param countShift - кількість перестановок у тексті
*/
void Decryption(char * txt, int countShift)
{
	int size = strlen(txt);
	char * temp = (char *)malloc(size + 1 * sizeof(char));
	for (int i = 0; i < size; i++)
	{
		temp[i] = txt[i];
	}
	temp[size] = '\0';
	for (int i = 0; i < countShift; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j == 0)
			{
				txt[j] = temp[size-1];
			}
			else
			{
				txt[j] = temp[j - 1];
			}
		}
	}
	free(temp);
}