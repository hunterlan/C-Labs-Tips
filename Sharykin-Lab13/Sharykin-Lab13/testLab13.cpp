#include"Student.h"
int main()
{
	FILE * file = fopen("Students.txt", "a+");
	struct Student * students = (Student * )malloc(1 * sizeof(Student));
	int sizeStudents = 0;
	ReadStudents(students, &sizeStudents, file);
	for (int i = 0; i < sizeStudents; i++)
	{
		printf("Student #%d\n", i+1);
		students[i].ShowData();
	}
	SortStudent(students, 2, sizeStudents);
	for (int i = 0; i < sizeStudents; i++)
	{
		printf("Student #%d\n", i + 1);
		students[i].ShowData();
	}
	file = fopen("StudentsSorted.txt", "w+");
	WriteStudents(students, sizeStudents, file);
	return 0;
}