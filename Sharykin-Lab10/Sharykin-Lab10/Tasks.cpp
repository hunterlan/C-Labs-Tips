#include"Tasks.h"
/**
* @file Tasks.cpp
* ����, � ����� ��������� �������� ������� � Tasks.h
* @author ������ ���������
* @version 1.0
* @date 2018.10.29
*/

/**
* �������, ��� ��������, �� ������� ����� ������.<br>
* ����������� ��:
* <ul>
* <li>���� ����� ���� �� �������, �� ��� �� �� ������� ������� �������� ����� 
* ����������� ������</li>
* <li>���� ����� ������� ������, �� �� ������� 1</li>
* </ul>
* * \param size - ����� ����������� ������
* * \param pos - ����� �������
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
* �������, ��� ��������, �� ������� ��'����<br>
* ����������� ��:
* <ul>
* <li>���� ������� ����, �� 0, ��� �� ������ ������� ������
* </ul>
* \param pos - ����� �������
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
* 20. ������������ ������� �����, ��� ���� � ������� ����� ������ �������� ������� ������������ �������
* �� n ������� ������ ( i-� ������ ��� i+1-�, � ������� � ������). �������� n ������ � ���������.
* �������, ��� ����� �����<br>
* ����������� ��:
* <ul>
* <li>C�������� ������</li>
* <li>����� ����� �� ������ \0</li>
* <li>������� ����� � ���� ������� �����������</li>
* </ul>
* \param txt - ��������� �����, ��� ������� �����������
* \param countShift - ������� ������������ � �����
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
* �������, ��� ��������� �����
* ����������� ��:
* <ul>
* <li>C�������� ������</li>
* <li>����� ����� �� ������ \0</li>
* <li>��������� ����� � ���� ������� ������������</li>
* </ul>
* \param txt - ��������� �����, ��� ������� �����������
* \param countShift - ������� ������������ � �����
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