#define _CRT_SECURE_NO_WARNINGS
#include "WorkWithArr.h"

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
	if (pos < 0)
	{
		*pos = -*pos;
	}
}

/**
* ������� ��� ������ ������� ������ � ������.<br>
* ���� ������:<br>
* int sizeTxt1, sizeTxt2 - ����� ���� ����������� ������<br>
* int sizeResult - ����� ������������� ������<br>
* int i, j, k - ���������.<br>
* char * result - ����� �������.<br>
* char * txt1, txt2 - �����b �������, ��� ������ ��� � �����.<br>
* ����������� ��:
* <ul>
* <li>C�������� ������</li>
* <li>�'������� ����� ������������ ������</li>
* <li>����������� ���������� ������� �� ��������� ������� {@link CheckPosNotNegative},
* {@link CheckPos}</li>
* <li>������� ��� ������ �� �������� ��������� � sizeResult</li>
* <li>���������� ������ ����� � ������.</li>
* </ul>
* \param txt1 - ������ ���������� �����
* \param txt2 - ������ ���������� �����
* \param  pos - ���� ��� ����� �� ������ ��������� ������ ����� � ������
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
* ������� ��� ������� ����� � �������� �������<br>
* ���� ������:<br>
* int sizeTxt����� ���� ������������ ������<br>
* int sizeResult - ����� ������������� ������<br>
* int k - ���������.<br>
* char * result - ����� �������.<br>
* char * txt - ����� �������, ��� ������ ��� � �����.<br>
* ����������� ��:
* <ul>
* <li>C�������� ������</li>
* <li>�'������� ����� ������������ ������</li>
* <li>����������� ���������� ������� �� ��������� ������� {@link CheckPosNotNegative},
* {@link CheckPos}</li>
* <li>�������� ������������ ����� �� �������� ��������� � sizeResult</li>
* <li>������� ����� � �������</li>
* </ul>
* \param txt - ���������� �����
* \param pos1 - ������� "��"
* \param pos2 - ������� "��"
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
* �������, ��� ����� �����<br>
* ���� ������:<br>
* int size - ����� ������������ ����������� ������<br>
* char * temp - ���������� ����� ����������� ������<br>
* char * txt - ����� �������, ��� ������ ��� � �����.<br>
* ����������� ��:
* <ul>
* <li>C�������� ������</li>
* <li>����� ����� �� ������ \0</li>
* <li>������� ����� � ���� ������� �����������</li>
* </ul>
* \param txt - ��������� �����, ��� ������� �����������
* \param countShift - ������� ������������ � �����
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
* �������, ��� ��������� �����
* ���� ������:<br>
* int size - ����� ������������ ����������� ������<br>
* char * temp - ���������� ����� ����������� ������<br>
* char * txt - ����� �������, ��� ������ ��� � �����.<br>
* ����������� ��:
* <ul>
* <li>C�������� ������</li>
* <li>����� ����� �� ������ \0</li>
* <li>��������� ����� � ���� ������� ������������</li>
* </ul>
* \param txt - ��������� �����, ��� ������� �����������
* \param countShift - ������� ������������ � �����
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