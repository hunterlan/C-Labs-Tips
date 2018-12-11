#include"Student.h"

const int COUNT_LIST_MENU = 8;

void ShowListMenu(int kX);
void ControlMenu();

int main()
{
	/*ListOfStudents * list = NULL;


	Student students[2];

	students[0].firstName = (char *)"Mark";
	students[0].lastName = (char *)"Bezpalyi";
	students[0].patronyminc = (char *)"Batkovich";
	students[0].group = (char *)"KIT102.8b";

	students[1].firstName = (char *)"Konstantin";
	students[1].lastName = (char *)"Bezpalyi";
	students[1].patronyminc = (char *)"Batkovich";
	students[1].group = (char *)"KIT102.8b";

	PushStudentToList(&list, students[0]);
	PushBackStudentToList(&list, students[1]);

	ShowList(list);

	free(list);*/
	ControlMenu();
	return 0;
}

void ShowListMenu(int kX)
{
	char listMenu[COUNT_LIST_MENU][32] = { {"Read students from file"}, {"Input student and push"},
	{"Input student and push it back"}, {"Delete last student"}, {"Write students to file"},
	{"Find student"}, {"Show list of students"}, {"Exit"} };
	for (int i = 0; i < COUNT_LIST_MENU; i++)
	{
		if (i == kX)
		{
			printf("%s", listMenu[i]);
			printf(" <=\n");
		}
		else
			printf("%s\n", listMenu[i]);
	}
}

void ControlMenu()
{
	ListOfStudents * list = NULL;
	int kX = 0, key;
	bool exit = false;
	ShowListMenu(kX);
	do
	{
		key = _getch();
		switch (key)
		{
			case 72: //up
			{
				if (kX == 0)
					kX = COUNT_LIST_MENU;
				else
					kX--;
			}break;
			case 80: //down
			{
				if (kX == COUNT_LIST_MENU)
					kX = 0;
				else
					kX++;
			}break;
			case 13:
			{
				if (kX == 0)
				{
					int sizeStudents = 0;
					Student * students = (Student *)malloc(1 * sizeof(Student));
					char * path = (char *)malloc(255 * sizeof(char));
					bool IsRead = true;
					do
					{
						printf("Put the path to file with students: ");
						scanf("%s", path);
						FILE * file = fopen(path, "r+");
						if (!ReadStudents(students, &sizeStudents, file))
						{
							printf("Can't open this file.\n");
							IsRead = false;
						}
					} while (!IsRead);
					for (int i = 0; i < sizeStudents; i++)
					{
						//printf("%s", students[i]);
						PushStudentToList(&list, students[i]);
					}
				}
				else if (kX == 1 || kX == 2 || kX == 5)
				{
					Student student;
					printf("Write the first name of student: ");
					scanf("%s", &student.firstName);
					printf("Write the last name of student: ");
					scanf("%s", &student.lastName);
					printf("Write the patronymic name of student: ");
					scanf("%s", &student.patronyminc);
					printf("Write the name group of student: ");
					scanf("%s", &student.group);
					if (kX == 1)
						PushStudentToList(&list, student);
					else if(kX == 2)
						PushBackStudentToList(&list, student);
					else
					{
						if (!FindStudent(list, student))
							printf("Student wasn't found");
						else
							printf("Student was found");
					}
				}
				else if (kX == 3)
					PopStudentFromList(&list);
				else if (kX == 4)
				{
					char * path = (char *)malloc(255 * sizeof(char));
					bool isWrite = true;
					do
					{
						printf("Put the path to file with students: ");
						scanf("%s", path);
						FILE * file = fopen(path, "a+");
						if (!WriteStudents(list, file))
						{
							isWrite = false;
							printf("Can't write");
						}
					} while (!isWrite);
				}
				else if (kX == 6)
				{
					ShowList(list);
					printf("\nPress any key to continue...");
					getchar();
				}
				else
					exit = true;
			}break;
			case 27:
			{
				exit = true;
			}break;
		}
		system("cls");
		ShowListMenu(kX);
	} while (exit == false);
	free(list);
}
