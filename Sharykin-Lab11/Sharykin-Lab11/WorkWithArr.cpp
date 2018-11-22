#define _CRT_SECURE_NO_WARNINGS
#include "WorkWithArr.h"

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
	if (pos < 0)
	{
		*pos = -*pos;
	}
}

/**
* Функція для вставкі другого тексту у перший.<br>
* Опис змінних:<br>
* int sizeTxt1, sizeTxt2 - розмір двух передаваємих текстів<br>
* int sizeResult - розмір результуючего масиву<br>
* int i, j, k - лічильники.<br>
* char * result - масив символів.<br>
* char * txt1, txt2 - масивb символів, якій зберігає дані з файлу.<br>
* Послідовність дій:
* <ul>
* <li>Cтворення змінних</li>
* <li>З'ясовуємо розмір передаваємого тексту</li>
* <li>Переверяємо передаваєму позицію за допомогою функції {@link CheckPosNotNegative},
* {@link CheckPos}</li>
* <li>Сумміруєм два розміра та записуємо результат у sizeResult</li>
* <li>Вставляємо другий текст у перший.</li>
* </ul>
* \param txt1 - перший символьний масив
* \param txt2 - другий символьний масив
* \param  pos - після якої букви ми будемо вставляти другий текст у перший
*/

void Insert(int pos, char * nameFile1, char * nameFile2)
{
	char * txt1;
	char * txt2;
	char * result;
	int sizeTxt1, sizeTxt2, sizeResult, i = 0, j = 0, k = 0;

	sizeTxt1 = GetLengthSymbInFile(nameFile1);
	sizeTxt2 = GetLengthSymbInFile(nameFile2);
	CheckPosNotNegative(&pos);
	CheckPos(sizeTxt1, &pos);

	txt1 = (char *)malloc(sizeTxt1 * sizeof(char));
	txt2 = (char *)malloc(sizeTxt2 * sizeof(char));
	ReadFromFile(nameFile1, txt1);
	ReadFromFile(nameFile2, txt2);

	sizeResult = sizeTxt1 + sizeTxt2;
	result = (char *)malloc(sizeResult * sizeof(char));
	for (; i < pos; i++)
	{
		result[k] = txt1[i];
		k++;
	}
	for (; j < sizeTxt2; j++)
	{
		result[k] = txt2[j];
		k++;
	}
	for (; i < sizeTxt1; i++)
	{
		result[k] = txt1[i];
		k++;
	}
	result[sizeResult] = '\0';

	char * nameResultedFile = (char *)malloc((strlen(nameFile1) + 1) * sizeof(char));
	int posDot = 0;
	for (i = 0; i < strlen(nameFile1); i++)
	{
		if (nameFile1[i] == '.')
		{
			posDot = i;
		}
	}
	for (int i = 0; i < (strlen(nameFile1) + 1); i++)
	{
		if (i < posDot)
		{
			nameResultedFile[i] = nameFile1[i];
		}
		else if (i == posDot)
		{
			nameResultedFile[i] = 'N';
		}
		else
		{
			nameResultedFile[i] = nameFile1[i-1];
		}
	}
	nameResultedFile[strlen(nameFile1) + 1] = '\0';
	WriteToFile(nameResultedFile, result);

	//free(nameResultedFile);
	//free(result);
	free(txt1);
	free(txt2);
}

/**
* Функція для очищеня буквів у заданому діапозоні<br>
* Опис змінних:<br>
* int sizeTxtрозмір двух передаваємого тексту<br>
* int sizeResult - розмір результуючего масиву<br>
* int k - лічильники.<br>
* char * result - масив символів.<br>
* char * txt - масив символів, якій зберігає дані з файлу.<br>
* Послідовність дій:
* <ul>
* <li>Cтворення змінних</li>
* <li>З'ясовуємо розмір передаваємого тексту</li>
* <li>Переверяємо передаваєму позицію за допомогою функції {@link CheckPosNotNegative},
* {@link CheckPos}</li>
* <li>Находимо результуючий розмір та записуємо результат у sizeResult</li>
* <li>Очищаємо букви у діапозоні</li>
* </ul>
* \param txt - символьний масив
* \param pos1 - діапозон "від"
* \param pos2 - діапозон "до"
*/


void DeleteCharFromText(int pos1, int pos2, char * nameFile)
{
	char * txt;
	char * result;
	int sizeTxt, sizeResult, k = 0;
	CheckPosNotNegative(&pos1);
	CheckPosNotNegative(&pos2);

	sizeTxt = GetLengthSymbInFile(nameFile);

	CheckPos(sizeTxt, &pos1);
	CheckPos(sizeTxt, &pos2);

	sizeResult = sizeTxt - (pos2 - pos1);
	result = (char *)malloc(sizeResult * sizeof(char));
	txt = (char *)malloc(sizeResult * sizeof(char));

	ReadFromFile(nameFile, txt);

	for (int i = 0; i < pos1; i++)
	{
		result[k] = txt[i];
		k++;
	}

	for (int i = pos2; i < sizeTxt; i++)
	{
		result[k] = txt[i];
		k++;
	}

	result[sizeResult] = '\0';

	char nameResultedFile[] = "ResultDeletingChars.txt";
	WriteToFile(nameResultedFile, result);
	
	//free(result);
}


/**
* Функція, яка шифрує текст<br>
* Опис змінних:<br>
* int size - розмір одержуваємого символьного масиву<br>
* char * temp - тимчасивой буфер символьного масиву<br>
* char * txt - масив символів, якій зберігає дані з файлу.<br>
* Послідовність дій:
* <ul>
* <li>Cтворення змінних</li>
* <li>Копює масив та додаємо \0</li>
* <li>Шифруємо текст у циклі методом перестановкі</li>
* </ul>
* \param txt - символьни масив, якій потрібно зашифрувати
* \param countShift - кількість перестановок у тексті
*/

void Encryption(int countShift, char * nameFile)
{
	char * txt;
	int size = GetLengthSymbInFile(nameFile);
	txt = (char *)malloc(size * sizeof(char));
	char * temp = (char *)malloc(size + 1 * sizeof(char));
	ReadFromFile(nameFile, txt);
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

	char NameEncryption[] = "ResultEncrypted.txt";
	WriteToFile(NameEncryption, txt);
	free(temp);
}

/**
* Функція, яка дешифровує текст
* Опис змінних:<br>
* int size - розмір одержуваємого символьного масиву<br>
* char * temp - тимчасивой буфер символьного масиву<br>
* char * txt - масив символів, якій зберігає дані з файлу.<br>
* Послідовність дій:
* <ul>
* <li>Cтворення змінних</li>
* <li>Копює масив та додаємо \0</li>
* <li>Дешифруємо текст у циклі методом перестановкої</li>
* </ul>
* \param txt - символьни масив, якій потрібно дешифрувати
* \param countShift - кількість перестановок у тексті
*/
void Decryption(int countShift, char * nameFile)
{
	char * txt;
	int size = GetLengthSymbInFile(nameFile);
	txt = (char *)malloc(size * sizeof(char));
	char * temp = (char *)malloc(size + 1 * sizeof(char));
	ReadFromFile(nameFile, txt);
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
				txt[j] = temp[size - 1];
			}
			else
			{
				txt[j] = temp[j - 1];
			}
		}
	}

	char NameDecryption[] = "ResultDecrypted.txt";
	WriteToFile(NameDecryption, txt);

	free(temp);
}