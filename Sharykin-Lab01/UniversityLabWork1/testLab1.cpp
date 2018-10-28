#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
/**
* Структура «Студент»
*/
struct Student
{
	char firstName[20]; ///< І’мя студента  
	char middleName[20]; ///< Прізвище студента  
	char lastName[20]; ///< По батькові студента  
	int *marks; ///< Оцінки студента 
};
/**
* Створення даних про студента.
*  * Функція генерує випадкові ПІБ на основі масивів символів для імен,
* по батькові, прізвищ;
* оцінки генеруються випадковим чином від 1 до 5, згенеровані дані
* заповнюють поля структури Student
* @return структура Student з заповненими полями
*/
struct Student generateStudent(int marksCount)
{
	int const NAMES_COUNT = 3; // Кількість імен/прізвищ/по батькові  
	char firstNames[NAMES_COUNT][20];  /* масив можливих імен */
	const char middleNames[NAMES_COUNT][20] = { "Valerievich", "Valerievich", "Valerievich", }; /* масив по батькові */
	char lastNames[NAMES_COUNT][20] = { "Sharykin",  "Sharykin",  "Sharykin" }; /* масив прізвищ */
	struct Student result;
	int i;
	strcpy_s(firstNames[0], "Konstantin");
	strcpy_s(firstNames[1], "Konstantin");
	strcpy_s(firstNames[2], "Konstantin");
	strcpy_s(result.firstName, firstNames[rand() % NAMES_COUNT]);
	strcpy_s(result.middleName, middleNames[rand() % NAMES_COUNT]);
	strcpy_s(result.lastName, lastNames[rand() % NAMES_COUNT]);
	result.marks = (int *)malloc(marksCount * 4);
	for (i = 0; i < marksCount; i++)
	{
		result.marks[i] = rand() % 5 + 1; // оцінки від 1 до 5  
	}
	return result;
}

void showStudents(struct Student students[], int studentsCount, int marksCount)
{
	int i, j;
	for (i = 0; i < studentsCount; i++)
	{
		printf("Output Student #%d information: \n", i);
		printf("%s %s %s: ", students[i].lastName, students[i].firstName, students[i].middleName);
		for (j = 0; j < marksCount; j++)
		{
			printf("%d ", students[i].marks[j]);
		}
		printf("\n");
	}
}

int main()
{
	const int STUDENTS_COUNT = 10; // Кількість студентів  
	const int STUDENT_MARKS_COUNT = 5; // Кількість оцінок у студента  
	struct Student students[10];
	int i;
	for (i = 0; i < STUDENTS_COUNT; i++)
	{
		students[i] = generateStudent(STUDENT_MARKS_COUNT);
	}
	showStudents(students, STUDENTS_COUNT, STUDENT_MARKS_COUNT);
	return 0;
}