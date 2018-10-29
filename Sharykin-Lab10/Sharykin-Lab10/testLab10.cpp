#include<stdlib.h>
#include"Tasks.h"
void Insert(char * txt1, char * txt2, int pos);

void DeleteCharFromText(char * txt, int pos1, int pos2);

int main()
{
	char demo1[] = "abrakadabra";
	char demo2[] = "TEXT2";
	char demo3[] = "Secret Programming";
	//Insert(demo1, demo2, 4);
	//DeleteCharFromText(demo1, 4, 8);
	int userWantsShift = 0;
	printf("How many times we must shift the text?");
	scanf_s("%i", &userWantsShift);
	Task1(demo3, 2);
	printf("It's resual, sir: ");
	printf("%s", demo3);
	return 0;
}

void Insert(char * txt1, char * txt2, int pos)
{
	int sizeTxt1, sizeTxt2, sizeResult, i = 0, j = 0, k = 0;
	char * result;
	sizeTxt1 = IdentifySize(txt1);
	sizeTxt2 = IdentifySize(txt2);
	CheckPosNotNegative(&pos);
	CheckPos(sizeTxt1, &pos);
	sizeResult = sizeTxt1 + sizeTxt2;
	result = (char *)malloc(sizeResult  * sizeof(char));
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
	free(result);
}

void DeleteCharFromText(char * txt, int pos1, int pos2)
{
	char * result;
	int sizeTxt, sizeResult, k = 0;
	CheckPosNotNegative(&pos1);
	CheckPosNotNegative(&pos2);
	sizeTxt = IdentifySize(txt);
	sizeResult = sizeTxt - (pos2 - pos1);
	result = (char *)malloc(sizeResult * sizeof(char));
	CheckPos(sizeTxt, &pos1);
	CheckPos(sizeTxt, &pos2);
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
	free(result);
}