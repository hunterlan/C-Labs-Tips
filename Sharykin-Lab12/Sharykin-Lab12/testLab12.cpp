#define _CRT_SECURE_NO_WARNINGS
#include"Structs.h"

/**
* @mainpage
* <b> Лабораторна робота № 12. <br/>  Структуровані типи даних   </b>
* <br/><b><i>Мета роботи:</i></b>: придбати практичні навички щодо розроблення програм 
* із застосуванням масивів структур, сумішей і перерахувань.  <br/>
* <b>1 Завдання до роботи <br/> Основне завдання  <br/> </b>
* ? розробити функцію, яка читає дані (масив елементів) з файлу;<br/>
* ? розробити функцію, яка записує дані (масив елементів) у файл;<br/>
* ? розробити функцію, яка виводить масив елементів на екран;<br/>
* ? розробити функцію, яка буде сортирувати масив елементів за заданим критерієм (полем);<br/>
* ? розробити функцію, яка генерує елемент прикладної галузі згідно з індивідуальним завданням<br/>
* <b> Індивідуальне завдання: <br/> </b>
* Прикладна галузь «СТУДЕНТ». Сформувати масив даних про студентів, які не отримують стипендію. <br/>
* @author Шарикін Костянтин.
* @date 29-oct-2018
* @version 1.0  */

/**
* @file testLab12.cpp
* Головний файл
* @author Шарикін Костянтин
* @version 1.0
* @date 2018.11.25
*/

bool FillFromFileAStudent(Student * student, char * pathToFile);
void SortStudent(struct Student * students, int sortBy, int sizeStudents);
bool SortTwoCharElements(char * txt1, char * txt2);
bool SortTwoIntElemnets(int num1, int num2);
bool SortTwoFloatElements(float num1, float num2);
bool FillFromFileAWorker(Worker * worker, char * pathToFile);
bool FillFromFileALaptop(Laptop * laptop, char * pathToFile);
bool FillFromFileAProduct(Product * product, char * pathToFile);

/**
* Головна функція<br>
* Послідовність дій:
* <ul>
* <li>Створення змінних</li>
* <li>Просимо вказати путь до файлу у циклі. Якщо файлу не існує, тоді просимо ще раз написати путь.
* У іншому випадку, заповнюємо елемент масиву структури студентів. { @link FillFromFileAStudent } </li>
* <li>Потім, для індивідуального завдання, ми шукаємо кількість студентів, які не отримують студентів.</li>
* <li>Сортируємо результат.</li>
* <li>Виводимо на екран</li>
* </ul>
* Опис змінних: <br>
* int sizeStudent - розмір динамічного масиву структуру "студент"<br>
* int countStudentsNotGetMoney - кількість студентів, які не отримують стипендію<br>
* Students * students - масив структуру "студент"<br>
* Students * studentsNotGetMoney - масив структуру "студент", яка зберігає студентів, які не отримують стипендію<br>
* char * pathToFile - зберігає путь до файлу<br>
*/

int main()
{
	int sizeStudents = 0;
	printf("Write count of students: ");
	scanf("%d", &sizeStudents);
	struct Student * students = (Student *)malloc(sizeStudents * sizeof(Student));
	char pathToFile[255];
	for (int i = 0; i < sizeStudents; i++)
	{
		printf("\nWrite the path: ");
		scanf("%s", pathToFile);
		if (!FillFromFileAStudent(&students[i], pathToFile))
		{
			printf("\nFile is not found.");
			i--;
		}
	}
	int countStudentNotGetMoney = 0;
	for (int i = 0; i < sizeStudents; i++)
	{
		if (students[i].isGetAScholarship == 0)
		{
			countStudentNotGetMoney++;
		}
	}
	if (countStudentNotGetMoney == 0)
	{
		printf("Students, who don't get a scholar ship is not found.\n");
	}
	else
	{
		struct Student * studentsNotGetMoney = (Student *)malloc(countStudentNotGetMoney * sizeof(Student));
		for (int i = 0; i < countStudentNotGetMoney; i++)
		{
			printf("Student #%d", i + 1);
			printf("\n");
			if (students[i].isGetAScholarship == 0)
			{
				studentsNotGetMoney[i] = students[i];
				studentsNotGetMoney[i].ShowData();
			}
			printf("\n");
		}
		char userDecide;
		getchar();
		printf("Do you want to sort result?\n");
		scanf("%c", &userDecide);
		switch (userDecide)
		{
		case 'Y':
			case 'y':
			{
				int chooseSortBy = 0;
				bool end = false;
				do
				{
					getchar();
					printf("Please, choose from 1-9:\n");
					printf("1. Sort by first name\n");
					printf("2. Sort by last name\n");
					printf("3. Sort by patronymic\n");
					printf("4. Sort by country\n");
					printf("5. Sort by disctirct\n");
					printf("6. Sort by city\n");
					printf("7. Sort by phoneNumber\n");
					printf("8. Sort by living in hostel\n");
					printf("9. Sort by markZNO\n");
					scanf("%d", &chooseSortBy);
					if (chooseSortBy >= 1 && chooseSortBy < 10)
					{
						end = true;
					}
					else
					{
						printf("Wrong choose\n");
					}
				} while(end == false);
				SortStudent(studentsNotGetMoney, chooseSortBy, countStudentNotGetMoney);
				for (int i = 0; i < countStudentNotGetMoney; i++)
				{
					printf("Student #%d", i + 1);
					printf("\n");
					studentsNotGetMoney[i].ShowData();
					printf("\n");
				}
			}break;
		case 'N':
			case 'n':
			{
				printf("Thank you for using programming\n");
			}break;
		default:
			printf("That's wrong choose!");
			break;
		}
		free(studentsNotGetMoney);
	}

	
	free(students);

	/*
	int sizeWorkers = 0;
	printf("Write count of workers: ");
	scanf("%d", &sizeWorkers);
	struct Worker * workers = (Student *)malloc(sizeStudents * sizeof(Student));
	for (int i = 0; i < sizeStudents; i++)
	{
		printf("\nWrite the path: ");
		scanf("%s", pathToFile);
		if (!FillFromFileAWorker(&workers[i], pathToFile))
		{
			printf("\nFile is not found.");
			i--;
		}
	}
	for(int i = 0; i < sizeWorkers; i++)
	{
		workers[i]->ShowData();
	}
	*/
	printf("Press any key to exit...");
	getchar();
	getchar();
	return 0;
}


/*!
Функція, яка заповнює структуру студент.
\param struct Student * student - вказівник на структуру "Студент"
\param char * pathToFile - строка, яка вказує путь до файлу
@return чи успішно були зчитані дані з файлу. 
*/
bool FillFromFileAStudent(struct Student * student, char * pathToFile)
{
	bool isSuccesfull = true;
	char temp[5][10];
	FILE * file;
	file = fopen(pathToFile, "r");
	if (file == NULL)
	{
		isSuccesfull = false;
	}
	else
	{
		rewind(file);
		fscanf(file, "%s", student->firstName);
		fscanf(file, "%s", student->lastName);
		fscanf(file, "%s", student->patronyminc);
		fscanf(file, "%s", student->country);
		fscanf(file, "%s", student->disctrict);
		fscanf(file, "%s", student->city);
		fscanf(file, "%s", student->phoneNumber);
		fscanf(file, "%s", temp[0]);
		fscanf(file, "%s", temp[1]);
		fscanf(file, "%s", temp[2]);
		fscanf(file, "%s", temp[3]);
		fscanf(file, "%s", temp[4]);
		student->isLiveInHostel = atoll(temp[0]);
		student->isGetAScholarship = atoll(temp[1]);
		student->markZNO[0] = atof(temp[2]);
		student->markZNO[1] = atof(temp[3]);
		student->markZNO[2] = atof(temp[4]);
	}
	return isSuccesfull;
}

/*!
Функція, яка заповнює структуру робітник.
\param struct Student * student - вказівник на структуру "Студент"
\param char * pathToFile - строка, яка вказує путь до файлу
@return чи успішно були зчитані дані з файлу.
*/

bool FillFromFileAWorker(Worker * worker, char * pathToFile)
{
	bool isSuccesfull = true;
	FILE * file;
	file = fopen(pathToFile, "r");
	if (file == NULL)
	{
		isSuccesfull = false;
	}
	else
	{
		char temp[4][10];
		rewind(file);
		fscanf(file, "%s", worker->firstName);
		fscanf(file, "%s", worker->lastName);
		fscanf(file, "%s", worker->patronyminc);
		fscanf(file, "%s", temp[0][10]);
		fscanf(file, "%s", temp[1][10]);
		fscanf(file, "%s", temp[2][10]);
		fscanf(file, "%s", worker->position);
		fscanf(file, "%s", temp[3][10]);
		fscanf(file, "%s", temp[4][10]);
		worker->birthday[0] = atoll(temp[0]);
		worker->birthday[1] = atoll(temp[1]);
		worker->birthday[2] = atoll(temp[2]);
		worker->salary = atoll(temp[3]);
		worker->isWorkerTeacher = atoll(temp[4]);
	}
	return isSuccesfull;
}

/*!
Функція, яка заповнює структуру "ноутбук".
\param struct Student * student - вказівник на структуру "Студент"
\param char * pathToFile - строка, яка вказує путь до файлу
@return чи успішно були зчитані дані з файлу.
*/

bool FillFromFileALaptop(Laptop * laptop, char * pathToFile)
{
	bool isSuccesfull = true;
	FILE * file;
	file = fopen(pathToFile, "r");
	if (file == NULL)
	{
		isSuccesfull = false;
	}
	else
	{
		char temp[4][10];
		rewind(file);
		fscanf(file, "%s%s%s%s%s%s%s", temp[0], laptop->nameOfCompany, laptop->nameOfModel, temp[1],
			temp[2], temp[3], laptop->operationSystem);
		laptop->sizeOfScreen = atof(temp[0]);
		laptop->isHaveBluetooth = atoll(temp[1]);
		laptop->countKeyOnKeyboard = atoll(temp[2]);
		laptop->price = atoll(temp[3]);
	}

	return isSuccesfull;
}

/*!
Функція, яка заповнює структуру продукт.
\param struct Student * student - вказівник на структуру "Студент"
\param char * pathToFile - строка, яка вказує путь до файлу
@return чи успішно були зчитані дані з файлу.
*/

bool FillFromFileAProduct(Product * product, char * pathToFile)
{
	bool isSuccesfull = true;
	FILE * file;
	file = fopen(pathToFile, "r");
	if (file == NULL)
	{
		isSuccesfull = false;
	}
	else
	{
		char temp[2][10];
		rewind(file);
		fscanf(file, "%s%s%s%s", product->nameOfProduct, temp[0], temp[1], temp[2]);
		product->countOfProduct = atoll(temp[0]);
		product->priceToBuyProduct = atof(temp[1]);
		product->priceToSaleProduct = atof(temp[2]);
	}
	return isSuccesfull;
}

/*!
Функція, яка записує у файл структуру студент.
\param struct Student * student - вказівник на структуру "Студент"
\param char * pathToFile - строка, яка вказує путь до файлу
*/

void WriteStudent(struct Student * student, char * pathToFile)
{
	FILE *file = fopen(pathToFile, "w+");

	fprintf(file, "%s%s%s%s%s%s%s%i%i%f%f%f", student->firstName, student->lastName,
		student->patronyminc, student->country, student->disctrict, student->city,
		student->phoneNumber, student->isLiveInHostel, student->isGetAScholarship,
		student->markZNO[0], student->markZNO[1], student->markZNO[2]);
	fclose(file);
}

/*!
Функція, яка записує у файл структуру робітник.
\param struct Student * student - вказівник на структуру "Студент"
\param char * pathToFile - строка, яка вказує путь до файлу
*/

void WriteWorker(struct Worker * worker, char * pathToFile)
{
	FILE *file = fopen(pathToFile, "w+");

	fprintf(file, "%s%s%s%d%d%d%s%i%i", worker->firstName, worker->lastName, worker->patronyminc,
		worker->birthday[0], worker->birthday[1], worker->birthday[2], worker->position,
		worker->salary, worker->isWorkerTeacher);
	fclose(file);
}

/*!
Функція, яка записує у файл структуру ноутбук.
\param struct Student * student - вказівник на структуру "Студент"
\param char * pathToFile - строка, яка вказує путь до файлу
*/

void WriteLaptop(struct Laptop * laptop, char * pathToFile)
{
	FILE *file = fopen(pathToFile, "w+");

	fprintf(file, "%f%s%s%d%d%d%s", laptop->sizeOfScreen, laptop->nameOfCompany,
		laptop->nameOfModel, laptop->isHaveBluetooth, laptop->countKeyOnKeyboard,
		laptop->price, laptop->operationSystem);
	fclose(file);
}

/*!
Функція, яка записує у файл структуру продукт.
\param struct Student * student - вказівник на структуру "Студент"
\param char * pathToFile - строка, яка вказує путь до файлу
*/

void WriteProduct(struct Product * product, char * pathToFile)
{
	FILE *file = fopen(pathToFile, "w+");

	fprintf(file, "%s%d%f%f", product->nameOfProduct, product->countOfProduct,
		product->priceToBuyProduct, product->priceToSaleProduct);
	fclose(file);
}

/*!
Функція, яка сортирує студентів
\param struct Student * student - вказівник на структуру "Студент"
\param int sortBy - за яким полем будемо сортирувати
\param int sizeStudents - розмір масиву студент
*/

void SortStudent(struct Student * students, int sortBy, int sizeStudents)
{
	struct Student temp;
	switch (sortBy)
	{
	case 1:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].firstName, students[j].firstName))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 2:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].lastName, students[j].lastName))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 3:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].patronyminc, students[j].patronyminc))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 4:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].country, students[j].country))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 5:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].disctrict, students[j].disctrict))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 6:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].city, students[j].city))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 7:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoCharElements(students[i].phoneNumber, students[j].phoneNumber))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 8:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoIntElemnets(students[i].isLiveInHostel, students[j].isLiveInHostel))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	case 9:
	{
		for (int i = 0; i < sizeStudents - 1; i++)
		{
			for (int j = i + 1; j < sizeStudents; j++)
			{
				if (SortTwoFloatElements(students[i].markZNO[0], students[j].markZNO[0]))
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}break;
	default:
		break;
	}
}

/*!
Функція, яка визначає, чи потрібно сортирувати char елементі
\param struct Student * student - вказівник на структуру "Студент"
\param char * txt1 - перша строка
\param char * txt2 - друга строка
@return повертає, чи потрібно сортирувати ці два елемента
*/

bool SortTwoCharElements(char * txt1, char * txt2)
{
	int theSmallestSizeOfTxt;
	bool isNeedToSort = false;
	if (strlen(txt1) >= strlen(txt2))
	{
		theSmallestSizeOfTxt = strlen(txt2);
	}
	else
	{
		theSmallestSizeOfTxt = strlen(txt2);
	}
	for (int i = 0; i < theSmallestSizeOfTxt; i++)
	{
		if (txt1[i] < txt2[i])
		{
			break;
		}
		else if (txt1[i] > txt2[i])
		{
			isNeedToSort = true;
			break;
		}
	}
	return isNeedToSort;
}

/*!
Функція, яка визначає, чи потрібно сортирувати int елементі
\param struct Student * student - вказівник на структуру "Студент"
\param int num1 - перше значення int
\param int num2 - друге значення int 
@return повертає, чи потрібно сортирувати ці два елемента
*/

bool SortTwoIntElemnets(int num1, int num2)
{
	bool isNeedToSort = false;

	if (num1 < num2)
	{
		isNeedToSort = true;
	}

	return isNeedToSort;
}

/*!
Функція, яка визначає, чи потрібно сортирувати float елементі
\param struct Student * student - вказівник на структуру "Студент"
\param float num1 - перше значення float
\param float num2 - друге значення float
@return повертає, чи потрібно сортирувати ці два елемента
*/

bool SortTwoFloatElements(float num1, float num2)
{
	bool isNeedToSort = false;

	if (num1 < num2)
	{
		isNeedToSort = true;
	}

	return isNeedToSort;
}