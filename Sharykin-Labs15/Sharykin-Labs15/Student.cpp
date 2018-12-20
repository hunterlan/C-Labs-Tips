#include"Student.h"

struct ListOfStudents * Init(struct Student student)
{
	struct ListOfStudents * lst;
	// выделение памяти под корень списка
	lst = (struct ListOfStudents *)malloc(sizeof(struct ListOfStudents));
	lst->student = student;
	lst->next = NULL; // указатель на следующий узел
	lst->prev = NULL; // указатель на предыдущий узел
	return lst;
}
struct ListOfStudents * Swap(ListOfStudents * lst1, ListOfStudents * lst2, ListOfStudents * head)
{
	struct ListOfStudents *prev1, *prev2, *next1, *next2;
	prev1 = lst1->prev;  // узел предшествующий lst1
	prev2 = lst2->prev;  // узел предшествующий lst2
	next1 = lst1->next; // узел следующий за lst1
	next2 = lst2->next; // узел следующий за lst2
	if (lst2 == next1)  // обмениваются соседние узлы
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
	else if (lst1 == next2)  // обмениваются соседние узлы
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
	else  // обмениваются отстоящие узлы
	{
		if (lst1 != head)  // указатель prev можно установить только для элемента,
			prev1->next = lst2; // не являющегося корневым
		lst2->next = next1;
		if (lst2 != head)
			prev2->next = lst1;
		lst1->next = next2;
		lst2->prev = prev1;
		if (next2 != NULL) // указатель next можно установить только для элемента,
			next2->prev = lst1; // не являющегося последним
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
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->student = student; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->prev = temp;
	return(temp);
}
struct ListOfStudents * Del(ListOfStudents * lst)
{
	struct ListOfStudents *prev, *next;
	prev = lst->prev; // узел, предшествующий lst
	next = lst->next; // узел, следующий за lst
	if (prev != NULL)
		prev->next = lst->next; // переставляем указатель
	if (next != NULL)
		next->prev = lst->prev; // переставляем указатель
	free(lst); // освобождаем память удаляемого элемента
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
		p = p->next;  // переход к концу списка
	do {
		printf("Name: %s\nSername: %s\nPatronymic: %s\n Group: %s\n ", p->student.firstName,
			p->student.lastName, p->student.middleName, 
			p->student.group); // вывод значения элемента p
		p = p->prev; // переход к предыдущему узлу
	} while (p != NULL); // условие окончания обхода
}
