int main()
{
	/**  * @file testLab04.cpp
	* Виконання задач з лабораторної работи
	* @author Шарикін Костянтин
	* @version 0.1 
	* @date 2018.09.18  
	*/


	/*
	* Первая программа
	* Для заданного непарного факториала найти удвоенный факториал
	*/

	/*@full
	* i - счетчик, numeral1 - какое-то число, result - удвоенный факториал
	*/
	int i = 1;
	int numeral1 = 7, result = 1;
	for (; i <= numeral1; i++)
	{
		if (i % 2 != 0)
		{
			result *= i;
		}
	}
	numeral1 = 7, result = 1, i = 1;
	do
	{
		if (i % 2 != 0)
		{
			result *= i;
		}
		i++;
	} while (i <= numeral1);
	numeral1 = 7, result = 1, i = 1;
	while (i <= numeral1)
	{
		if (i % 2 != 0)
		{
			result *= i;
		}
		i++;
	}

	/*
	Вторая программа
	Найти значение 10 * n!
	*/
	const int MULTIPLY_TO = 10;
	int numeral2 = 8, temp = 1, resultSecond;
	for (int i = 1; i <= numeral2; i++)
	{
		temp *= i;
	}
	resultSecond = MULTIPLY_TO * temp;

	/*
	Третья программа
	Выяснить в числе количество цифр и посчитать их сумму
	*/

	int num = 123456, countNum = 0, sumNum = 0;
	while (num != 0)
	{
		countNum++;
		sumNum += num % 10;
		num /= 10;
	}
	

	/*
	Четвертая программа
	Найти НОД для двух чисел
	*/
	int resultFour = 1;
	bool endCycle = false;
	numeral1 = 2, numeral2 = 3;
	while (endCycle == false)
	{
		if (resultFour % numeral1 == 0 && resultFour % numeral2 == 0)
		{
			endCycle = true;
		}
		else
		{
			resultFour++;
		}
	}
	
	/*
	Пятая программа
	Определить, простое ли число
	*/
	bool isNumberSimple;
	num = 439;
	for (int i = 1; i < num; i++)
	{
		if (num % i == 0)
		{
			isNumberSimple = false;
		}
		else
		{
			isNumberSimple = true;
		}
	}
	/*
	Шестая программа
	Определить, является ли билет с 6тизначным числом - "Щасливым"
	*/

	int ticket = 102300, sumFirstHalfTicket = 0, sumSecondHalfTicket = 0, countOps = 0;
	bool isTicketLucky;
	while (ticket != 0)
	{
		if (countOps < 3)
		{
			sumSecondHalfTicket += ticket % 10;
		}
		else
		{
			sumFirstHalfTicket += ticket % 10;
		}
		countOps++;
		ticket /= 10;
	}
	if (sumFirstHalfTicket == sumSecondHalfTicket)
	{
		isTicketLucky = true;
	}
	else
	{
		isTicketLucky = false;
	}

	/*
	Седьмая программа
	Определить количество 4ехзначных "щасливых" билетов
	*/

	
	int countLuckyTicket = 0;
	for (int i = 1000; i <= 9999; i++)
	{
		sumFirstHalfTicket = 0;
		sumSecondHalfTicket = 0;
		temp = i;
		countOps = 0;
		while (i != 0)
		{
			if (countOps < 2)
			{
				sumSecondHalfTicket += i % 10;
			}
			else
			{
				sumFirstHalfTicket += i % 10;
			}
			countOps++;
			i /= 10;
		}
		if (sumFirstHalfTicket == sumSecondHalfTicket)
		{
			countLuckyTicket++;
		}
		i = temp;
	}

	return 0;
}