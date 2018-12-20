#include"Student.h"

struct ListOfStudents * Init(struct Student student)
{
	struct ListOfStudents * lst;
	// ��������� ������ ��� ������ ������
	lst = (struct ListOfStudents *)malloc(sizeof(struct ListOfStudents));
	lst->student = student;
	lst->next = NULL; // ��������� �� ��������� ����
	lst->prev = NULL; // ��������� �� ���������� ����
	return lst;
}
struct ListOfStudents * Swap(ListOfStudents * lst1, ListOfStudents * lst2, ListOfStudents * head)
{
	struct ListOfStudents *prev1, *prev2, *next1, *next2;
	prev1 = lst1->prev;  // ���� �������������� lst1
	prev2 = lst2->prev;  // ���� �������������� lst2
	next1 = lst1->next; // ���� ��������� �� lst1
	next2 = lst2->next; // ���� ��������� �� lst2
	if (lst2 == next1)  // ������������ �������� ����
	{
		lst2->next = lst1;
		lst2->prev = prev1;
		lst1->next = next2;
		lst1->prev = lst2;
		if (next2 != NULL)
			next2->prev = lst1;
		if (lst1 != head)
			prev1->next = lst2;
	}
	else if (lst1 == next2)  // ������������ �������� ����
	{
		lst1->next = lst2;
		lst1->prev = prev2;
		lst2->next = next1;
		lst2->prev = lst1;
		if (next1 != NULL)
			next1->prev = lst2;
		if (lst2 != head)
			prev2->next = lst1;
	}
	else  // ������������ ��������� ����
	{
		if (lst1 != head)  // ��������� prev ����� ���������� ������ ��� ��������,
			prev1->next = lst2; // �� ����������� ��������
		lst2->next = next1;
		if (lst2 != head)
			prev2->next = lst1;
		lst1->next = next2;
		lst2->prev = prev1;
		if (next2 != NULL) // ��������� next ����� ���������� ������ ��� ��������,
			next2->prev = lst1; // �� ����������� ���������
		lst1->prev = prev2;
		if (next1 != NULL)
			next1->prev = lst2;
	}
	if (lst1 == head)
		return(lst2);
	if (lst2 == head)
		return(lst1);
	return(head);
}
//struct ListOfStudent * Sort(ListOfStudent * lst)
//{
//
//}
struct ListOfStudents * Add(ListOfStudents * lst, struct Student student)
{
	struct ListOfStudents *temp, *p;
	temp = (struct ListOfStudents*)malloc(sizeof(ListOfStudents));
	p = lst->next; // ���������� ��������� �� ��������� ����
	lst->next = temp; // ���������� ���� ��������� �� �����������
	temp->student = student; // ���������� ���� ������ ������������ ����
	temp->next = p; // ��������� ���� ��������� �� ��������� ����
	temp->prev = lst; // ��������� ���� ��������� �� ���������� ����
	if (p != NULL)
		p->prev = temp;
	return(temp);
}
struct ListOfStudents * Del(ListOfStudents * lst)
{
	struct ListOfStudents *prev, *next;
	prev = lst->prev; // ����, �������������� lst
	next = lst->next; // ����, ��������� �� lst
	if (prev != NULL)
		prev->next = lst->next; // ������������ ���������
	if (next != NULL)
		next->prev = lst->prev; // ������������ ���������
	free(lst); // ����������� ������ ���������� ��������
	return(prev);
}
//struct ListOfStudent * Get(ListOfStudents * lst, struct Student student)
//{
//
//}
void ShowList(ListOfStudents * lst)
{
	struct ListOfStudents *p;
	p = lst;
	while (p->next != NULL)
		p = p->next;  // ������� � ����� ������
	do {
		printf("Name: %s\nSername: %s\nPatronymic: %s\n Group: %s\n ", p->student.firstName,
			p->student.lastName, p->student.middleName, 
			p->student.group); // ����� �������� �������� p
		p = p->prev; // ������� � ����������� ����
	} while (p != NULL); // ������� ��������� ������
}
