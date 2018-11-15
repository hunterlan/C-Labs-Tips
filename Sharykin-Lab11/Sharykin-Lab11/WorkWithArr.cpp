#define _CRT_SECURE_NO_WARNINGS
#include "WorkWithArr.h"

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
	if (pos < 0)
	{
		*pos = -*pos;
	}
}

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
		if (nameFile1[i] == (char)".")
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
			nameResultedFile[i] = (char)"N";
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

void DeleteCharFromText(int pos2, char * nameFile)
{
	char * txt;
}

void Encryption(int countShift, char * nameFile)
{
	char * txt;
}

void Decryption(int countShift, char * nameFile)
{
	char * txt;
}