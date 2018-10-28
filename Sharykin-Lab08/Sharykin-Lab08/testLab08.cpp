#include"OpsWithArray.h"
#define __CRTDBG_MAP_ALLOC 
#include <crtdbg.h> 
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__) 
#define new DEBUG_NEW 

/**
* @file testLab08.cpp
* �������� ����������� ������
* @author ������ ���������
* @version 0.0.1
* @date 2018.10.01
*/

void Task1();
void Task2();
void Task3();
void Task4();

int main()
{
	srand(time(0));
	Task1();
	Task2();
	Task3();
	Task4();
	_CrtDumpMemoryLeaks();
	return 0;
}
/**
* ����� ��������.
* ���� ���������� ����� � N*N ����� �����. 
* � ������� ����� ������ ������ ������� ������ �������� �����. 
* ������� ���������� �������� � ����������� �����.<br> 
* ���� ������:<br>
* int col = 4 - ����� ��������� �������<br>
* int tmp1, tmp2 - ��������� ��������� ����� � ������<br> 
* int minSize = 1 - ��������� ����� ��������������� �������<br>
* int ** matrix - ��������� �������� �����<br>
* int * matrixTrue - ��������� �����, � ����� ���� ���������� ���������<br>
* int * matrixTemp - ���������� �����, � ����� ���������� ��������� �������� matrixTrue<br>
*/
void Task1()
{

	int col = 4, tmp1, tmp2, minSize = 1;
	//��������� �������� �������, ��� ������� �� �� ������ � ���'��
	int ** matrix = (int **)malloc(col * (sizeof*matrix));

	makingDoubleArr(matrix, col);

	FillArrRandNum(matrix, col, col);
	//��������� ����������� �����, � ����� ���������� ���������
	int * matrixTrue = (int *)malloc(minSize * (sizeof*matrixTrue));
	*(matrixTrue) = 0; //����� ������ �������� ����� ����.
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < col - 1; j++)//����� -1, ����� � ����� ��������� �� ����� �� ������� �������
		{
			tmp1 = *(*(matrix + i) + j);
			tmp2 = *(*(matrix + i) + j + 1);
			if (tmp1 == tmp2 && tmp1 > 0)
			{
				*(matrixTrue + minSize - 1) = tmp1;
				minSize++;
				/*
				��������� ��������� ������, ������� ������ ������ �� ��������������� ������� �� ���
				���, ���� �� �� �������� ������ ��������������� ������� �� 1
				*/
				int * matrixTemp = (int *)malloc(minSize * sizeof*matrixTemp);
				for (int k = 0; k < minSize - 1; k++)
				{
					// ������� ������
					*(matrixTemp + k) = *(matrixTrue + k);
				}
				free(matrixTrue);
				matrixTrue = (int *)malloc(minSize * sizeof*matrixTrue);
				for (int k = 0; k < minSize - 1; k++)
				{
					//���������� ������ � ���������������� ������
					*(matrixTrue + k) = *(matrixTemp + k);
				}
				free(matrixTemp);
			}
		}
	}
	ClearArr(matrix, col);
	free(matrixTrue);
}
//2 �������
void Task2()
{
	int sizeArr = 6, min;
	int ** Array = (int **)malloc(sizeArr * sizeof*Array);
	makingDoubleArr(Array, sizeArr);

	FillArrRandNum(Array, sizeArr, sizeArr);

	int * minArray = (int *)malloc(sizeArr * sizeof*minArray);
	min = (int)*(Array);
	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 1; j < sizeArr; j++)
		{
			if (min < *(*(Array + j) + i))
			{
				min = *(*(Array + j) + i);
			}
		}
		*(minArray + i) = min;
	}
	ClearArr(Array, sizeArr);
	free(minArray);
}
//11 �������
void Task3()
{
	bool isArrEnd = false;

	int sizeArr1 = 6, sizeArr2 = 10;
	int * arrayNum1 = (int *)malloc(sizeArr1 * sizeof*arrayNum1), *arrayNum2 =
		(int *)malloc(sizeArr2 * sizeof*arrayNum2), *arrayNum3 = (int *)
		malloc((sizeArr1 + sizeArr2) * sizeof*arrayNum3);

	FillArrRandNum(arrayNum1, sizeArr1);
	FillArrRandNum(arrayNum2, sizeArr2);
	int i = 0, countOps = 1; //�������� ����� - �� ������� ������� 
	if (sizeArr1 > sizeArr2)
	{
		while (i < sizeArr1)
		{
			if ((i + 1) / sizeArr1 == 0)
			{
				*(arrayNum3 + i) = *(arrayNum1 + i);
			}
			else if (isArrEnd)
			{
				*(arrayNum3 + i) = *(arrayNum1 + i);
				*(arrayNum3 + i + 1) = *(arrayNum1 + i + 1);
			}
			else
			{
				if (countOps % 2 == 0)
				{
					*(arrayNum3 + i) = *(arrayNum1 + i);
					*(arrayNum3 + i + 1) = *(arrayNum1 + i + 1);
				}
				else
				{
					if ((i + 1) / sizeArr2 == 0)
					{
						isArrEnd = true;
						*(arrayNum3 + i) = *(arrayNum2 + i);
					}
					else
					{
						*(arrayNum3 + i) = *(arrayNum2 + i);
						*(arrayNum3 + i + 1) = *(arrayNum2 + i);
					}
				}
				countOps++;
			}
			i++;
		}
	}
	else
	{
		while (i < sizeArr2)
		{
			if ((i + 1) / sizeArr2 == 1)
			{
				*(arrayNum3 + i) = *(arrayNum2 + i);
				break;
			}
			else if (isArrEnd)
			{
				*(arrayNum3 + i) = *(arrayNum2 + i);
				*(arrayNum3 + i + 1) = *(arrayNum2 + i + 1);
			}
			else
			{
				if (countOps % 2 != 0)
				{
					*(arrayNum3 + i) = *(arrayNum2 + i);
					*(arrayNum3 + i + 1) = *(arrayNum2 + i + 1);
				}
				else
				{
					if ((i + 1) / sizeArr1 == 0)
					{
						isArrEnd = true;
						*(arrayNum3 + i) = *(arrayNum1 + i);
					}
					else
					{
						*(arrayNum3 + i) = *(arrayNum1 + i);
						*(arrayNum3 + i + 1) = *(arrayNum1 + i);
					}
				}
				countOps++;
			}
			i++;
		}
	}
	free(arrayNum1);
	free(arrayNum2);
	free(arrayNum3);
}
//����� 9
void Task4()
{
	int sizeArr1 = 6, sizeArr2 = 8;
	int * arrayNum1 = (int *)malloc(sizeArr1 * sizeof*arrayNum1), *arrayNum2 =
		(int *)malloc(sizeArr2 * sizeof*arrayNum2), *arrayNum3 = (int *)
		malloc((sizeArr1 + sizeArr2) * sizeof*arrayNum3);

	FillArrRandNum(arrayNum1, sizeArr1);
	FillArrRandNum(arrayNum2, sizeArr2);

	int k = 0, l = 0;
	if (sizeArr1 < sizeArr2)
	{
		for (int i = 0; i < sizeArr2 + sizeArr1;)
		{
			if (l < sizeArr1)
			{
				*(arrayNum3 + i) = *(arrayNum1 + l);
				i++;
				*(arrayNum3 + i) = *(arrayNum2 + k);
				i++;
				k++;
				l++;
			}
			else
			{
				*(arrayNum3 + i) = *(arrayNum2 + k);
				i++;
				k++;
			}
		}
	}
	else
	{
		for (int j = 0; j < sizeArr1 + sizeArr2; j++)
		{
			if (k < sizeArr2)
			{
				*(arrayNum3 + j) = *(arrayNum1 + l);
				j++;
				*(arrayNum3 + j) = *(arrayNum2 + k);
				j++;
				k++;
				l++;
			}
			else
			{
				*(arrayNum3 + j) = *(arrayNum1 + l);
				j++;
				l++;
			}
		}
	}

	SortFromSmallToBig(arrayNum3, sizeArr1 + sizeArr2);
	free(arrayNum1);
	free(arrayNum2);
	free(arrayNum3);
}
//����� 8
void Task5()
{
	int sizeTwoArr = 5, sizeMainDiagonalArr = sizeTwoArr;
	int ** twoArr = (int **)malloc(sizeTwoArr * sizeof*twoArr);
	int * mainDiagonalArr = (int *)malloc(sizeMainDiagonalArr * sizeof*mainDiagonalArr);

	makingDoubleArr(twoArr, sizeTwoArr);
	FillArrRandNum(twoArr, sizeTwoArr, sizeTwoArr);
	for (int i = 0; i < sizeTwoArr; i++)
	{
		for (int j = 0; j < sizeTwoArr; j++)
		{
			if (i == j)
			{
				*(mainDiagonalArr + i) = *(*(twoArr + j) + i);
			}
		}
	}
	SortFromSmallToBig(mainDiagonalArr, sizeMainDiagonalArr);
	ClearArr(twoArr, sizeTwoArr);
	free(mainDiagonalArr);
}