#include"Structs.h"
#include<stdio.h>

void FillFromFileAStudent(Student * student, char * pathToFile);
void FillFromFileAWorker(Worker * worker, char * pathToFile);
void FillFromFileALaptop(Laptop * laptop, char * pathToFile);
void FillFromFileAProduct(Product * product, char * pathToFile);

int main()
{
	Student students[2];
	return 0;
}

void FillFromFileAStudent(Student * student, char * pathToFile)
{
	FILE * file;
	Student copiedStudent;
	file = fopen(pathToFile, "r");
	if (file == NULL)
	{

	}
	else
	{
		while (fscanf(file, "%s%s%s", student->firstName, student->lastName, student) != EOF) {
			i++;
		}

	}
}