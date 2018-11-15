#define _CRT_SECURE_NO_WARNINGS
#include"WriteAndRead.h"


void ReadFromFile(char *nameFile, char * txt)
{
	FILE *fp = fopen(nameFile, "w+");
	if (fp == NULL)
	{
		printf("Cannot open file.\n");
	}
	else
	{
		rewind(fp);
		fscanf_s(fp, "%s", txt);
	}
	fclose(fp);
}

void WriteToFile(char * nameFile, char * txt)
{
	FILE *fp;
	if ((fp = fopen(nameFile, "w")) == NULL)
	{
		printf("Cannot open file.\n");
	}
	else
	{
		fprintf_s(fp, "%s", txt);
	}
	fclose(fp);
}

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