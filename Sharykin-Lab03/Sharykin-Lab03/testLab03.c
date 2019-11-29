

int main()
{
	/*
	Первая программа
	Найти наименьшее число среди трех переменных
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
	Вторая программа
	При заданих a, b та f визначити значення c таким чином: 
	c = a++ + ++b, якщо прапорець f = true;
	c = a-- - --b  , якщо прапорець  f = false. 
	*/
	int a, b, c;
	int f = 0;
	a = 4; 
	b = 5;
	if (f == 1)
	{
		c = a++ + ++b;
	}
	else
	{
		c = a-- - --b;
	}

	/*
	Третья программа
	Визначити, чи є серед цифр заданого трьохзначного числа однакові цифри.
	*/
	int num = 445;
	int noDifferenceResult;
	numeral3 = num % 10;
	numeral2 = (num / 10) % 10;
	numeral1 = num / 100;
	if (numeral1 == numeral2)
	{
		noDifferenceResult = 1;
	}
	else if(numeral1 == numeral3)
	{
		noDifferenceResult = 1;
	}
	else if (numeral2 == numeral3)
	{
		noDifferenceResult = 1;
	}
	else
	{
		noDifferenceResult = 0;
	}
	/*
	Четвертая программа
	Визначити позицію цифри з мінімальним значенням у трьохзначному числі
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
	Пятая программа
	 Студенти на іспиті отримують оцінки в системі ЄКТС (літери A, B, C, D, F). 
	 За заданою оцінкою визначити її еквівалент у національній формі (цифровій).
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
	Шестая программа
	Найти значение функции f по графику
	*/
	//Формула: f = ||x|-1|
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