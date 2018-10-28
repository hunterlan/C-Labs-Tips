/**
* @file testLab07.cpp
* �������� ����������� ������
* @author ������ ���������
* @version 0.0.1
* @date 2018.10.11
*/
#include<stdlib.h>
#include<time.h>

const int N = 5;
const int M = 5;
const int sizeArr = M * N;

void GenRandNum(int * array, int size);
void Tranforming(int * array, int choosenTask);
void Task1(int dvoArr[][M], const int col, const int row);
void Task2(int dvoArr[][M], const int col, const int row);
void Task3(int dvoArr[][M], const int col, const int row);
void Task4(int dvoArr[][M], const int col, const int row);
void Task5(int dvoArr[][M], const int col, const int row);


int main()
{
	srand(time(0));
	int numArr[sizeArr];
	GenRandNum(numArr, sizeArr);
	Tranforming(numArr, 5);
	return 0;
}

/**
* �������, ��� ������ ��� ������ ������ �����
* \param int size - ����� ������
* \param int * array - ��������� ����� ���� int
*/

void GenRandNum(int * array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % (20 + 10) - 10;
	}
}

/**
* �������, ��� ���������� � ���������� � �������� �����
* \param int choosenTask - ���� ������
* \param int * array - ��������� ����� ���� int
*/

void Tranforming(int * array, int choosenTask)
{
	int doubleArr[N][M];
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			doubleArr[i][j] = array[k];
			k++;
		}
	}
	switch (choosenTask)
	{
	case 1:
	{
		Task1(doubleArr, N, M);
	}break;
	case 2:
	{
		Task2(doubleArr, N, M);
	}break;
	case 3:
	{
		Task3(doubleArr, N, M);
	}break;
	case 4:
	{
		Task4(doubleArr, N, M);
	}break;
	case 5:
	{
		Task5(doubleArr, N, M);
	}break;
	default:
		break;
	}
	k = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			array[k] = doubleArr[i][j];
			k++;
		}
	}
}
/*!
���� ���������� ����� � N*N ����� �����. 
�������� ������� ������� �������� � ��������� �����, ��������� ����� ������������ �� ����������.
<br>
���� ������:
int resultDiag[N] - �����, � ����� ���������� ���������
\param const int col - ����� ��������
\param const int row - ����� �����
\param int dvoArr[][M] - �������� ��������� ����� ���� int
*/
void Task1(int dvoArr[][M], const int col, const int row)
{
	int resultDiag[N];
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (i == j)
			{
				resultDiag[i] = dvoArr[i][j];
			}
		}
	}
}
/*18. ���� ���������� ����� � N*N ����� �����.
�������� ������� �������� �������� ����� ������ � ��������
���� ������� (������� ������� ����� ������� ������������ �
�� �������).*/
void Task2(int dvoArr[][M], const int col, const int row)
{
	int tempArr[N][M];
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (j == row - 1)
			{
				tempArr[i][j] = dvoArr[i][0];
			}
			else
			{
				tempArr[i][j] = dvoArr[i][j + 1];
			}
		}
	}
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			dvoArr[i][j] = tempArr[i][j];
		}
	}
}
/*
19. ���� ���������� ����� � N*N ����� �����.
������� ������ ������������ � ��������� �������� ������.
*/
void Task3(int dvoArr[][M], const int col, const int row)
{
	int min = dvoArr[0][0], max = dvoArr[0][0], posMinI,
		posMinJ, posMaxI, posMaxJ, temp;
	for (int i = 0; i < col; i++)
	{
		for (int j = 1; j < row; j++)
		{
			if (min > dvoArr[i][j])
			{
				min = dvoArr[i][j];
				posMinI = i;
				posMinJ = j;
			}
			if (max < dvoArr[i][j])
			{
				max = dvoArr[i][j];
				posMaxI = i;
				posMaxJ = j;
			}
		}
	}
	temp = dvoArr[posMinI][posMinJ];
	dvoArr[posMinI][posMinJ] = dvoArr[posMaxI][posMaxJ];
	dvoArr[posMaxI][posMaxJ] = temp;
}
/*
 ���� ���������� ����� � N*N ����� �����. ������������� ����
*/
void Task4(int dvoArr[][M], const int col, const int row)
{
	int tempDvoArr[N][M];
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			tempDvoArr[j][i] = dvoArr[i][j];
		}
	}
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			dvoArr[i][j] = tempDvoArr[i][j];
		}
	}
}

/*
���� ���������� ����� � N*N ����� �����.
�������� ������� �������� �������� ����� ������ � �������� ������ ����� (������ ������� ����� ������� ������������ � �� �����).
*/
void Task5(int dvoArr[][M], const int col, const int row)
{
	
}