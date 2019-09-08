#include <iostream>
#include "University_Task_6.h"

//Дана строка, содержащая запись числа целого типа. Определить, симметрично ли оно, т.е. одинаковы ли цифры слева и справа (12321). Записать 3
	//последние цифры в одномерный массив.
void zadanie6_1(std::string str)
{
	int counterequals = 0;
	if (str.size() % 2 == 0)
	{
		int beforemiddle = str.size() / 2;//количество элементов первой половины
		int aftermiddle = str.size();
		for (int i = 0, j = aftermiddle - 1; i < beforemiddle; j > beforemiddle, i++, j--)
		{
			if ((int)str[i] == (int)str[j])
				counterequals++;
		}
		if (counterequals == (str.size() / 2))
		{
			std::cout << "Введенная строка является симметричной" << std::endl;
		}
		else
		{
			std::cout << "Введенная строка неявляется симметричной" << std::endl;

		}
	}
	else
	{
		int beforemiddle = str.size() / 2;
		int aftermiddle = str.size();
		for (int i = 0, j = aftermiddle - 1; i < beforemiddle; j > str.size() - beforemiddle, i++, j--)
		{
			if ((int)str[i] == (int)str[j])
				counterequals++;
		}
		if (counterequals == (str.size() / 2))
		{
			std::cout << "Введенная строка является симметричной" << std::endl;
		}
		else
		{
			std::cout << "Введенная строка неявляется симметричной" << std::endl;

		}
	}
}
