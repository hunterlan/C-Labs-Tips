#include"Tasks.h"
int IdentifySize(char * txt)
{
	int i = 0;
	while (txt[i] != '\0')
	{
		i++;
	}
	return i;
}

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

void CheckPosNotNegative(int * pos)
{
	{
		if (pos < 0)
		{
			*pos = -*pos;
		}
	}
}

/*!
20. ������������ ������� �����, ��� ���� � ������� ����� ������ �������� ������� ������������ �������
�� n ������� ������ ( i-� ������ ��� i+1-�, � ������� � ������). �������� n ������ � ���������.
*/

void Encryption(char * txt, int countShift)
{
	int size = IdentifySize(txt);
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
				txt[j] = temp[size];
			}
			else
			{
				txt[j] = temp[j - 1];
			}
		}
	}
	free(temp);
}