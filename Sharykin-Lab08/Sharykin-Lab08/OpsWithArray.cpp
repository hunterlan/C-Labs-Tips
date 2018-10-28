#include"OpsWithArray.h"

/**
* @file OpsWithArray.h
* ���������� ������� ��� ������ � ��������
* @author ������ ���������
* @version 0.0.1
* @date 2018.10.01
*/


/**
* ���������� ������ ��� �������� �������� ������
* \param int col - ����� ��� ���������
* \param int ** array - �������� ����� ���� int
*/
void makingDoubleArr(int ** array, int col)
{
	for (int i = 0; i < col; i++)
	{
		//!�������� ������ ��������
		*(array + i) = (int *)malloc(col * sizeof*array);
	}
}
/**
* ���������� �������� �����
* \param int col - ����� ��� ���������
* \param int row - ����� ��� �����
* \param int * array - �������� ����� ���� int
*/
void FillArrRandNum(int ** array, int col, int row)
{
	//!��������� ���������� �������
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			*(*(array + j) + i) = rand() % 50 - 50;
		}
	}
}
/**
* ���������� ��������� �����
* \param int col - ����� ���������� ������
* \param int ** array - ��������� ����� ���� int
*/
void FillArrRandNum(int * array, int col)
{
	for (int i = 0; i < col; i++)
	{
		*(array + i) = rand() % (20 + 10) - 10;
	}
}
/**
* ��������� �� ������������ ��������� �����
* \param int size - ����� ���������� ������
* \param int * array - ��������� ����� ���� int
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
* ������ ���'��� �� ������
* \param int col - ����� ��� ���������
* \param int ** array - �������� ����� ���� int
*/
void ClearArr(int ** array, int col) 
{
	for (int i = 0; i < col; i++)
	{
		free(*(array + i));
	}
	free(array);
}