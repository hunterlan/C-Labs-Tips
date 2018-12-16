#include"testStudent.h"

int main()
{

	int sizeStudents = 0;
	Student * student = (Student *)malloc(1 * sizeof(Student));
	FILE * file = fopen("students.txt", "r+");
	ReadStudents(&student, &sizeStudents, file);
	TestReadStudent(student, sizeStudents);
	return 0;
}