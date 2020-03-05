#include "stdafx.h"
#include "Students.h"

/**
* @file Student.cpp
* ��������� ��������� �������
* @author ������ ���������
* @version 1.0
* @date 2018.12.03
*/
void Student::ShowData()
{
	printf("Frist name: %s", &firstName);
	printf("\nLast name: %s", &lastName);
	printf("\nPatronymic: %s", &patronyminc);
	printf("\nHome adress:\n\t   Country: %s", &country);
	printf("\n\t   Discrict: %s", &disctrict);
	printf("\n\t   City: %s", &city);
	printf("\nPhone number: %s", &phoneNumber);
	if (isLiveInHostel == 1)
	{
		printf("\nLive in hostel: true");
	}
	else
	{
		printf("\nLive in hostel: false");
	}
	if (isGetAScholarship == 1)
	{
		printf("\nGetting a scholar ship: true");
	}
	else
	{
		printf("\nGetting a scholar ship: true");
	}
	printf("\nFirst mark of exam: %.3f", markZNO[0]);
	printf("\nSecond mark of exam: %.3f", markZNO[1]);
	printf("\nThird mark of exam: %.3f", markZNO[2]);
	printf("\n");
}

bool ReadStudents(struct Student * students, int * sizeStudents, FILE * file)
{
	char temp[6][50];
	bool isSuccesful = false;
	if (file != NULL)
	{
		rewind(file);
		int k = 0;
		while (1)
		{
			*sizeStudents += 1;
			students = (Student *)realloc(students, *sizeStudents * sizeof(Student));
			fscanf(file, "%s", students[k].firstName);
			fscanf(file, "%s", students[k].lastName);
			fscanf(file, "%s", students[k].patronyminc);
			fscanf(file, "%s", students[k].country);
			fscanf(file, "%s", students[k].disctrict);
			fscanf(file, "%s", students[k].city);
			fscanf(file, "%s", students[k].phoneNumber);
			fscanf(file, "%s", temp[0]);
			fscanf(file, "%s", temp[1]);
			fscanf(file, "%s", temp[2]);
			fscanf(file, "%s", temp[3]);
			fscanf(file, "%s", temp[4]);
			students[k].isLiveInHostel = atoll(temp[0]);
			students[k].isGetAScholarship = atoll(temp[1]);
			students[k].markZNO[0] = atof(temp[2]);
			students[k].markZNO[1] = atof(temp[3]);
			students[k].markZNO[2] = atof(temp[4]);
			k++;
			if (feof(file))
				break;
		}
	}
	fclose(file);

	return isSuccesful;
}

bool WriteStudents(struct Student * students, int sizeStudents, FILE * file)
{
	bool isSuccesful = false;

	if (file != NULL)
	{
		for (int k = 0; k < sizeStudents; k++)
		{
			fprintf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%i\n%i\n%f\n%f\n%f\n", students[k].firstName, students[k].lastName,
				students[k].patronyminc, students[k].country, students[k].disctrict, students[k].city,
				students[k].phoneNumber, students[k].isLiveInHostel, students[k].isGetAScholarship,
				students[k].markZNO[0], students[k].markZNO[1], students[k].markZNO[2]);
		}
		fclose(file);
		isSuccesful = true;
	}

	return isSuccesful;
}

void SortStudent(struct Student * students, int sortBy, int sizeStudents)
{
	struct Student temp;
	switch (sortBy)
	{
	case 1:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].firstName, students[j].firstName))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 2:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].lastName, students[j].lastName))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 3:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].patronyminc, students[j].patronyminc))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 4:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].country, students[j].country))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 5:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].disctrict, students[j].disctrict))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 6:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].city, students[j].city))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 7:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].phoneNumber, students[j].phoneNumber))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 8:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoIntElemnets(students[i].isLiveInHostel, students[j].isLiveInHostel))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 9:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoFloatElements(students[i].markZNO[0], students[j].markZNO[0]))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	default:
		break;
	}
}

/*!
�������, ��� �������, �� ������� ����������� char �������
\param struct Student * student - �������� �� ��������� "�������"
\param char * txt1 - ����� ������
\param char * txt2 - ����� ������
@return �������, �� ������� ����������� �� ��� ��������
*/

bool SortTwoCharElements(char * txt1, char * txt2)
{
	int theSmallestSizeOfTxt;
	bool isNeedToSort = false;
	if (strlen(txt1) >= strlen(txt2))
	{
		theSmallestSizeOfTxt = strlen(txt2);
	}
	else
	{
		theSmallestSizeOfTxt = strlen(txt2);
	}
	for (int i = 0; i < theSmallestSizeOfTxt; i++)
	{
		if (txt1[i] < txt2[i])
		{
			break;
		}
		else if (txt1[i] > txt2[i])
		{
			isNeedToSort = true;
			break;
		}
	}
	return isNeedToSort;
}

/*!
�������, ��� �������, �� ������� ����������� int �������
\param struct Student * student - �������� �� ��������� "�������"
\param int num1 - ����� �������� int
\param int num2 - ����� �������� int
@return �������, �� ������� ����������� �� ��� ��������
*/

bool SortTwoIntElemnets(int num1, int num2)
{
	bool isNeedToSort = false;

	if (num1 < num2)
	{
		isNeedToSort = true;
	}

	return isNeedToSort;
}

/*!
�������, ��� �������, �� ������� ����������� float �������
\param struct Student * student - �������� �� ��������� "�������"
\param float num1 - ����� �������� float
\param float num2 - ����� �������� float
@return �������, �� ������� ����������� �� ��� ��������
*/

bool SortTwoFloatElements(float num1, float num2)
{
	bool isNeedToSort = false;

	if (num1 < num2)
	{
		isNeedToSort = true;
	}

	return isNeedToSort;
}