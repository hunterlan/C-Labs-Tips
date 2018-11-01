#include"Tasks.h"
/**
* @mainpage
* <b> Лабораторна робота № 10. <br/>  Рядки типу char*  </b>
* <br/><b><i>Мета роботи:</i></b>: придбати практичні навички щодо
* розроблення програм з використанням рядків на мові С.  <br/>
* <b>1 Завдання до роботи <br/> Основне завдання  <br/> </b>
* 1. виконати завдання на «задовільно»;<br />
* 2. Розробити функцію, яка реалізує вставку в рядок «s»
* другий рядок «s2» в «i»-у позицію рядка «s». Наприклад,
* insert(“abrakadabra”, “TEXT2”, 4) повинна створити рядок
* «abraTEXT2kadabra»;  <br/>
* 3. Розробити функцію видалення з рядка «s» усіх символів з
* індексами в заданому діапазоні.
* Наприклад, reduce(“abrakadabra”, 4, 8) повинна створити
* рядок «abrara»  (без підрядка kadab).  <br/>
* <b><i>Індивідуальне завдання:</i></b>
* «Зашифрувати» вхідний текст, для чого в кожному рядку тексту
* виконати циклічну перестановку символів на n позицій вправо
* (i-й символ стає i+1-м, а останній – першим).
* Значення n ввести з клавіатури. <br/>
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


void Insert(char * txt1, char * txt2, int pos);

void DeleteCharFromText(char * txt, int pos1, int pos2);


/**
* Головна функція.<br>
* Опис змінних:
* char demo1[], demo2[], demo3[] - символьний масив
* int userWantsShift - цілочислений тип, у якому зберігається значення, скільки буде перестановок
* у тексті
* Послідовність дій:
* <ul>
* <li>Cтворення змінних</li>
* <li>Прохаємо користувача написати кількість перестановок у тексті</li>
* <li>Переносимо значення у змінну</li>
* <li>Викликаємо функції {@link Encryption} и {@link Decryption} та виводимо результат у консоль</li>
* </ul>
* @return успешний код повернення з програми (0)
*/
int main()
{
	char demo1[] = "abrakadabra"; 
	char demo2[] = "TEXT2";
	char demo3[] = "Secret Programming";
	//Insert(demo1, demo2, 4);
	//DeleteCharFromText(demo1, 4, 8);
	int userWantsShift = 0;
	printf("How many times we must shift the text? ");
	scanf_s("%i", &userWantsShift);
	Encryption(demo3, userWantsShift);
	printf("\n");
	printf("It's resual encryption, sir: \n");
	printf("%s", demo3);
	Decryption(demo3, userWantsShift);
	printf("\n");
	printf("It's resual decryption, sir: ");
	printf("%s", demo3);
	return 0;
}

/**
* Функція для вставкі другого тексту у перший.<br>
* Опис змінних:<br>
* int sizeTxt1, sizeTxt2 - розмір двух передаваємих текстів<br>
* int sizeResult - розмір результуючего масиву<br>
* int i, j, k - лічильники.<br>
* char * result - масив символів.<br>
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

void Insert(char * txt1, char * txt2, int pos)
{
	int sizeTxt1, sizeTxt2, sizeResult, i = 0, j = 0, k = 0;
	char * result;
	sizeTxt1 = strlen(txt1);
	sizeTxt2 = strlen(txt2);
	CheckPosNotNegative(&pos);
	CheckPos(sizeTxt1, &pos);
	sizeResult = sizeTxt1 + sizeTxt2;
	result = (char *)malloc(sizeResult  * sizeof(char));
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
	free(result);
}

/**
* Функція для очищеня буквів у заданому діапозоні<br>
* Опис змінних:<br>
* int sizeTxtрозмір двух передаваємого тексту<br>
* int sizeResult - розмір результуючего масиву<br>
* int k - лічильники.<br>
* char * result - масив символів.<br>
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

void DeleteCharFromText(char * txt, int pos1, int pos2)
{
	char * result;
	int sizeTxt, sizeResult, k = 0;
	CheckPosNotNegative(&pos1);
	CheckPosNotNegative(&pos2);
	sizeTxt = strlen(txt);
	sizeResult = sizeTxt - (pos2 - pos1);
	result = (char *)malloc(sizeResult * sizeof(char));
	CheckPos(sizeTxt, &pos1);
	CheckPos(sizeTxt, &pos2);
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
	free(result);
}