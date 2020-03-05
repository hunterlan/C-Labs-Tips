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

bool ReadStudents(struct Student ** students, int * sizeStudents, FILE * file)
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
			*students = (Student *)realloc(*students, *sizeStudents * sizeof(Student));
			fscanf(file, "%s", getStudent.firstName);
			fscanf(file, "%s", getStudent.lastName);
			fscanf(file, "%s", getStudent.patronyminc);
			fscanf(file, "%s", getStudent.group);
			*(*students + k) = getStudent;
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
	bool isToSort, isNear = true, isHead = true;
	head = Copy(lst);
	tmp2 = Copy(lst);
	
	while ((tmp1 = tmp2->next) != NULL)
	{
		//isNear = true;
		while(tmp1 != NULL)
		{
			isToSort = false;
			if (chooseSort == 0)
			{
				if (strcmp(tmp1->student.firstName, tmp2->student.firstName) < 0)
					isToSort = true;
			}
			else if (chooseSort == 1)
			{
				if (strcmp(tmp1->student.lastName, tmp2->student.lastName) < 0)
					isToSort = true;
			}
			else if (chooseSort == 2)
			{
				if (strcmp(tmp1->student.patronyminc, tmp2->student.patronyminc) < 0)
					isToSort = true;
			}
			else
			{
				/*if (strcmp(tmp1->student.group > lst->student.group) < 0 )
					isToSort = true;*/
			}
			if (isToSort)
			{
				/*if (isHead)
				{
					if (isNear)
					{
						head = tmp1;
						lst->next = tmp1->next;
						head->next = lst;
						lst = head;
					}
					else
					{
						tmp2 = tmp1->next;
						tmp3 = lst->next;
						tmp1->next = tmp3;
						head = tmp1;
						tmp3->next = lst;
						lst->next = tmp2;
						lst = head;
					}
				}
				else
				{
					if (isNear)
					{
						tmp4 = tmp1;
						lst->next = tmp1->next;
						tmp4->next = lst;
						lst = tmp4;
					}
					else
					{
						tmp2 = tmp1->next;
						tmp3 = lst->next;
						tmp1->next = tmp3;
						tmp4 = tmp1;
						tmp3->next = lst;
						lst->next = tmp2;
						lst = tmp4;
					}
				}
			}
			tmp1 = tmp1->next;
			isNear = false;*/
				head = Swap(tmp1, tmp2, head);
			}
			tmp1 = tmp1->next;
		} 
		tmp2 = tmp2->next;
		//isHead = false;
	}
	lst = head;
	return lst;

	//ListOfStudents * resultLst = NULL;
	//bool isToSort;
	//while (lst->next != NULL)
	//{
	//	isToSort = false;
	//	ListOfStudents * node = lst;
	//	lst = lst->next;
	//	if (chooseSort == 0)
	//	{
	//		if (strcmp(node->student.firstName, lst->student.firstName) < 0)
	//			isToSort = true;
	//	}
	//	else if (chooseSort == 1)
	//	{
	//		if (strcmp(node->student.lastName, lst->student.lastName) < 0)
	//			isToSort = true;
	//	}
	//	else if (chooseSort == 2)
	//	{
	//		if (strcmp(node->student.patronyminc, lst->student.patronyminc) < 0)
	//			isToSort = true;
	//	}
	//	else
	//	{
	//		/*if (strcmp(tmp1->student.group > lst->student.group) < 0 )
	//			isToSort = true;*/
	//	}

	//	if (resultLst == NULL || isToSort)
	//	{
	//		node->next = resultLst;
	//		resultLst = node;
	//	}
	//	else
	//	{
	//		ListOfStudents * currentObj = resultLst;
	//		while (currentObj->next != NULL && !isToSort)
	//			currentObj = currentObj->next;

	//		node->next = currentObj->next;
	//		currentObj->next = node;
	//	}
	//}
	//return resultLst;
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

ListOfStudents * Swap(ListOfStudents * lst1, ListOfStudents * lst2, ListOfStudents * head)
{
	struct ListOfStudents *prev1, *prev2, *next1, *next2;
	prev1 = head;
	prev2 = head;
	if (prev1 == lst1)
		prev1 = NULL;
	else
		while (prev1->next != lst1) // поиск узла предшествующего lst1
			prev1 = prev1->next;
	if (prev2 == lst2)
		prev2 = NULL;
	else
		while (prev2->next != lst2) // поиск узла предшествующего lst2
			prev2 = prev2->next;
	next1 = lst1->next;  // узел следующий за lst1
	next2 = lst2->next;  // узел следующий за lst2
	if (lst2 == next1)
	{                       // обмениваются соседние узлы
		lst2->next = lst1;
		lst1->next = next2;
		if (lst1 != head)
			prev1->next = lst2;
	}
	else
		if (lst1 == next2)
		{
			// обмениваются соседние узлы
			lst1->next = lst2;
			lst2->next = next1;
			if (lst2 != head)
				prev2->next = lst2;
		}
		else
		{
			// обмениваются отстоящие узлы
			if (lst1 != head)
				prev1->next = lst2;
			lst2->next = next1;
			if (lst2 != head)
				prev2->next = lst1;
			lst1->next = next2;
		}
	if (lst1 == head)
		return(lst2);
	if (lst2 == head)
		return(lst1);
	return(head);
}

ListOfStudents * Copy(ListOfStudents * lst)
{
	if (lst == NULL)
		return NULL;
	ListOfStudents * result = (ListOfStudents *)malloc(sizeof(ListOfStudents));
	result->student = lst->student;
	result->next = Copy(lst->next);
	return result;
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