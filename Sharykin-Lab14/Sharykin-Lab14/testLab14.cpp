#include"Student.h"

int main()
{
	ListOfStudents * list = NULL;
	
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

	free(list);
	return 0;
}