using namespace std;

int main()
{
	/*
	������ ���������
	Ÿ ������ ��������� � ����������� ����� ������ �����.
	*/
	int num = 456, numeral;
	num = num / 10; //����� ���, ����� �������� ������ ��� �����, ���� � ������ ��������� � ������� �������
	numeral = num % 10; //�������� ������� �� �������. ��� ������� �� 10 �� ������ �������� ��������� �����.

	/*
	������ ���������
	Ÿ ������ 
	*/
	num = 123;
	int numeralFirst, numeralLast;
	float result;
	numeralLast = num % 10;
	numeralFirst = num / 100;
	result = numeralFirst / (float)numeralLast;

	/*
	������ ���������
	��������� ����� ��������
	*/

	const int PI = 3.1415;
	float height = 5, radius = 4;
	double amount;
	amount = PI * radius * radius * height;
	

	/*
	��������� ���������
	�������� ������� � �������� ��������
	*/

	float sizeA = 2.2, perimetr, area;
	perimetr = sizeA * 2;
	area = sizeA * sizeA;

	/*
	����� ���������
	�� ������� � �������
	*/
	const int CONST_DEGREE = 180;
	float radian = 3.2, degree;
	degree = (3.2 * CONST_DEGREE) / PI;

	/*
	������ ���������
	 ���� ����� ����� �. ������������ ����� ���������� ��������, �������� ��������: 
	 �4 � �� �� ��������, �6 �� �8 � �� ��� ��������, �10 � �� ������ ��������.
	*/
	int a = 2;
	//�� ��� �������� �������� �4
	a *= a * a;
	//�� ��� �������� �������� �6 � �8
	a = 2;
	int aCopy = a;
	a = a * a;
	a *= a * a; //� � 6 ������� 
	a = a * (aCopy * aCopy);//� � 8 ������� 
	//�� ������ �������� �������� �10
	a = 2;
	aCopy = a;
	a *= a * a;
	a *= a * a * aCopy;
	return 0;
}