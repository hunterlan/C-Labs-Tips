#include"Student.h"

ListOfStudents * PushAfterStudentToList(ListOfStudents * lst, Student getStudent, int pos)
{
	ListOfStudents * tmp, *p;
	tmp = (ListOfStudents *)malloc(sizeof(ListOfStudents));
	for (int i = 0; i < pos - 1; i++)
	{
		lst = lst->next;
	}
	p = lst->next;
	lst->next = tmp;
	tmp->student = getStudent;
	tmp->next = p;
	return lst;
}

bool ReadStudents(struct Student * students, int * sizeStudents, FILE * file)
{
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
 			students = (Student *)realloc(students, *sizeStudents * sizeof(Student));
			fscanf(file, "%s", getStudent.firstName);
			fscanf(file, "%s", getStudent.lastName);
			fscanf(file, "%s", getStudent.patronyminc);
			fscanf(file, "%s", getStudent.group);
			students[k] = getStudent;
			k++;
			if (feof(file))
				break;
		}
	}
	fclose(file);

	return isSuccesful;
}

ListOfStudents * SortWithPointer(ListOfStudents * lst, int chooseSort)
{
	ListOfStudents * tmp1, * tmp2, *head;
	bool isToSort;
	head = lst;
	
	while ((tmp1 = lst->next) != NULL)
	{
		while(tmp1 != NULL)
		{
			isToSort = false;
			if (chooseSort == 0)
			{
				if (tmp1->student.firstName < lst->student.firstName)
					isToSort = true;
			}
			else if (chooseSort == 1)
			{
				if (tmp1->student.lastName < lst->student.lastName)
					isToSort = true;
			}
			else if (chooseSort == 2)
			{
				if (tmp1->student.patronyminc < lst->student.patronyminc)
					isToSort = true;
			}
			else
			{
				if (tmp1->student.group < lst->student.group)
					isToSort = true;
			}
			if (isToSort)
			{
				tmp2 = lst->next;
				lst = tmp1->next;
				tmp1->next = tmp2;
				lst->next = tmp1;
			}
			tmp1 = tmp1->next;
		} 
		lst = lst->next;
	}
	lst = head;
	return lst;
}

void PushBackStudentToList(ListOfStudents ** lst, Student getStudent)
{
	ListOfStudents * tmp = (ListOfStudents *)malloc(sizeof(ListOfStudents));
	ListOfStudents * last = GetLastElemInList(*lst);
	if (last == NULL)
		PushStudentToList(lst, getStudent);
	else
	{
		tmp->student = getStudent;
		tmp->next = NULL;
		last->next = tmp;
		*lst = last;
	}
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
	ListOfStudents *pFwd = NULL;  //текущий узел
	ListOfStudents *pBwd = NULL;  //предыдущий узел
	//Получили NULL
	if (!lst) {
		exit(-1);
	}
	//Список пуст
	if (!(*lst)) {
		exit(-1);
	}

	pFwd = *lst;
	while (pFwd->next) {
		pBwd = pFwd;
		pFwd = pFwd->next;
	}

	if (pBwd == NULL) {
		free(*lst);
		*lst = NULL;
	}
	else {
		free(pFwd->next);
		pBwd->next = NULL;
	}
}

bool WriteStudents(ListOfStudents * lst, FILE * file)
{
	bool isSuccesful = false;
	if (file != NULL)
	{
		do
		{
			fprintf(file, "%s %s %s %s\n", lst->student.firstName, lst->student.lastName,
				lst->student.patronyminc, lst->student.group);
			//lst = lst->next;
		} while (lst = lst->next);
		isSuccesful = true;
	}
	fclose(file);

	return isSuccesful;
}

bool FindStudent(ListOfStudents * lst, Student findStudent)
{
	bool isFound = false;
	while (lst->next)
	{
		if (lst->student.firstName == findStudent.firstName &&
			lst->student.lastName == findStudent.lastName &&
			lst->student.patronyminc == findStudent.patronyminc &&
			lst->student.group == findStudent.group)
		{
			isFound = true;
			break;
		}
	}
	return isFound;
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