

int main()
{
	/*
	������ ���������
	����� ���������� ����� ����� ���� ����������
	*/
	int numeral1 = 3, numeral2 = 4, numeral3 = 5, result;
	if (numeral1 == numeral2 == numeral3)
	{
		result = numeral1;
	}
	else if (numeral1 <= numeral2)
	{
		if (numeral1 < numeral3)
		{
			result = numeral1;
		}
		else
		{
			result = numeral3;
		}
	}
	else
	{
		if (numeral2 <= numeral3)
		{
			result = numeral2;
		}
		else
		{
			result = numeral3;
		}
	}

	/*
	������ ���������
	��� ������� a, b �� f ��������� �������� c ����� �����: 
	c = a++ + ++b, ���� ��������� f = true;
	c = a-- - --b  , ���� ���������  f = false. 
	*/
	int a, b, c;
	bool f;
	a = 4; 
	b = 5;
	f = false;
	if (f = true)
	{
		c = a++ + ++b;
	}
	else
	{
		c = a-- - --b;
	}

	/*
	������ ���������
	���������, �� � ����� ���� �������� ������������� ����� ������� �����.
	*/
	int num = 445;
	bool noDifferenceResult;
	numeral3 = num % 10;
	numeral2 = (num / 10) % 10;
	numeral1 = num / 100;
	if (numeral1 == numeral2)
	{
		noDifferenceResult = true;
	}
	else if(numeral1 == numeral3)
	{
		noDifferenceResult = true;
	}
	else if (numeral2 == numeral3)
	{
		noDifferenceResult = true;
	}
	else
	{
		noDifferenceResult = false;
	}
	/*
	��������� ���������
	��������� ������� ����� � ��������� ��������� � ������������� ����
	*/
	num = 123;
	int temperyNumeral1, temperyNumeral2, temperyNumeral3, position;
	temperyNumeral1 = num % 10;
	temperyNumeral2 = (num / 10) % 10;
	temperyNumeral3 = num / 100;
	if (temperyNumeral1 == temperyNumeral2 == temperyNumeral3)
	{
		position = 0;
	}
	else if (temperyNumeral1 <= temperyNumeral2)
	{
		if (temperyNumeral1 < temperyNumeral3)
		{
			position = 1;
		}
		else
		{
			position = 3;
		}
	}
	
	else
	{
		if (temperyNumeral2 <= temperyNumeral3)
		{
			position = 2;
		}
		else
		{
			position = 3;
		}
	}
	/*
	����� ���������
	 �������� �� ����� ��������� ������ � ������ ���� (����� A, B, C, D, F). 
	 �� ������� ������� ��������� �� ��������� � ����������� ���� (�������).
	*/
	char mark = 'B';
	int numeralMark;
	switch (mark)
	{
		case 'A':
		{
			numeralMark = 5;
		}break;
		case 'B':
		{
			numeralMark = 4;
		}break;
		case 'C':
		{
			numeralMark = 3;
		}break;
		case 'D':
		{
			numeralMark = 2;
		}break;
		case 'F':
		{
			numeralMark = 1;
		}break;
		default:
			break;
	}
	return 0;
	/*
	������ ���������
	����� �������� ������� f �� �������
	*/
	//�������: f = ||x|-1|
	int pointX = -2, pointY;
	if (pointX < 0)
	{
		pointX = -pointX;
		if (pointX - 1 < 0)
		{
			pointY = -(pointX - 1);
		}
		else
		{
			pointY = pointX - 1;
		}
	}
	else
	{
		if (pointX - 1 < 0)
		{
			pointY = -(pointX - 1);
		}
		else
		{
			pointY = pointX - 1;
		}
	}
}