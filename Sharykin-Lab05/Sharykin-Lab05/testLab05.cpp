/**  
* @file testLab05.cpp 
* �������� ����������� ������. 
* @author ������ ���������
* @version 0.0.1  
* @date 2018.09.20  */

int main()
{
	//������ � ������ ���������.
	//���������� ���������� ������� � ���������.
	///endSentence - ������� ����, ��� ������� ����� ������� ��� �����.
	///isGlasni - ������� ����, ��� �������, �� � ����� �������.
	///COUNT_GOLOSNI - ������� ��������(� ��������� �������.
	///golosni[COUNT_GOLOSNI] - ����� �������� ����.
	///sentence[] - �����, ���� ������ �������.
	bool endSentence = false, isGlasni;
	const int COUNT_GOLOSNI = 20;
	int countGlasni = 0, countSoglasni = 0;
	char golosni[COUNT_GOLOSNI] = { '�', '�', '�', '�', '�', '�', '�', '�', '�',
	'�', '�', '�', '�', '�', '�', '�', '�', '�'};
	char sentence[] = "�� ��� �����, ����?";
	for (int i = 0; sentence[i] != '\0'; i++)
	{
		isGlasni = false;
		for (int j = 0; j < COUNT_GOLOSNI; j++)
		{
			if (sentence[i] == golosni[j])
			{
				countGlasni++;
				isGlasni = true;
				break;
			}
			else if(sentence[i] == '.' || sentence[i] == '?' || 
				sentence[i] == '!')
			{ 
				isGlasni = true;
				endSentence = true;
				break;
			}
			else if (sentence[i] == ',' || sentence[i] == '/' || sentence[i] == ' ')
			{
				isGlasni = true;
				break;
			}
		}
		if (isGlasni == false)
		{
			countSoglasni++;
		}
		if (endSentence == true)
		{
			break;
		}
	}

	/*
	������ ���������
	�������� ��� ����� � ������� �� ������������ ����� � �������
	*/

	const int SIZE_MAS_NUM = 10;
	int maxNum = 0;
	int massiveNum[SIZE_MAS_NUM];
	for (int i = 0; i < SIZE_MAS_NUM; i++)
	{
		if (i % 2 == 0)
		{
			massiveNum[i] = -(i + 2);
		}
		else
		{
			massiveNum[i] = i + 2;
		}
	}

	for (int j = 0; j < SIZE_MAS_NUM; j++)
	{
		if (massiveNum[j] > maxNum)
		{
			maxNum = massiveNum[j];
		}
	}

	for (int k = 0; k < SIZE_MAS_NUM; k++)
	{
		massiveNum[k] = maxNum;
	}

	/*
	��������� ���������
	����� ������� �������� ����� � �������
	*/

	const int SIZE_ARRAY_NUMBERS = 16;
	int arrNumbers[SIZE_ARRAY_NUMBERS];
	float sum = 0, result;
	for (int i = 0; i < SIZE_ARRAY_NUMBERS; i++)
	{
		if (i % 2 == 0)
		{
			arrNumbers[i] = i + 2;
		}
		else
		{
			arrNumbers[i] = i + 4;
		}
	}

	for (int j = 0; j < SIZE_ARRAY_NUMBERS; j++)
	{
		sum += arrNumbers[j];
	}

	result = sum / SIZE_ARRAY_NUMBERS;

	/*
	����� ���������
	����� ��������� ������������� � ������������ �������� � �������
	*/


	return 0;
}