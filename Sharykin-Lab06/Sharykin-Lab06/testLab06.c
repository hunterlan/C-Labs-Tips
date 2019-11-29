#include <cstdarg>
/**  
* @file testLab06.cpp  
* Виконная лабораторної роботи
* @author Шарикін Костянтин
* @version 0.0.1
* @date 2018.09.23
*/ 

/**
* Перше завдання.
* Перевірка, чи відбувається переповнення сітки.
* Опис змінних:
* const int ONE_BYTE, TWO_BYTE, FOUR_BYTE, EIGHT_BYTE - константні значення, у яких зберігається 
максимальне значення.
* bool isOverflow - визначає, чи відбувається переповнення сітки.
* long long byte - результат додатка чисел.
* \param countByte - кількість байтів, яке визначає розмір сетки
* \param arrayNumbers[] - масив типу int
* \param ... - невідома кількість аргументів long long 
* @return бульове значення isOverflow
*/

bool CheckByteOverflow(int countByte, int countArgum, ...)
{
	const int ONE_BYTE = 128, TWO_BYTE = 32767, FOUR_BYTE = 2147483647, 
		EIGHT_BYTE = 9223372036854775807;
	bool isOverflow = false;
	va_list argum; 
	long long byte = 1;
	//long long byte = arrayNumbers[0]; 
	/*
	*Якщо число буде більше, ніж максимальне число у байтах, то тоді це переповненняя
	*/
	va_start(argum, countArgum);
	if (countByte == 1)
	{
		
		for(int i = 0; i < countArgum; i++)
		{
			byte *= va_arg(argum, long long);
			if (byte > ONE_BYTE)
			{
				isOverflow = true;
				break;
			}
		}
	}
	else if (countByte == 2)
	{
		for (int i = 0; i < countArgum; i++)
		{
			/*byte *= arrayNumbers[i];
			if (byte > TWO_BYTE)
			{
				isOverflow = true;
				break;
			}*/
			byte *= va_arg(argum, long long);
			if (byte > TWO_BYTE)
			{
				isOverflow = true;
				break;
			}
		}
	}
	else if (countByte == 4)
	{
		for (int i = 0; i < countArgum; i++)
		{
			/*byte *= arrayNumbers[i];
			if (byte > FOUR_BYTE)
			{
				isOverflow = true;
				break;
			}*/
			byte *= va_arg(argum, long long);
			if (byte > FOUR_BYTE)
			{
				isOverflow = true;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < countArgum; i++)
		{
			/*byte *= arrayNumbers[i];
			if (byte < 0)
			{
				isOverflow = true;
				break;
			}*/
			byte *= va_arg(argum, long long);
			if (byte <= 0)
			{
				isOverflow = true;
				break;
			}
		}
	}
	va_end(argum);
	return isOverflow;
}
/**
* Друге завдання.
* Визначаєм факторіал
* \param num - число, якого ми будемо визначати факторіал
* @return int factorial - факторіал числа
*/
int Factorial(int num)
{
	int factorial = 1;
	for (int i = 1; i <= num; i++)
	{
		factorial *= i;
	}
	return factorial;
}
/**
* Третє завдання.
* Підраховуваєм добуток проміжутка
* \param from - начальний діапозон
* \param to - кінечний діапозон
* @return int resultMultiply - результат добутку проміжутка
*/
int MultiplyFromTo(int from, int to)
{
	int resultMultiply = 1;
	for (int i = from; i <= to; i++)
	{
		resultMultiply *= i;
	}
	return resultMultiply;
}

/**
* Четверте завдання.
* Підвести число n у ступінь m. 
* \param num - число
* \param to - ступінь
* @return int resultPow - результат підведення числа у ступінь
*/

int ToPower(int num, int pow)
{
	int resultPow = 1;
	for (int i = 0; i < pow; i++)
	{
		resultPow *= num;
	}
	return resultPow;
}

/**
* П'яте завдання.
* Отримати заголовний еквівалент переданого символу, якщо символ – риса літери
* \param a - символ
* @return char convert - результат конвертації з маленької літери у велику
*/

bool FromSmallToBig(char a)
{
	const int DIFFERENCE = 32;
	char convert;
	convert = a - DIFFERENCE;
	return convert;
}

int main()
{

	bool result; 
	int countByte = 4; 
	int countArgum = 3;
	result = CheckByteOverflow(countByte, countArgum, (long long)34560, (long long)112300, (long long)32000);

	int resultFactorial, num = 3;
	resultFactorial = Factorial(num);

	int resultMultiply, firstNum = 50, lastNum = 52;
	resultMultiply = MultiplyFromTo(firstNum, lastNum);

	int resultPow, pow = 2;
	num = 4;
	resultPow = ToPower(num, pow);

	char resultConvert, a = 'a';
	resultConvert = FromSmallToBig(a);

	return 0;
}