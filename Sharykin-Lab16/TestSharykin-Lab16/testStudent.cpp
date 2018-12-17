#include "testStudent.h"
void TestReadStudent(Student * students, int sizeStudent)
{
	clock_t startWorkProgramm, finishWorkProgramm;
	startWorkProgramm = clock();
	printf("The functions is %s\n", __FUNCTION__);
	Student student;
	strcpy(student.firstName, (char *)"Aleksandr");
	strcpy(student.lastName, (char *)"Kusch");
	strcpy(student.patronyminc, (char *)"Eduardovich");
	strcpy(student.group, "1.KIT102.8b");
	if (strcmp(student.firstName, students[0].firstName) == 0 &&
		strcmp(student.lastName, students[0].lastName) == 0 &&
		strcmp(student.lastName, students[0].lastName) == 0 && 
		strcmp(student.lastName, students[0].lastName) == 0)
		printf("Test is OK!\n");
	else
		printf("Failed!\n");
	finishWorkProgramm = clock();
	float result = float(finishWorkProgramm - startWorkProgramm) / (float)CLK_TCK;
	printf("Time of work programm: %f", result);
}