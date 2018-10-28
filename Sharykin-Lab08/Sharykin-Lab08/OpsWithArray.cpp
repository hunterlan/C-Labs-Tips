#include"OpsWithArray.h"

/**
* @file OpsWithArray.h
* Описування функції для роботи з массивом
* @author Шарикін Костянтин
* @version 0.0.1
* @date 2018.10.01
*/


/**
* Добавляємо адреса для значення двумірних масивів
* \param int col - розмір для стовпчиків
* \param int ** array - двумірний масив типу int
*/
void makingDoubleArr(int ** array, int col)
{
	for (int i = 0; i < col; i++)
	{
		//!выделяем память столбцам
		*(array + i) = (int *)malloc(col * sizeof*array);
	}
}
/**
* Заповнюємо двумірний масив
* \param int col - розмір для стовпчиків
* \param int row - розмір для рядків
* \param int * array - двумірний масив типу int
*/
void FillArrRandNum(int ** array, int col, int row)
{
	//!Заполняем случайными числами
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			*(*(array + j) + i) = rand() % 50 - 50;
		}
	}
}
/**
* Заповнюємо одномірний масив
* \param int col - розмір одномірного масиву
* \param int ** array - одномірний масив типу int
*/
void FillArrRandNum(int * array, int col)
{
	for (int i = 0; i < col; i++)
	{
		*(array + i) = rand() % (20 + 10) - 10;
	}
}
/**
* Сортируємо за возрастанням одномірний масив
* \param int size - розмір одномірного масиву
* \param int * array - одномірний масив типу int
*/
void SortFromSmallToBig(int * array, int size)
{
	int tmp, num;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (*(array+j) < *(array + j + 1))
			{
				tmp = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = tmp;
			}
			else//code it when notDebug. Uncode when Debug
			{
				num = *(array + j);
			}
		}
	}
}
/**
* Очищаєм пам'ять від масиву
* \param int col - розмір для стовпчиків
* \param int ** array - двумірний масив типу int
*/
void ClearArr(int ** array, int col) 
{
	for (int i = 0; i < col; i++)
	{
		free(*(array + i));
	}
	free(array);
}