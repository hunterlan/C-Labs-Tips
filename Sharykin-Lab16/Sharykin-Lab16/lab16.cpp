#include"Student.h"

int main()
{
	srand(time(0));
	int sizeOfStudents = 0;
	Student * students = (Student *)malloc(1 * sizeof(Student));
	clock_t startWorkProgramm, finishWorkProgramm;
	startWorkProgramm = clock();
	char * path = (char *)malloc(255 * sizeof(char));
	FILE * file;
	bool exit;
	do
	{
		exit = true;
		printf("Put the path: ");
		scanf("%s", path);
		file = fopen(path, "r+");
		if (!(ReadStudents(students, &sizeOfStudents, file)))
		{
			printf("Can't open the file.\n");
			exit = false;
		}
	} while (!exit);

	for (int i = 0; i < sizeOfStudents; i++)
	{
		printf("%s\n%s\n%s\n%s\n", students[i].firstName, students[i].lastName,
			students[i].patronyminc, students[i].group);
	}
	//FillStudents(students, &sizeOfStudents);

	do
	{
		exit = true;
		printf("Put the path: ");
		scanf("%s", path);
		file = fopen(path, "a+");
		if (!(WriteStudents(students, sizeOfStudents, file)))
		{
			printf("Can't write.\n");
			exit = false;
		}
	} while (!exit);

#if _DEBUG
	finishWorkProgramm = clock();
	float result = float(finishWorkProgramm - startWorkProgramm) / CLK_TCK;
	printf("Time of work programm: %f", result);
#endif
	return 0;
}
