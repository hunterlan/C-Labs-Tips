#include"Student.h"

bool ReadStudents(struct Student * students, int * sizeStudents, FILE * file)
{
	bool isSuccesful = false;
	if (file != NULL)
	{
		rewind(file);
		int k = 0;
		while (1)
		{
			*sizeStudents += 1;
			students = (Student *)realloc(students, *sizeStudents * sizeof(Student));
			fscanf(file, "%s%s%s%s", students[k].firstName, students[k].lastName, 
				students[k].patronyminc, students[k].group);
			k++;
			if (feof(file))
				break;
		}
	}
	fclose(file);

	return isSuccesful;
}

void PushBackStudentToList(ListOfStudents ** lst, Student getStudent)
{
	ListOfStudents * last = GetLastElemInList(*lst);
	ListOfStudents * tmp = (ListOfStudents *)malloc(sizeof(ListOfStudents));
	tmp->student = getStudent;
	tmp->next = NULL;
	last->next = tmp;
}

void PushStudentToList(ListOfStudents ** lst, Student getStudent)
{
	ListOfStudents * tmp = (ListOfStudents *)malloc(sizeof(ListOfStudents));
	tmp->student = getStudent;
	tmp->next = *lst;
	*lst = tmp;
}

ListOfStudents * GetLastElemInList(ListOfStudents * lst)
{
	if (lst == NULL)
		return NULL;
	while (lst->next)
		lst->next;

	return lst;
}

void PopStudentFromList(ListOfStudents ** lst)
{

}

void ShowList(ListOfStudents * lst)
{
	ListOfStudents * tmp = lst;
	printf("List of students:\n");
	while (tmp)
	{
		printf("%s %s %s ", tmp->student.firstName, tmp->student.lastName, tmp->student.patronyminc);
		printf("%s\n", tmp->student.group);
		tmp = tmp->next;
	}
}