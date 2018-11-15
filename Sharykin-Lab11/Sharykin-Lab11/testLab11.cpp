#define _CRT_SECURE_NO_WARNINGS
#include"WorkWithArr.h"
#include"WriteAndRead.h"
void DemoInsert();

int main()
{
	DemoInsert();
	return 0;
}

void DemoInsert()
{
	char * nameFile1 = (char * )malloc(255 * sizeof(char));
	char * nameFile2 = (char *)malloc(255 * sizeof(char));
	int pos = 0;
	scanf("%s", nameFile1);
	scanf("%s", nameFile2);
	//scanf("%d", pos);
	Insert(4, nameFile1, nameFile2);
}