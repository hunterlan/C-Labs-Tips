#include"Student.h"

bool ReadStudents(struct Student ** students, int * sizeStudents, FILE * file)
{
#if _DEBUG
	time_t tTime = time(NULL);
	printf("The functions is %s\n", __FUNCTION__);
	printf("%s\n", ctime(&tTime));
#endif
	struct Student getStudent;
	bool isSuccesful = false;
	if (file != NULL)
	{
		isSuccesful = true;
		rewind(file);
		int k = 0;
		while (1)
		{
			*sizeStudents += 1;
			*students = (Student *)realloc(*students, *sizeStudents * sizeof(Student));
			fscanf(file, "%s", getStudent.firstName);
			fscanf(file, "%s", getStudent.lastName);
			fscanf(file, "%s", getStudent.patronyminc);
			fscanf(file, "%s", getStudent.group);
			*(*students+k) = getStudent;
			k++;
			if (feof(file))
				break;
		}
		fclose(file);
	}

	return isSuccesful;
}

void FillStudents(struct Student ** students, int * sizeStudents)
{
#if _DEBUG
	time_t tTime = time(NULL);
	printf("The functions is %s\n", __FUNCTION__);
	printf("%s\n", ctime(&tTime));
#endif
	Student student;
	printf("Put the first name of student: ");
	scanf("%s", student.firstName);
	printf("Put the last name of student: ");
	scanf("%s", student.lastName);
	printf("Put the middle name of student: ");
	scanf("%s", student.patronyminc);
	printf("Put the group of student: ");
	scanf("%s", student.group);
	*sizeStudents++;
	students = (Student *)realloc(students, *sizeStudents * sizeof(Student));
	students[*sizeStudents - 2] = student;
}

bool WriteStudents(struct Student * students, int sizeStudents, FILE * file)
{
#if _DEBUG
	time_t tTime = time(NULL);
	printf("The functions is %s\n", __FUNCTION__);
	printf("%s\n", ctime(&tTime));
#endif
	bool isSuccsful = false;
	if (file != NULL)
	{
		isSuccsful = true;
		for (int i = 0; i < sizeStudents; i++)
		{
			fprintf(file, "%s\n%s\n%s\n%s\n", students[i].firstName, students[i].lastName,
				students[i].patronyminc, students[i].group);
		}
	}
	fclose(file);

	return isSuccsful;
}