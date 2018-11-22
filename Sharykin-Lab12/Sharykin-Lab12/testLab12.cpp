#define _CRT_SECURE_NO_WARNINGS
#include"Structs.h"

bool FillFromFileAStudent(Student * student, char * pathToFile);
void SortStudent(struct Student * students, int sortBy, int sizeStudents);
bool SortTwoCharElements(char * txt1, char * txt2);
bool SortTwoIntElemnets(int num1, int num2);
bool SortTwoFloatElements(float num1, float num2);
bool FillFromFileAWorker(Worker * worker, char * pathToFile);
bool FillFromFileALaptop(Laptop * laptop, char * pathToFile);
bool FillFromFileAProduct(Product * product, char * pathToFile);

int main()
{
	int sizeStudents = 0;
	printf("Write count of students: ");
	scanf("%d", &sizeStudents);
	struct Student * students = (Student *)malloc(sizeStudents * sizeof(Student));
	char pathToFile[255];
	for (int i = 0; i < sizeStudents; i++)
	{
		printf("\nWrite the path: ");
		scanf("%s", pathToFile);
		if (!FillFromFileAStudent(&students[i], pathToFile))
		{
			printf("\nFile is not found.");
			i--;
		}
	}
	int countStudentNotGetMoney = 0;
	for (int i = 0; i < sizeStudents; i++)
	{
		if (students[i].isGetAScholarship == 0)
		{
			countStudentNotGetMoney++;
		}
	}
	if (countStudentNotGetMoney == 0)
	{
		printf("Students, who don't get a scholar ship is not found.\n");
	}
	else
	{
		struct Student * studentsNotGetMoney = (Student *)malloc(countStudentNotGetMoney * sizeof(Student));
		for (int i = 0; i < countStudentNotGetMoney; i++)
		{
			printf("Student #%d", i + 1);
			printf("\n");
			if (students[i].isGetAScholarship == 0)
			{
				studentsNotGetMoney[i] = students[i];
				studentsNotGetMoney[i].ShowData();
			}
			printf("\n");
		}
		char userDecide;
		getchar();
		printf("Do you want to sort result?\n");
		scanf("%c", &userDecide);
		switch (userDecide)
		{
		case 'Y':
			case 'y':
			{
				int chooseSortBy = 0;
				bool end = false;
				do
				{
					getchar();
					printf("Please, choose from 1-9:\n");
					printf("1. Sort by first name\n");
					printf("2. Sort by last name\n");
					printf("3. Sort by patronymic\n");
					printf("4. Sort by country\n");
					printf("5. Sort by disctirct\n");
					printf("6. Sort by city\n");
					printf("7. Sort by phoneNumber\n");
					printf("8. Sort by living in hostel\n");
					printf("9. Sort by markZNO\n");
					scanf("%d", &chooseSortBy);
					if (chooseSortBy >= 1 && chooseSortBy < 10)
					{
						end = true;
					}
					else
					{
						printf("Wrong choose\n");
					}
				} while(end == false);
				SortStudent(studentsNotGetMoney, chooseSortBy, countStudentNotGetMoney);
				for (int i = 0; i < countStudentNotGetMoney; i++)
				{
					printf("Student #%d", i + 1);
					printf("\n");
					studentsNotGetMoney[i].ShowData();
					printf("\n");
				}
			}break;
		case 'N':
			case 'n':
			{
				printf("Thank you for using programming\n");
			}break;
		default:
			printf("That's wrong choose!");
			break;
		}
		free(studentsNotGetMoney);
	}

	
	free(students);

	/*
	int sizeWorkers = 0;
	printf("Write count of workers: ");
	scanf("%d", &sizeWorkers);
	struct Worker * workers = (Student *)malloc(sizeStudents * sizeof(Student));
	for (int i = 0; i < sizeStudents; i++)
	{
		printf("\nWrite the path: ");
		scanf("%s", pathToFile);
		if (!FillFromFileAWorker(&workers[i], pathToFile))
		{
			printf("\nFile is not found.");
			i--;
		}
	}
	for(int i = 0; i < sizeWorkers; i++)
	{
		workers[i]->ShowData();
	}
	*/
	printf("Press any key to exit...");
	getchar();
	getchar();
	return 0;
}

bool FillFromFileAStudent(struct Student * student, char * pathToFile)
{
	bool isSuccesfull = true;
	char temp[5][10];
	FILE * file;
	file = fopen(pathToFile, "r");
	if (file == NULL)
	{
		isSuccesfull = false;
	}
	else
	{
		rewind(file);
		fscanf(file, "%s", student->firstName);
		fscanf(file, "%s", student->lastName);
		fscanf(file, "%s", student->patronyminc);
		fscanf(file, "%s", student->country);
		fscanf(file, "%s", student->disctrict);
		fscanf(file, "%s", student->city);
		fscanf(file, "%s", student->phoneNumber);
		fscanf(file, "%s", temp[0]);
		fscanf(file, "%s", temp[1]);
		fscanf(file, "%s", temp[2]);
		fscanf(file, "%s", temp[3]);
		fscanf(file, "%s", temp[4]);
		student->isLiveInHostel = atoll(temp[0]);
		student->isGetAScholarship = atoll(temp[1]);
		student->markZNO[0] = atof(temp[2]);
		student->markZNO[1] = atof(temp[3]);
		student->markZNO[2] = atof(temp[4]);
	}
	return isSuccesfull;
}

bool FillFromFileAWorker(Worker * worker, char * pathToFile)
{
	bool isSuccesfull = true;
	FILE * file;
	file = fopen(pathToFile, "r");
	if (file == NULL)
	{
		isSuccesfull = false;
	}
	else
	{
		char temp[4][10];
		rewind(file);
		fscanf(file, "%s", worker->firstName);
		fscanf(file, "%s", worker->lastName);
		fscanf(file, "%s", worker->patronyminc);
		fscanf(file, "%s", temp[0][10]);
		fscanf(file, "%s", temp[1][10]);
		fscanf(file, "%s", temp[2][10]);
		fscanf(file, "%s", worker->position);
		fscanf(file, "%s", temp[3][10]);
		fscanf(file, "%s", temp[4][10]);
		worker->birthday[0] = atoll(temp[0]);
		worker->birthday[1] = atoll(temp[1]);
		worker->birthday[2] = atoll(temp[2]);
		worker->salary = atoll(temp[3]);
		worker->isWorkerTeacher = atoll(temp[4]);
	}

}

bool FillFromFileALaptop(Laptop * laptop, char * pathToFile)
{
	bool isSuccesfull = true;
	FILE * file;
	file = fopen(pathToFile, "r");
	if (file == NULL)
	{
		isSuccesfull = false;
	}
	else
	{
		char temp[4][10];
		rewind(file);
	}


}

bool FillFromFileAProduct(Product * product, char * pathToFile)
{
	bool isSuccesfull = true;
	FILE * file;
	file = fopen(pathToFile, "r");
	if (file == NULL)
	{
		isSuccesfull = false;
	}
	else
	{
		char temp[4][10];
		rewind(file);
	}
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
	case 10:
	{

	}break;
	case 11:
	{

	}break;
	default:
		break;
	}
}

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

bool SortTwoIntElemnets(int num1, int num2)
{
	bool isNeedToSort = false;

	if (num1 < num2)
	{
		isNeedToSort = true;
	}

	return isNeedToSort;
}

bool SortTwoFloatElements(float num1, float num2)
{
	bool isNeedToSort = false;

	if (num1 < num2)
	{
		isNeedToSort = true;
	}

	return isNeedToSort;
}