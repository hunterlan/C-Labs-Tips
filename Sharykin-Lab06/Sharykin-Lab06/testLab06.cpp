#include <cstdarg>
/**  
* @file testLab06.cpp  
* �������� ����������� ������
* @author ������ ���������
* @version 0.0.1
* @date 2018.09.23
*/ 

/**
* ����� ��������.
* ��������, �� ���������� ������������ ����.
* ���� ������:
* const int ONE_BYTE, TWO_BYTE, FOUR_BYTE, EIGHT_BYTE - ��������� ��������, � ���� ���������� 
����������� ��������.
* bool isOverflow - �������, �� ���������� ������������ ����.
* long long byte - ��������� ������� �����.
* \param countByte - ������� �����, ��� ������� ����� �����
* \param arrayNumbers[] - ����� ���� int
* \param ... - ������� ������� ��������� long long 
* @return ������� �������� isOverflow
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
	*���� ����� ���� �����, �� ����������� ����� � ������, �� ��� �� �������������
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
* ����� ��������.
* �������� ��������
* \param num - �����, ����� �� ������ ��������� ��������
* @return int factorial - �������� �����
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
* ���� ��������.
* ϳ���������� ������� ���������
* \param from - ��������� �������
* \param to - ������� �������
* @return int resultMultiply - ��������� ������� ���������
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
* �������� ��������.
* ϳ������ ����� n � ������ m. 
* \param num - �����
* \param to - ������
* @return int resultPow - ��������� ��������� ����� � ������
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
* �'��� ��������.
* �������� ���������� ��������� ���������� �������, ���� ������ � ���� �����
* \param a - ������
* @return char convert - ��������� ����������� � �������� ����� � ������
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