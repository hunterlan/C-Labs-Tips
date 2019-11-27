using namespace std;

int main()
{
	/*
	Первая программа
	Её задача вычеслить в трехзначном числе вторую цифру.
	*/
	int num = 456, numeral;
	num = num / 10; //делим так, чтобы осталось только два числа, ведь С всегда окгруляет в меньшую сторону
	numeral = num % 10; //получаем остаток от деления. При деление на 10 мы всегда получаем последнию цифру.

	/*
	Вторая программа
	Её задача 
	*/
	num = 123;
	int numeralFirst, numeralLast;
	float result;
	numeralLast = num % 10;
	numeralFirst = num / 100;
	result = numeralFirst / (float)numeralLast;

	/*
	Третья программа
	Вычесляем объем цилиндра
	*/

	const int PI = 3.1415;
	float height = 5, radius = 4;
	double amount;
	amount = PI * radius * radius * height;
	

	/*
	Четвертая программа
	Опрелеям площадь и периметр квадрата
	*/

	float sizeA = 2.2, perimetr, area;
	perimetr = sizeA * 2;
	area = sizeA * sizeA;

	/*
	Пятая программа
	Из радианы в градусы
	*/
	const int CONST_DEGREE = 180;
	float radian = 3.2, degree;
	degree = (3.2 * CONST_DEGREE) / PI;

	/*
	Шестая программа
	 Дано дійсне число а. Користуючись тільки операціями множення, отримати значення: 
	 а4 – за дві операції, а6 та а8 – за три операції, а10 – за чотири операції.
	*/
	int a = 2;
	//за две операции получаем а4
	a *= a * a;
	//за три операции получаем а6 и а8
	a = 2;
	int aCopy = a;
	a = a * a;
	a *= a * a; //а в 6 степени 
	a = a * (aCopy * aCopy);//а в 8 степени 
	//за четыре операции получаем а10
	a = 2;
	aCopy = a;
	a *= a * a;
	a *= a * a * aCopy;
	return 0;
}