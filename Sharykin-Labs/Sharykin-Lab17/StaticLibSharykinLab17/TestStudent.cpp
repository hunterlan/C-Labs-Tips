#include"stdafx.h"
#include"TestStudent.h"

void TestReadStudents(Student * students)
{
	struct Student testStudents;
	testStudents.isLiveInHostel = 1;
	testStudents.isGetAScholarship = 0;
	if (students[0].isLiveInHostel == testStudents.isLiveInHostel)
		printf("Live in hostel is OK.\n");
	else
		printf("Test failed. We excepted 1.");
	if (students[0].isGetAScholarship == testStudents.isGetAScholarship)
		printf("Get a scholar ship is OK.\n");
	else
		printf("Test failed. We excepted 0.");
}