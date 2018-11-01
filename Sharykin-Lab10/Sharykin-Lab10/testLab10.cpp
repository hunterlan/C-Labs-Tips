#include"Tasks.h"
/**
* @mainpage
* <b> ����������� ������ � 10. <br/>  ����� ���� char*  </b>
* <br/><b><i>���� ������:</i></b>: �������� �������� ������� ����
* ����������� ������� � ������������� ����� �� ��� �.  <br/>
* <b>1 �������� �� ������ <br/> ������� ��������  <br/> </b>
* 1. �������� �������� �� ����������;<br />
* 2. ��������� �������, ��� ������ ������� � ����� �s�
* ������ ����� �s2� � �i�-� ������� ����� �s�. ���������,
* insert(�abrakadabra�, �TEXT2�, 4) ������� �������� �����
* �abraTEXT2kadabra�;  <br/>
* 3. ��������� ������� ��������� � ����� �s� ��� ������� �
* ��������� � �������� �������.
* ���������, reduce(�abrakadabra�, 4, 8) ������� ��������
* ����� �abrara�  (��� ������� kadab).  <br/>
* <b><i>������������ ��������:</i></b>
* ������������ ������� �����, ��� ���� � ������� ����� ������
* �������� ������� ������������ ������� �� n ������� ������
* (i-� ������ ��� i+1-�, � ������� � ������).
* �������� n ������ � ���������. <br/>
*
* @author ������ ���������.
* @date 29-oct-2018
* @version 1.0  */

/**
* @file testLab10.cpp
* �������� ����
* @author ������ ���������
* @version 1.0
* @date 2018.10.29
*/


void Insert(char * txt1, char * txt2, int pos);

void DeleteCharFromText(char * txt, int pos1, int pos2);


/**
* ������� �������.<br>
* ���� ������:
* char demo1[], demo2[], demo3[] - ���������� �����
* int userWantsShift - ������������ ���, � ����� ���������� ��������, ������ ���� ������������
* � �����
* ����������� ��:
* <ul>
* <li>C�������� ������</li>
* <li>������� ����������� �������� ������� ������������ � �����</li>
* <li>���������� �������� � �����</li>
* <li>��������� ������� {@link Encryption} � {@link Decryption} �� �������� ��������� � �������</li>
* </ul>
* @return �������� ��� ���������� � �������� (0)
*/
int main()
{
	char demo1[] = "abrakadabra"; 
	char demo2[] = "TEXT2";
	char demo3[] = "Secret Programming";
	//Insert(demo1, demo2, 4);
	//DeleteCharFromText(demo1, 4, 8);
	int userWantsShift = 0;
	printf("How many times we must shift the text? ");
	scanf_s("%i", &userWantsShift);
	Encryption(demo3, userWantsShift);
	printf("\n");
	printf("It's resual encryption, sir: \n");
	printf("%s", demo3);
	Decryption(demo3, userWantsShift);
	printf("\n");
	printf("It's resual decryption, sir: ");
	printf("%s", demo3);
	return 0;
}

/**
* ������� ��� ������ ������� ������ � ������.<br>
* ���� ������:<br>
* int sizeTxt1, sizeTxt2 - ����� ���� ����������� ������<br>
* int sizeResult - ����� ������������� ������<br>
* int i, j, k - ���������.<br>
* char * result - ����� �������.<br>
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

void Insert(char * txt1, char * txt2, int pos)
{
	int sizeTxt1, sizeTxt2, sizeResult, i = 0, j = 0, k = 0;
	char * result;
	sizeTxt1 = strlen(txt1);
	sizeTxt2 = strlen(txt2);
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

/**
* ������� ��� ������� ����� � �������� �������<br>
* ���� ������:<br>
* int sizeTxt����� ���� ������������ ������<br>
* int sizeResult - ����� ������������� ������<br>
* int k - ���������.<br>
* char * result - ����� �������.<br>
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

void DeleteCharFromText(char * txt, int pos1, int pos2)
{
	char * result;
	int sizeTxt, sizeResult, k = 0;
	CheckPosNotNegative(&pos1);
	CheckPosNotNegative(&pos2);
	sizeTxt = strlen(txt);
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