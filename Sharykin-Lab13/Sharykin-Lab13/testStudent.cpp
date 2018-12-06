#include"Student.h"
#include"testStudent.h"

/**
* @file testStudent.cpp
* Реалізація прототипів функції для тестування
* @author Шарикін Костянтин
* @version 1.0
* @date 2018.12.03
*/

void TestReadStudents(Student * students)
{
	struct Student testStudents;
	testStudents.isLiveInHostel = 1;
	testStudents.isGetAScholarship = 0;
	if (students[0].isLiveInHostel == testStudents.isLiveInHostel)
		printf("Live in hostel is OK.\n");
	else
		printf("Test failed. We excepted 1.");
	if(students[0].isGetAScholarship == testStudents.isGetAScholarship)
		printf("Get a scholar ship is OK.\n");
	else
		printf("Test failed. We excepted 0.");
}
