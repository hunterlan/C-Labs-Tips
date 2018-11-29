#define _CRT_SECURE_NO_WARNINGS
#include"WriteAndRead.h"

/**
* �������, ��� ���� ������ � �����
* ���� ������:<br>
* FILE * file - ��������� �����<br>
* ����������� ��:
* <ul>
* <li>C�������� ������</li>
* <li>�����������, �� ���� ����</li>
* <li>������ ������ � �����</li>
* </ul>
* \param txt - ���������� �����, � ��� ������� �������� ������
* \param nameFile - ���� �� �����
*/


void ReadFromFile(char *nameFile, char * txt)
{
	FILE *fp = fopen(nameFile, "a+");
	if (fp == NULL)
	{
		printf("Cannot open file.\n");
	}
	else
	{
		rewind(fp);
		fscanf(fp, "%s", txt);
	}
	fclose(fp);
}

/**
* �������, ��� ������ ����� � ����
* ���� ������:<br>
* FILE * file - ��������� �����<br>
* ����������� ��:
* <ul>
* <li>C�������� ������</li>
* <li>�������� ����� � ����</li>
* </ul>
* \param txt - ���������� �����, � ����� �� ������ ����� � �����
* \param nameFile - ���� �� �����
*/

void WriteToFile(char * nameFile, char * txt)
{
	FILE *fp = fopen(nameFile, "w+");

	fprintf(fp, "%s", txt);
	fclose(fp);
}


/**
* �������, ��� ���������� ������� ������� � �����
* ���� ������:<br>
* FILE * file - ��������� �����<br>
* long sizeTxt - ������� ������� � �����
* ����������� ��:
* <ul>
* <li>C�������� ������</li>
* <li>�����������, �� ���� ����</li>
* <li>������ ������� ������� � �����</li>
* </ul>
* \param nameFile - ���� �� �����
*/
long GetLengthSymbInFile(char * nameFile)
{
	long sizeTxt;
	FILE *stream;
	if ((stream = fopen(nameFile, "r")) == NULL)
	{
		printf("Cannot open file.\n");
		sizeTxt = 0;
	}
	else
	{
		fseek(stream, 0, SEEK_END);
		sizeTxt = ftell(stream);
		fseek(stream, 0, SEEK_SET);
	}
	return sizeTxt;
}