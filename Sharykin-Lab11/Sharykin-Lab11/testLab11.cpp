#define _CRT_SECURE_NO_WARNINGS
#include"WorkWithArr.h"
#include"WriteAndRead.h"

/**
* @mainpage
* <b> ����������� ������ � 11. <br/>   �����  </b>
* <br/><b><i>���� ������:</i></b>: �������� �������� ������� ���� 
* ����������� ������� �� ������������� ����� ��� ������������ �� ���������� �����. <br/>
* <b>1 �������� �� ������ <br/> ������� ��������  <br/> </b>
* � ��������, �� ���������� � ��������� ����������� ����� (������ � �������), 
* �������� ������� ����: <br>
* 1. ������� ����� ���������� �� � ���������, � � �����. ��� ����� �������, �� ���� ���, 
* �� ������� ���� � ��� ��� �����. ��� ����� �� ������������ �� �������� �������;<br/>
* 2. ������ ����� ����������� �� � �������, � � ����. ��� ����� �������, �� ������ ���, 
* �� ������� ���� �  ��� ��� �����. ��� ����� �� ������������ �� �������� �������. <br/>
*
* @author ������ ���������.
* @date 29-oct-2018
* @version 1.0  */

/**
* @file testLab11.cpp
* �������� ����
* @author ������ ���������
* @version 1.0
* @date 2018.10.29
*/

void DemoInsert();
void DemoDelete();
void DemoEncryption();
void DemoDecryption();

int main()
{
	//DemoInsert();
	//DemoDelete();
	DemoEncryption();
	DemoDecryption();
	return 0;
}

void DemoInsert()
{
	char * nameFile1 = (char * )malloc(255 * sizeof(char));
	char * nameFile2 = (char *)malloc(255 * sizeof(char));
	int pos = 0;
	printf("Write the name of the first file");
	scanf("%s", nameFile1);
	printf("Write the name of the second file");
	scanf("%s", nameFile2);
	//scanf("%d", pos);
	Insert(4, nameFile1, nameFile2);
}

void DemoDelete()
{
	char * nameFile1 = (char *)malloc(255 * sizeof(char));
	printf("Write the name of the file");
	scanf("%s", nameFile1);
	DeleteCharFromText(4, 8, nameFile1);
}

void DemoEncryption()
{
	char * nameFile = (char *)malloc(255 * sizeof(char));
	printf("Write the name of the file");
	scanf("%s", nameFile);
	Encryption(1, nameFile);
}

void DemoDecryption()
{
	char * nameFile = (char *)malloc(255 * sizeof(char));
	printf("Write the name of the file");
	scanf("%s", nameFile);
	Decryption(1, nameFile);
}